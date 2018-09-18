
task main()
{
int threshold = 10;
	static int leftSpeed = 0;
	static int rightSpeed = 0;

	while(true)
	{
		leftSpeed = (getJoystickValue(ChA) - getJoystickValue(ChB)/2);	// (y - x)/2
		rightSpeed = (getJoystickValue(ChA) + getJoystickValue(ChB)/2);	// (y + x)/2

		if(leftSpeed > threshold || leftSpeed < -threshold)
		{
			setMotorSpeed(leftMotor, leftSpeed);
		}
		else
		{
			setMotorSpeed(leftMotor, 0);
		}

		if(rightSpeed > threshold || rightSpeed < -threshold)
		{
			setMotorSpeed(rightMotor, rightSpeed);
		}
		else
		{
			setMotorSpeed(rightMotor, 0);
		}

		//If Button "L-Up" is pressed in, we'll set the arm motor to run in reverse.
		if(getJoystickValue(BtnLUp) == 1)
		{
			setMotorSpeed(armMotor, -127);
		}
		//If the "L-Up" isn't pressed, but "L-Down" is, we'll set the motor to run forward.
		else if(getJoystickValue(BtnLDown) == 1)
		{
			setMotorSpeed(armMotor, 127);
		}
		else  //If neither button is pressed, we'll set the motor off.
		{
			setMotorSpeed(armMotor, 0);
		}

		//If Button "L-Up" is pressed in, we'll set the arm motor to run in reverse.
		if(getJoystickValue(BtnRUp) == 1)
		{
			setMotorSpeed(armMotor2, -127);
		}
		//If the "L-Up" isn't pressed, but "L-Down" is, we'll set the motor to run forward.
		else if(getJoystickValue(BtnRDown) == 1)
		{
			setMotorSpeed(armMotor, 127);
		}
		else	//If neither button is pressed, we'll set the motor off.
		{
			setMotorSpeed(clawMotor, 0);
		}

	}
}
