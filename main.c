// I know it is silly, but it seem that the compiler of ROBOTC does not know how to compile from multiple files.

#include "PWM.c"

task main()
{
	startTask(run_motor, 10);
	startTask(_test_motor, 50);
	while(true)
		;
}
