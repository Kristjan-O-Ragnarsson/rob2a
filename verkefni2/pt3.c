#pragma config(Sensor, dgtl9,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl11,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop, reversed)
#pragma config(Sensor, dgtl8,   touchSensor,			sensorTouch)
#include "../functions/driveRelatedFunctions.c";
#include "../verkefni3/tasks.c"

/*----------------------------------------------------------------------------------------------------*\
|*                                 - ADVANCED Movement by Rotation -                                  *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program uses functions 'Turn(float, bool)' and 'drive(float, bool)' to very neatly and       *|
|*  modularly run your robot in a square. There is a two second pause at the beginning of the program.*|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
\*-----------------------------------------------------------------------------------------------4246-*/

const float TURNBASE = 3.335;
// Functions Prototypes
void Forward(float r);
//void TurnLeft(int deg);

// Declare Global Variables
const float rotations = 360.0;



//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++
task main()
{
	StartTask(StopIfNeed);
  wait1Msec(2000);
  drive(50.0, true);
  driveStop(stopTime);
  gyroTurn(90, true);
  drive(50.0, true);
  driveStop(stopTime);
  gyroTurn(90, false);
  drive(50.0, true);
  driveStop(stopTime);
  gyroTurn(90, false);
  drive(50.0, true);
  driveStop(stopTime);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*

//--------------------------------------------| FORWARD |---------------------------------------------
void Forward(float r)
{
  SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder]  = 0;

  // While the encoders have not yet met their goal: (r * rotations) ie (3.0 * 360.0) or "three rotations"
  while(SensorValue[rightEncoder] < (r * rotations) && SensorValue[leftEncoder] < (r * rotations))
  {
    motor[rightMotor] = 63;
    motor[leftMotor]  = 63;
  }
  motor[rightMotor] = 0;
  motor[leftMotor]  = 0;
}
//----------------------------------------------------------------------------------------------------

//-------------------------------------------| TURN LEFT |--------------------------------------------

void TurnLeft(int deg)
{
  SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder]  = 0;

  // While the encoders have not yet met their goal: (left is compared negativly since it will in reverse)
  while(SensorValue[rightEncoder] < (deg * TURNBASE) && SensorValue[leftEncoder] > (-1 * deg * TURNBASE))
  {
    motor[rightMotor] = 63;
    motor[leftMotor]  = -63;
  }
  motor[rightMotor] = 0;
  motor[leftMotor]  = 0;
}
*/
//----------------------------------------------------------------------------------------------------
