#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S2,     HTPB,           sensorI2CCustom9V)
#pragma config(Sensor, S3,     light,          sensorCOLORFULL)
#pragma config(Sensor, S4,     ir,             sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     left,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     right,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     arm,           tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     motorG,        tmotorTetrix, openLoop)
/**#pragma config(Servo,  srvo_S1_C3_1,    latch,                tServoStandard)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)**/
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

task main()
{
	int armPower = 4;
	int flagPower = 50;

	while(true)
	{
		getJoystickSettings(joystick);

		if(abs(joystick.joy1_y1) > 5){
			motor[left] = joystick.joy1_y1;
		}
		else{
			motor[left] = 0;
		}

		if(abs(joystick.joy1_y2) > 5){
			motor[right] = -joystick.joy1_y2;
		}
		else{
			motor[right] = 0;
		}

		/**		if(joy1Btn(6) == 1){
		motor[arm] = armPower;
		}
		else if(joy1Btn(8) == 1){
		motor[arm] = -armPower;
		}
		else{
		motor[arm] = 0;
		}**/

		if(joy1Btn(5) == 1){
			motor[motorG] = flagPower;
		}
		else if(joy1Btn(7) == 1){
			motor[motorG] = -flagPower;
		}
		else{
			motor[motorG] = 0;
		}

	}


}
