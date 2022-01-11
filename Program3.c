#pragma config(Sensor, S1,     touch,          sensorEV3_Touch)
#pragma config(Sensor, S2,     ultrasonic,     sensorEV3_Ultrasonic)
#pragma config(Sensor, S3,     color,          sensorEV3_Color)
#pragma config(Sensor, S4,     gyro,           sensorEV3_Gyro)
#pragma config(Motor,  motorA,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          bookMotor,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorD,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)


task main()
{

	while(getUSDistance(ultrasonic) >50){
		playSoundFile("Analyze");
		wait1Msec(100);
		motor[leftMotor] = 10;
		wait1Msec(100);

		if(getUSDistance(ultrasonic) <=50){
			motor[leftMotor]=20;
			motor[rightMotor]=20;
			wait1Msec(2000);}

		if(getUSDistance(ultrasonic) <30){
			break;
		}
	}

	motor[leftMotor]=0;
	motor[rightMotor]=0;
	wait1Msec(1000);


	playSoundFile("Blip 2");
	wait1Msec(1000);
	motor[rightMotor] = 10;
	wait1Msec(3500);

	motor[leftMotor]=0;
	motor[rightMotor]=0;
	wait1Msec(1000);

	playSoundFile("Forward");

	motor[leftMotor]=50;
	motor[rightMotor]=51;
	wait1Msec(10000);


	motor[leftMotor]=0;
	motor[rightMotor]=0;
	wait1Msec(1000);

	playSoundFile("Backing alert");
	motor[bookMotor]=30;
	wait1Msec(7000);
      motor[bookMotor]=0;
	wait1Msec(1000);


	playSoundFile("Blip 2");
	wait1Msec(1000);
	motor[rightMotor] = 10;
	wait1Msec(3500);

	motor[leftMotor]=0;
	motor[rightMotor]=0;
	wait1Msec(1000);

	motor[leftMotor]=40;
	motor[rightMotor]=41;
	wait1Msec(6000);

	motor[leftMotor]=0;
	motor[rightMotor]=0;
	wait1Msec(1000);

	playSoundFile("Blip 2");
	wait1Msec(1000);
	motor[rightMotor] = 10;
	wait1Msec(3500);

	motor[leftMotor]=0;
	motor[rightMotor]=0;
	wait1Msec(1000);


	playSoundFile("Forward");
	motor[leftMotor]=50;
	motor[rightMotor]=51;
	wait1Msec(12000);

	motor[leftMotor]=0;
	motor[rightMotor]=0;
	wait1Msec(1000);


	playSoundFile("Ready");
	wait1Msec(2000);

}
