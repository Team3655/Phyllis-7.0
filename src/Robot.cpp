///////////////////////////////////////////////////////////////////////////////
//
// Robot.cpp
//
//  Created on: Jan 7, 2017
//      Author: Silas A.
//
///////////////////////////////////////////////////////////////////////////////

#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "RobotMap.h"
#include "CommandBase.h"
#include "Logger.h"

#include "Commands/Autonomous/AutoShoot.h"
#include "Commands/Autonomous/AutoCrossLine.h"
#include "Commands/Autonomous/AutoPegGear.h"
#include "Commands/Autonomous/AutoPegAndShoot.h"

#include "Commands/MagicDrive.h"

class Robot: public frc::IterativeRobot
{
private:
	std::unique_ptr<frc::Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> autoModes;

	frc::LiveWindow* lw;

	double autonDelay;

public:
	void InitializeSubsystems(frc::Preferences* prefs)
	{
		// Logger
		Logger::Initialize("/home/lvuser/Logs");
		Logger::GetInstance()->AddLog("cmds");

		CommandBase::drive.get()->Initialize(prefs);
		CommandBase::shooter.get()->Initialize(prefs);
		CommandBase::gearCollector.get()->Initialize(prefs);
		CommandBase::climber.get()->Initialize(prefs);
		CommandBase::fuelCollector.get()->Initialize(prefs);
		CommandBase::lights.get()->Initialize(prefs);
		CommandBase::visionManager.get()->Initialize(prefs);

		CommandBase::oi.get()->Initialize();
	}

	void UpdateDashboard(bool verbose = false)
	{
		CommandBase::drive.get()->DashboardOutput(verbose);
		CommandBase::shooter.get()->DashboardOutput(verbose);
		CommandBase::gearCollector.get()->DashboardOutput(verbose);
		CommandBase::climber.get()->DashboardOutput(verbose);
		CommandBase::fuelCollector.get()->DashboardOutput(verbose);
		CommandBase::lights.get()->DashboardOutput(verbose);
		CommandBase::visionManager.get()->DashboardOutput(verbose);
	}

	void RobotInit() override
	{
		InitializeSubsystems(CommandBase::oi.get()->GetPrefs());

		// Peg Blue 1
		autoModes.AddObject("Blue Peg 1",
				new AutoPegGear(0,
						std::vector<Profile>{ make_profile_inches(-76), make_profile_turn(45), make_profile_inches(-26) },
						std::vector<Profile>{ make_profile_inches(MAGIC_PEG_RETRY), make_profile_inches(-MAGIC_PEG_RETRY) },
						MAGIC_ZERO));
		// Peg Blue 2
		autoModes.AddObject("Blue Peg 2",
				new AutoPegGear(0,
						std::vector<Profile>{ make_profile_inches(-76, 200, 360) },
						std::vector<Profile>{ make_profile_inches(-MAGIC_PEG_RETRY), make_profile_inches(MAGIC_PEG_RETRY) },
						MAGIC_ZERO));
		// Peg Blue 3
		autoModes.AddObject("Blue Peg 3",
				new AutoPegGear(0,
						std::vector<Profile>{ make_profile_inches(88), make_profile_turn(-45), make_profile_inches(MAGIC_PEG_PLACE) },
						std::vector<Profile>{ make_profile_inches(-MAGIC_PEG_RETRY), make_profile_inches(MAGIC_PEG_RETRY) },
						MAGIC_ZERO));
		// Peg Red 1
		autoModes.AddObject("Red Peg 1",
				new AutoPegGear(0,
						std::vector<Profile>{ make_profile_inches(-120), make_profile_turn(45), make_profile_inches(-33.6) },
						std::vector<Profile>{ make_profile_inches(-MAGIC_PEG_RETRY), make_profile_inches(MAGIC_PEG_RETRY) },
						MAGIC_ZERO));
		// Peg Red 2
		autoModes.AddObject("Red Peg 2",
				new AutoPegGear(0,
						std::vector<Profile>{ make_profile_inches(-MAGIC_PEG_MID * 2) },
						std::vector<Profile>{ make_profile_inches(-MAGIC_PEG_RETRY), make_profile_inches(MAGIC_PEG_RETRY) },
						MAGIC_ZERO));
		// Peg Red 3
		autoModes.AddObject("Red Peg 3",
				new AutoPegGear(0,
						std::vector<Profile>{ make_profile_inches(90), make_profile_turn(-45), make_profile_inches(MAGIC_PEG_PLACE) },
						std::vector<Profile>{ make_profile_inches(-MAGIC_PEG_RETRY), make_profile_inches(MAGIC_PEG_RETRY) },
						MAGIC_ZERO));
		// Shoot Red 1
		autoModes.AddObject("Red Shoot 1",
				new AutoShoot(
						std::vector<Profile>{ make_profile_arc(50, -40, true), make_profile_arc(120, -60), make_profile_inches(300) }));
		// Shoot Blue 1
		autoModes.AddObject("Blue Shoot 1",
				new AutoShoot(
						std::vector<Profile>{ make_profile_arc(50, 40, true), make_profile_arc(120, 60), make_profile_inches(300) }));
		// Nothing
		autoModes.AddDefault("Nothing", nullptr);

		frc::SmartDashboard::Delete("Auto Modes"); // Attempt to fix no show chooser
		frc::SmartDashboard::PutData("Auto Modes", &autoModes);

		CommandBase::visionManager.get()->StartProc();
		CommandBase::lights.get()->SetPegCamLight(true);
	}

	void RobotPeriodic() override
	{
		UpdateDashboard();
	}

	/**
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */
	void DisabledInit() override
	{
	}

	void DisabledPeriodic() override
	{
		frc::Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to the
	 * chooser code above (like the commented example) or additional comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit() override
	{
		autonomousCommand.reset(autoModes.GetSelected());

		if (CommandBase::drive.get()->ShiftState() == HIGH)
			CommandBase::drive.get()->Shift();

		if (autonomousCommand.get() != nullptr)
		{
			autonomousCommand->Start();
		}
	}

	void AutonomousPeriodic() override
	{
		frc::Scheduler::GetInstance()->Run();
	}

	void TeleopInit() override
	{
		if (autonomousCommand != nullptr)
		{
			autonomousCommand->Cancel();
		}
	}

	void TeleopPeriodic() override
	{
		frc::Scheduler::GetInstance()->Run();
	}

	void TestPeriodic() override
	{
		frc::LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)
