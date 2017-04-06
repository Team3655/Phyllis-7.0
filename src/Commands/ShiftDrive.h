#ifndef SHIFT_DRIVE_H
#define SHIFT_DRIVE_H

#include <Commands/CommandGroup.h>

// Summary:
// Group to shift gears and wait for gear to catch
// before allowing the driver to control the bot
class ShiftDrive : public frc::CommandGroup
{
public:
	ShiftDrive();
};

#endif // SHIFT_DRIVE_H
