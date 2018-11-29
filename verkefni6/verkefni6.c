#pragma config(Sensor, dgtl1,  sonarSensor,         sensorSONAR_cm)
#pragma config(Sensor, in4,    lightSensor,         sensorReflection)
#pragma config(Sensor, dgtl8,   touchSensor,			sensorTouch)
#pragma config(Motor,  port2,           rightMotor,    tmotorNormal, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393, openLoop, reversed)
#pragma config(UART_Usage, UART2, uartVEXLCD, baudRate19200, IOPins, None, None)
#include "../verkefni3/tasks.c"


task main()
{
	StartTask(StopIfNeed);
	StartTask(BAtteryDisplay);
	StartTask(Claw);
	/*while(true){
		if(SensorValue(lightSensor) < 300)
		{

		}
	}*/
	clawState = 1;
	wait10Msec(100);
	clawState = 0;
	wait10Msec(100);
	clawState = -1;
	wait10Msec(100);
	armState = 1;
	wait10Msec(150);
}
