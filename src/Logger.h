///////////////////////////////////////////////////////////////////////////////
//
// Logger.h
//
//  Created on: Mar 27, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef LOGGER_H
#define LOGGER_H

#include <thread>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <memory>
#include <ctime>
#include <Commands/Subsystem.h>

// Sumary:
//	-Log to files
// 	-View live file feed
//	-Accept Subsystems
class Logger
{
public:
	enum LogLevel
	{
		kEnter,
		kExit,
		kInfo,
		kWarning,
		kError
	};

private:
	static std::shared_ptr<Logger> m_logger;

	std::map<std::string, std::shared_ptr<std::ofstream>> m_logs;
	typedef std::map<std::string, std::shared_ptr<std::ofstream>>::iterator LogItr;

	std::string m_logPath;

	bool m_streamLog;
	std::string m_streamId;

	std::time_t m_time = std::time(NULL);
	struct tm* m_now;

	std::mutex m_lock;

	bool log_exists(const std::string& id);

	void lock();
	void unlock();

	std::string level_to_string(LogLevel logLevel);

public:
	Logger(const char* path);

	static void Initialize(const char* path);

	// Gets instance of the logger
	// This will return nullptr if not initialized
	static Logger* GetInstance();

	// Creates/Appends a log file
	bool AddLog(const std::string& id);
	bool AddLog(frc::Subsystem* subsystem, const std::string& alias = "");
	// Stops write to log file
	bool StopLog(const std::string& id);
	bool StopLog(frc::Subsystem* subsystem);

	// Streams log entries to the console
	bool StreamLog(const std::string& id);
	bool StreamLog(frc::Subsystem* subsystem);
	// Stops streaming to console
	void StopStreamLog();

	// Add entry to log
	bool Log(frc::Subsystem* subsystem, LogLevel logLevel, const std::string& message = "");
	bool Log(const std::string& id, LogLevel logLevel, const std::string& message = "");
};

#endif // LOGGER_H
