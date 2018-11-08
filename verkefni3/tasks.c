
task StopIfNeed()
{
	while(true)
	{
		if( vexRT[Btn8D] == 1 && vexRT[Btn7D] == 1 || SensorValue[touchsensor] == 1)
		{
      StopAllTasks();
   	}
	}

}
