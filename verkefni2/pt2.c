#pragma config(Sensor, dgtl9,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl11,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop, reversed)
#include "../functions/driveRelatedFunctions.c";

/*----------------------------------------------------------------------------------------------------*\
|*                              - Forward for Distance with Encoders -                                *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs the robot to move forward for 5 rotations of the left shaft encoder.       *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|

\*----------------------------------------------------------------------------------------------------*/
const int ENERTIA = 70;
int stopTime = 250;
int power;


void drive(float dist, int counter, bool forward){
	int encoderTicks = driveDist(dist);
	int encoderStopValue = encoderTicks * counter;
	SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder] = 0;
	if (forward){
		power = 63;
	}
	else{
		power = -63;
	}
	while(abs(SensorValue[rightEncoder]) <encoderStopValue-ENERTIA)
  {
    motor[rightMotor] = power;
    motor[leftMotor] = power;
  }
   motor[rightMotor] = 0;
   motor[leftMotor] = 0;
}

void driveStop(int stopTime){
	motor[rightMotor] = 0;
	motor[leftMotor]  = 0;
	wait1Msec(stopTime);
}

//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
  wait1Msec(2000);
  for (int i = 1; i <= 5; i++){
		drive(50.0, i, true);
		driveStop(stopTime);
		drive(50.0, i, false);
		driveStop(stopTime);

	}
}




//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
