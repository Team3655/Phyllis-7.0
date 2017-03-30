#include "ShiftDrive.h"
#include "Delay.h"
#include "Shift.h"

ShiftDrive::ShiftDrive()
{
	AddSequential(new Shift());
	AddSequential(new Delay(.5));
}
