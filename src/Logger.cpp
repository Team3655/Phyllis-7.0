///////////////////////////////////////////////////////////////////////////////
//
// Logger.cpp
//
//  Created on: Mar 27, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include <Logger.h>

std::shared_ptr<Logger> Logger::m_logger;

Logger::Logger(const char* path)
{
	m_logPath = path;
}

Logger::~Logger()
{
	for (LogItr it = m_logs.begin(); it != m_logs.end(); it++)
	{
		it->second.get()->close();
	}
}

bool Logger::log_exists(const std::string& id)
{
	return m_logs.find(id) != m_logs.end();
}

void Logger::lock()
{
	m_lock.lock();
}

void Logger::unlock()
{
	m_lock.unlock();
}

std::string Logger::level_to_string(LogLevel logLevel)
{
	switch (logLevel)
	{
	case kEnter:
		return "Enter";
		break;
	case kExit:
		return "Exit";
		break;
	case kInfo:
		return "Info";
		break;
	case kWarning:
		return "Warning";
		break;
	case kError:
		return "Error";
		break;
	default:
		return "";
		break;
	}
}

void Logger::Initialize(const char* path)
{
	m_logger = std::make_shared<Logger>(path);
}

Logger* Logger::GetInstance()
{
	return m_logger.get();
}

bool Logger::AddLog(const std::string& id)
{
	lock();
	if (log_exists(id))
	{
		unlock();
		return true;
	}

	m_logs[id] = std::make_shared<std::ofstream>(m_logPath + id + ".txt"); // TODO: Add timestamp to filename
	if (!m_logs[id]->is_open())
	{
		unlock();
		return false;
	}
	unlock();
	return true;
}

bool Logger::AddLog(frc::Subsystem* subsystem, const std::string& alias)
{
	if (alias.empty())
		return AddLog(subsystem->GetName());
	return AddLog(alias);
}

bool Logger::StopLog(const std::string& id)
{
	lock();
	if (!log_exists(id))
	{
		unlock();
		return false;
	}

	m_logs[id]->close();
	m_logs.erase(m_logs.find(id));
	unlock();
	return true;
}

bool Logger::StopLog(frc::Subsystem* subsystem)
{
	if (subsystem != nullptr)
		return StopLog(subsystem->GetName());
	return false;
}

bool Logger::StreamLog(const std::string& id)
{
	lock();
	if (!log_exists(id))
	{
		unlock();
		return false;
	}
	m_streamLog = true;
	m_streamId = id;
	unlock();

	Log(id, kInfo, "Log stream started in " + id);

	return true;
}

bool Logger::StreamLog(frc::Subsystem* subsystem)
{
	if (subsystem != nullptr)
		return StreamLog(subsystem->GetName());
	return false;
}

void Logger::StopStreamLog()
{
	Log(m_streamId, kInfo, "Log stream ended in " + m_streamId);
	lock();
	m_streamLog = false;
	m_streamId.clear();
	unlock();
}

bool Logger::Log(const std::string& id, LogLevel logLevel, const std::string& message)
{
	std::string msg;

	lock();
	m_now = std::localtime(&m_time);
	msg = "[" + std::to_string(m_now->tm_hour)
		+ ":" + std::to_string(m_now->tm_min)
		+ ":" + std::to_string(m_now->tm_sec) + "]"; // TODO: Add milliseconds

	if (logLevel == kEnter || logLevel == kExit)
	{
		msg += "=====" + level_to_string(logLevel) + "ing " + "[" + id + "]: " + message + "====================";
	}
	else
	{
		msg += "[" + level_to_string(logLevel) + "]";
		msg += " " + id + ": ";
		msg += message;
	}

	if (!log_exists(id) || !m_logs[id]->is_open())
	{
		unlock();
		return false;
	}
	*m_logs[id].get() << msg << std::endl;

	if (m_streamLog && id == m_streamId)
	{
		std::cout << msg << std::endl;
	}
	unlock();
	return true;
}

bool Logger::Log(frc::Subsystem* subsystem, LogLevel logLevel, const std::string& message)
{
	if (subsystem != nullptr)
		return Log(subsystem->GetName(), logLevel, message);
	return false;
}
