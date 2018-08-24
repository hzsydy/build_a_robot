#pragma config(Sensor, in1,    leftIR,         sensorLineFollower)
#pragma config(Sensor, in2,    centerIR,       sensorLineFollower)
#pragma config(Sensor, in3,    rightIR,        sensorLineFollower)
#pragma config(Sensor, dgtl1,  sonar,          sensorSONAR_mm)
#pragma config(Motor,  port1,           leftServo,     tmotorVex393_HBridge, openLoop, driveLeft)
#pragma config(Motor,  port10,           rightServo,    tmotorVex393_MC29, openLoop, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// parameters as global variables
// calibration
int lowIR = 1000; //Arbitrary high number so the calibration will work
int highIR = 0;
int threshold = -1;

task main()
{
  for(int i=0; i< 50; i++) {
    if(SensorValue[leftIR] > highIR) {
      highIR = SensorValue[leftIR];
      } else if(SensorValue[leftIR] < lowIR) {
      lowIR = SensorValue[leftIR];
    }
    if(SensorValue[centerIR] > highIR) {
      highIR = SensorValue[centerIR];
      } else if(SensorValue[centerIR] < lowIR) {
      lowIR = SensorValue[centerIR];
    }
    if(SensorValue[rightIR] > highIR) {
      highIR = SensorValue[rightIR];
      } else if(SensorValue[rightIR] < lowIR) {
      lowIR = SensorValue[rightIR];
    }
    //StartTask(follow_line);
    writeDebugStreamLine("left %ld mid %ld right %ld; low %ld high %ld",
			SensorValue[leftIR],
			SensorValue[centerIR],
			SensorValue[rightIR],
			lowIR,
			highIR
		);
    delay(20);
  }

  //Set threshold as the average of light and dark.
  threshold = (lowIR + highIR) / 2;

  // Light following loop
  while (true)
	{

  	// white = 0, black = 1
	  int flag_left = 0;
	  int flag_center = 0;
	  int flag_right = 0;
	  if(SensorValue(leftIR) > threshold)
	    {
	      flag_left = 1;
	    }
	  if(SensorValue(centerIR) > threshold)
	    {
	      flag_center = 1;
	    }
	  if(SensorValue(rightIR) > threshold)
	    {
	      flag_right = 1;
	    }

	  if (!flag_left)
	    {
	      // turn left:
			  motor[leftServo]  = -30;
			  motor[rightServo]  = 30;
			  delay(30);
	      motor[leftServo]  = 40;
	      motor[rightServo] = 40;
    		delay(100);
	    }
	  else if (!flag_right)
	    {
	      // turn right:
	    	motor[leftServo]  = -30;
			  motor[rightServo]  = 30;
			  delay(30);
	      motor[leftServo]  = -40;
	      motor[rightServo] = -40;
    		delay(100);
	    }
	   else {

	  motor[leftServo]  = -60;
	  motor[rightServo]  = 60;
	   }
	  writeDebugStreamLine("flag_left %d flag_center %d flag_right %d",
			flag_left,
			flag_center,
			flag_right
		);
    delay(20);

	}

}
