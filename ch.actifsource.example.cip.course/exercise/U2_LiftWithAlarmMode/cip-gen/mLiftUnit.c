/*********************************************************************
	SYSTEM U2_LiftWithAlarmMode
	IMPLEMENTATION Lift
	Module for CIP MACHINE mLiftUnit
	Filename: mLiftUnit.c
	generated by CIP Tool(R)
	
	activated code options:
		C code
		use message interface
			naming option: use default prefix
		use postfix
			LiftUnit 
		'unsigned char' for delays
*********************************************************************/

/* Include Files */

#include "mLiftUnit.h"

/* External Declarations */

void fIMSG_C2_On(void);
void fIMSG_C2_Off(void);
void fIMSG_C1_push(void);
void fIMSG_C4_LeaveGrnd(void);
void fIMSG_C4_LeaveTop(void);
void fIMSG_C4_ReachGrnd(void);
void fIMSG_C4_ReachTop(void);
void fINIT_Alarmswitch (void);
void fINIT_Button (void);
void fINIT_LiftCar (void);

/* Global Declarations */

unsigned char time_LiftUnit = 0;
struct tCHNOUT_mLiftUnit CHNOUT_mLiftUnit;

/* Function Prototypes */

void fSTEP_LiftUnit(void);
void fCHAIN_LiftUnit(void);
void fTIMEUP_LiftUnit(void);
void fREAD_LiftUnit(void);

/* AUTO_ Handler Function */

static void fAUTOHDL_LiftUnit(void)
{
		/* dummy function handling no AUTO_ */
}

/* Timer Functions */

static void fTICK_LiftUnit(void)
{
	++time_LiftUnit;
}

/* Control Functions */

	/* Step Function for CIP Machine */

void fSTEP_LiftUnit(void)
{
	return;
}

	/* Chain Function for CIP Machine */

void fCHAIN_LiftUnit(void)
{
	return;
}

	/* Timeup Function for CIP Machine */

void fTIMEUP_LiftUnit(void)
{
	return;
}

	/* Read Function for CIP Machine */

void fREAD_LiftUnit(void)
{
	return;
}


/* Initialization Function */

int fINIT_LiftUnit(void)
{
	TRG_LiftUnit.TICK_ = fTICK_LiftUnit;
	TRG_LiftUnit.CHAIN_ = fCHAIN_LiftUnit;
	TRG_LiftUnit.TIMEUP_ = fTIMEUP_LiftUnit;
	TRG_LiftUnit.STEP_ = fSTEP_LiftUnit;
	TRG_LiftUnit.READ_ = fREAD_LiftUnit;
	TRG_LiftUnit.AUTO_ = fAUTOHDL_LiftUnit;
	IN_LiftUnit.C2_On = fIMSG_C2_On;
	IN_LiftUnit.C2_Off = fIMSG_C2_Off;
	IN_LiftUnit.C1_push = fIMSG_C1_push;
	IN_LiftUnit.C4_LeaveGrnd = fIMSG_C4_LeaveGrnd;
	IN_LiftUnit.C4_LeaveTop = fIMSG_C4_LeaveTop;
	IN_LiftUnit.C4_ReachGrnd = fIMSG_C4_ReachGrnd;
	IN_LiftUnit.C4_ReachTop = fIMSG_C4_ReachTop;
	iMSG_LiftUnit();
	if (!OUT_LiftUnit.C3_MotOff)
	{
		return 0;
	}
	if (!OUT_LiftUnit.C3_MotScend)
	{
		return 0;
	}
	if (!OUT_LiftUnit.C3_MotRaise)
	{
		return 0;
	}
	fINIT_Alarmswitch ();
	fINIT_Button ();
	fINIT_LiftCar ();
	return 1;
}

/*********************************************************************
	End of Module for CIP MACHINE mLiftUnit
*********************************************************************/

/* Actifsource ID=[a9fcef86-9d17-11e1-90e4-e1fd5739c0f6,f47d8c9c-37d0-11e2-9d61-05c638030bc3,75706e22-2ffd-11e2-8ce2-c76b5b13ae26,f8d9e1eb-37d0-11e2-9d61-05c638030bc3,f47fd695-37d0-11e2-9d61-05c638030bc3,f47fd690-37d0-11e2-9d61-05c638030bc3,ELyvcprDGyIUVMPCvD9Oet7MvUU=] */
