#pragma config(Sensor, in1,    ArmThang,       sensorPotentiometer)
#pragma config(Sensor, dgtl1,  The_Thing,      sensorTouch)
#pragma config(Sensor, dgtl2,  Yes,            sensorTouch)
#pragma config(Sensor, dgtl10, Eyes,           sensorSONAR_mm)
#pragma config(Sensor, dgtl12, Quaa,    sensorQuadEncoder)
#pragma config(Motor,  port1,           Testr1,          tmotorVex269_HBridge, openLoop)
#pragma config(Motor,  port2,           MotorRight,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           MotorLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           Upything,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           Upything2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           Skizer2,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           SpinnyDeal,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           LiftyThing,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           Claw,          tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          Testr2,          tmotorVex269_HBridge, openLoop)
//*!!Code automatically generated by 'JOSHU' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

int time = 10; //time in sec for pings

//Control tolerance, keeps from overheating.
int joystickTolerance = 25;
int fixNum(int num){
	if (num >= -joystickTolerance && num <= joystickTolerance)
		return 0;
	return num;
}

//Active ping protocal.
function (activePing){
while(1==1){
	sonarOn;
	wait(0.1);
	sonarOff;
	wait(1);
	}
}

//Range, in ft.
int sonarRange = 20;
int sonarConf(int pingResponce){
	if (pingResponce > -sonarRange && pingResponce =< sonarRange)
		return 0;
	return pingResponce;
}
if (sonarConf == true){
	ledOn(dgtl7);
	soundBlip;
	activePing;

}

//This part is great for keeping senosrs in line.
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
	motor[MotorRight] = 120;
	motor[MotorLeft] = 120;
	motor[LiftyThing] = 100;
	waitUntil(SensorValue[ArmThang] == 100);//wait(1.7)
	motor[LiftyThing] = 10;
	wait(3);//5
	//Pick it up
	motor[MotorLeft] = motor[MotorRight] = 0;
	motor[Upything] = motor[Upything2] = 100;
	motor[Claw] = -100;
	wait(2.3);//4
	//Pull it back
	motor[Claw] = 0;
	motor[Upything] = motor[Upything2] = 0;
	motor[MotorLeft] = -120;
	motor[MotorRight] = -120;
	wait(4.7);//5
	//Drop it while turning
	motor[Upything] = motor[Upything2] = -100;
	motor[MotorLeft] = 0;
	wait(2.5); //4
	//Pull back
	motor[Upything] = motor[Upything2] = 0;
	wait(0.5);
	motor[MotorLeft] = motor[MotorRight] = -100;
	wait(0.3);
	motor[MotorLeft] = motor[MotorRight] = motor [Claw] = motor[LiftyThing] = 0;
	//Wait further instructions
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
	// User control code here, inside the loop

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
	if(SensorValue(dgtl10) > 90)
	{
		motor[MotorLeft] = motor[MotorRight] = 100;
	}
	else if(SensorValue(dgtl10) <= 110)
	{
		motor[MotorLeft] = motor[MotorRight] = -100;
	}
	else
	{
		motor[MotorLeft] = motor[MotorRight] = 0;
	}
}
