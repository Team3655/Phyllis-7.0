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

#include "CommandBase.h"

#include "Commands/Autonomous/AutoShoot.h"
#include "Commands/Autonomous/AutoCrossLine.h"
#include "Commands/Autonomous/AutoPegGear.h"
#include "Commands/Autonomous/AutoPickupAndPeg.h"
#include "Commands/Autonomous/AutoPickupGear.h"
#include "MotionControl.h"

class Robot: public frc::IterativeRobot
{
private:
	std::unique_ptr<frc::Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> autoModes;

	frc::LiveWindow* lw;

	std::list<Profile*> seq1;
	std::list<Profile*> seq2;
	std::list<Profile*> seq3;

public:
	void InitializeSubsystems(frc::Preferences* prefs)
	{
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

		// Add Variable delay
		autoModes.AddDefault("Cross Line", new AutoCrossLine(0));
		// Peg 1 to 1

		seq1.push_back(new Profile(REVERSE, MpPeg86Size, MpPeg86, false));
		seq1.push_back(new Profile(RIGHT, Mp45TurnSize, Mp45Turn, false));
		seq1.push_back(new Profile(REVERSE, Mp28p5Size, Mp28p5, false));
		autoModes.AddObject("Peg Pos 1", new AutoPegGear(&seq1, nullptr));
		// Peg 2 to 2
		seq2.push_back(new Profile(REVERSE, Mp115p5Size, Mp115p5, false));
		autoModes.AddObject("Peg Pos 2", new AutoPegGear(&seq2, nullptr));

		// Peg 3 to 3
		seq3.push_back(new Profile(REVERSE, Mp104p5Size, Mp104p5, false));
		seq3.push_back(new Profile(LEFT, Mp45TurnSize, Mp45Turn, false));
		seq3.push_back(new Profile(REVERSE, Mp35p125Size, Mp35p125, false));
		autoModes.AddObject("Peg Pos 3", new AutoPegGear(&seq3, nullptr));

		frc::SmartDashboard::PutData("Auto Modes", &autoModes);
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
