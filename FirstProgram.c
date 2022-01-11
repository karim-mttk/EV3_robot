#pragma config(Sensor, S1,     touch,          sensorEV3_Touch)
#pragma config(Sensor, S2,     ultrasonic,     sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     color,          sensorEV3_Color)
#pragma config(Sensor, S4,     gyro,           sensorEV3_Gyro)
#pragma config(Motor,  motorA,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          bookMotor,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorD,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)


task main()
{



	while(getUSDistance(ultrasonic) >50)
	{
		playSoundFile("Analyze");
		wait1Msec(100);
		motor[leftMotor] = 20;
		wait1Msec(100);

		if(getUSDistance(ultrasonic) <=50){
			motor[leftMotor]=20;
			motor[rightMotor]=20;
			wait1Msec(2000);}

		if(getUSDistance(ultrasonic) <30){
			break;
	}
}

	wait(1, seconds);
	stopAllMotors();

	playSoundFile("Blip 2");
	wait1Msec(1000);
	motor[rightMotor] = 10;
	wait1Msec(3500);

	wait(2, seconds);
	stopAllMotors();


	playSoundFile("Forward");
        motor[leftMotor]=50;
	motor[rightMotor]=51;
	wait1Msec(10000);

	
        stopAllMotors();
        wait(2, seconds);
	
        playSoundFile("Backing alert");
	motor[bookMotor]=30;
	wait1Msec(7000);

	stopAllMotors();

	playSoundFile("Blip 2");
	wait1Msec(1000);
	motor[rightMotor] = 10;
	wait1Msec(3500);

	stopAllMotors();

	playSoundFile("Blip 2");
	wait1Msec(1000);
	motor[rightMotor] = 10;
	wait1Msec(3500);

	stopAllMotors();


	playSoundFile("Forward");
	motor[leftMotor]=50;
	motor[rightMotor]=51;
	wait1Msec(12000);

	stopAllMotors();

	playSoundFile("Ready");
	wait1Msec(2000);

}
