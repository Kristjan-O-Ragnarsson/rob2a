#pragma config(Sensor, in3,    lineFollowerRIGHT,   sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerCENTER,  sensorLineFollower)
#pragma config(Sensor, in1,    lineFollowerLEFT,    sensorLineFollower)
#pragma config(Sensor, dgtl1,  sonarSensor,         sensorSONAR_cm)
#pragma config(Sensor, in4,    lightSensor,         sensorReflection)
#pragma config(Sensor, dgtl8,   touchSensor,			sensorTouch)
#pragma config(Sensor, dgtl9,  rightEncoder,        sensorQuadEncoder)
#pragma config(Sensor, dgtl11,  leftEncoder,         sensorQuadEncoder)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393, openLoop, reversed)
#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)
#include "../verkefni3/tasks.c"
#include "../functions/driveRelatedFunctions.c";


task main()
{
	StartTask(StopIfNeed);
	StartTask(BAtteryDisplay);
	StartTask(Claw);
	StartTask(FollowLine);
	while(SensorValue(sonarSensor) > 30 || SensorValue(sonarSensor) == -1){
		if(SensorValue(lightSensor) < 300)
		{

		}
	}
	StopTask(FollowLine);
	motor[leftMotor]  = 0;
  motor[rightMotor] = 0;
  gyroTurn(90, false);
	while(true){}
	clawState = 1;
	wait10Msec(100);
	clawState = 0;
	wait10Msec(100);
	clawState = -1;
	wait10Msec(100);
	armState = 1;
	wait10Msec(150);
}
