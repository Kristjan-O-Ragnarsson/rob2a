const float TURNBASE = 3.335;
const int ENERTIA = 70;
int stopTime = 250;
int power;


int driveDist(float cm){
	return (cm / 32.0) * 360;
}

void turn(int deg, bool left){
  SensorValue[rightEncoder] = 0;
  SensorValue[leftEncoder]  = 0;
	if(left){
		while(SensorValue[rightEncoder] < (deg * TURNBASE) && SensorValue[leftEncoder] > (-1 * deg * TURNBASE))
	  {
	    motor[rightMotor] = 63;
	    motor[leftMotor]  = -63;
	  }
	} else {
		while(SensorValue[leftEncoder] < (deg * TURNBASE) && SensorValue[rightEncoder] > (-1 * deg * TURNBASE))
	  {
	    motor[rightMotor] = -63;
	    motor[leftMotor]  = 63;
	  }
	}
	motor[rightMotor] = 0;
  motor[leftMotor]  = 0;
}

void drive(float dist, bool forward){
	int encoderTicks = driveDist(dist);
	int encoderStopValue = encoderTicks;
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
