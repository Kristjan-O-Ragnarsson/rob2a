void armMotorSpeed(int n){
		motor[armMotor] = n;
	}

void clawMotorSpeed(int n){
    motor[clawMotor] = n;
}

int clawState = 0;
int armState = 0;

task StopIfNeed()
{
	while(true)
	{
		if( vexRT[Btn8D] == 1 && vexRT[Btn7D] == 1 || SensorValue[touchSensor] == 1)
		{
      StopAllTasks();
   	}
	}

}

task BAtteryDisplay()
{
	bLCDBacklight = true;
	string mainBattery, backupBattery;
	while(true)
	{
		clearLCDLine(0);											// Clear line 1 (0) of the LCD
		clearLCDLine(1);											// Clear line 2 (1) of the LCD

		//Display the Primary Robot battery voltage
		displayLCDString(0, 0, "Primary: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
		displayNextLCDString(mainBattery);

		//Display the Backup battery voltage
		displayLCDString(1, 0, "Backup: ");
		sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');	//Build the value to be displayed
		displayNextLCDString(backupBattery);

		//Short delay for the LCD refresh rate
		wait1Msec(100);
	}
}

task Claw()
{
	while(true)
	{
		if(armState == 1)
		{
			armMotorSpeed(32);
		}
		else if(armState == -1)
		{
			armMotorSpeed(-16);
		}
		else
		{
			armMotorSpeed(0);
		}

		if(clawState == 1)
		{
			clawMotorSpeed(42);
		}
		else if(clawState == -1)
		{
			clawMotorSpeed(-16);
		}
		else
		{
			clawMotorSpeed(0);
		}
	}
}
