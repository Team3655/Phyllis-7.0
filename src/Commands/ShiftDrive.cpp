#include "ShiftDrive.h"
#include "DelayCoast.h"
#include "Shift.h"

ShiftDrive::ShiftDrive()
{
	AddSequential(new Shift());
	AddSequential(new DelayCoast(2));
}
