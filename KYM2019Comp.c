#pragma config(Sensor, in1,    ArmThang,       sensorPotentiometer)
#pragma config(Sensor, dgtl1,  the_thing,      sensorTouch)
#pragma config(Sensor, dgtl2,  yes,            sensorTouch)
#pragma config(Sensor, dgtl10, Eyes,           sensorSONAR_mm)
#pragma config(Sensor, dgtl12, Pickle_Rick,    sensorQuadEncoder)
#pragma config(Motor,  port1,           abcd,          tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port2,           MotorRight,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           MotorLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           Upything,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Upything2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           Skizer2,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           SpinnyDeal,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LiftyThing,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           Claw,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          dcba,          tmotorVex269_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

int joystickTolerance = 10;
int fixNum(int num){
	if (num >= -joystickTolerance && num <= joystickTolerance)
		return 0;
	return num;
}

void pre_auton()
{
	resetSensor(dgtl5);
	resetSensor(dgtl2);
	resetSensor(dgtl1);
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	//Go forward
	//Get the coin
	//Put the coin on the pole
	//Park
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	// User control code here, inside the loop. Feel free to add your own little touch to the project.

	while (1 == 1)
	{
		motor[port1] = fixNum(vexRT[Ch1]);
		motor[port10] = fixNum(-vexRT[Ch4]);
		motor[MotorLeft] = fixNum(vexRT[Ch3]);
		motor[MotorRight] = fixNum(vexRT[Ch2]);
		//Turn table.
		if(vexRT[Btn7L] == 1) //8 Left
		{
			motor[SpinnyDeal] = 50;
		}
		else if(vexRT[Btn7R] == 1) //8 Right
		{
			motor[SpinnyDeal] = -50;
		}
		else //No input
		{
			motor[SpinnyDeal] = 0;
		}

		//Claw code.
		if(vexRT[Btn8U] == 1) //8 Up
		{
			motor[Claw] = 80;
		}
		else if(vexRT[Btn8D] == 1) //8 Down
		{
			motor[Claw] = -80;
		}
		else //No input
		{
			motor[Claw] = 0;
		}
		//Without futher knolage this is the furthest we can go.
		//Claw lift.

		if(vexRT[Btn7U] == 1) //7 Up
		{
			motor[LiftyThing] = 100;
		}

		else if(vexRT[Btn7D] == 1) //7 Down
		{
			motor[LiftyThing] = -100;
		}
		else //No input
		{
			motor[LiftyThing] = 10;
		}

		//Test 22.05, this would help with the rotation syt.
		//The the moble cone mover.
		if(vexRT[Btn6U] == 1) //6 Up
		{
			if(SensorValue[dgtl1] == 0)
			{
				motor(Upything) = 90;
			}
			else
			{
				motor(Upything) = 0;
			}

			if(SensorValue[dgtl2] == 0)
			{
				motor(Upything2) = 100;
			}
			else
			{
				motor(Upything2) = 0;
			}

		}

		else if(vexRT[Btn6D] == 1) //6 Down
		{
			motor[Upything] = -90;
			motor[Upything2] = -100;
		}
		else //No input
		{
			motor[Upything] = motor[Upything2] = 0;
		}

	}
	if((dgtl10) > 90)
	{
		motor[MotorLeft] = motor[MotorRight] = 100;
	}
	else if((dgtl10) <= 110)
	{
		motor[MotorLeft] = motor[MotorRight] = -100;
	}
	else
	{
		motor[MotorLeft] = motor[MotorRight] = 0;
	}
}

/*
NOTHING IS FINAL, THE TIDE CAN SHIFT

This is a brefing room for this next year.

obj 1. get the cones to flip and be mounted onto the poles
obj 2. park the robit on the tall park spot
obj 3. ato code
obj 4. flip the flags to earn us more points (First flip then shoot)

possibly switch the last two as this will allow for more points to be scored

The two ways of fliping:
	On claw ~Best but is heavy
	On Bot ~Not super awsome, but is more effective






*/
