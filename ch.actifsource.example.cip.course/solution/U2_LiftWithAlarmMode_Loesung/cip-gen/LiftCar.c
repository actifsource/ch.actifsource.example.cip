/*******************************************************************
        SYSTEM U4_LiftWithAlarmMode_Loesung
        Module for PROCESS LiftCar
        Filename: LiftCar.c
        generated by CIP Tool(R)

        activated code options:
        	C code
        	use message interface
        		naming option: use default prefix
        	use postfix
        		LiftWithAlarmMode 
        	enable mode inspection
        	'unsigned long' for delays
*********************************************************************/

/* Include Files */

#include "mLiftWithAlarmMode.h"

/* Process Macro Definitions */

#define EXCEPTION return;
#define SELF status_LiftCar.write_access_
#define STATUS (pStatus_LiftCar->read_access_)
#define TIME time_LiftWithAlarmMode

/* Process Enumerations */

enum eMODES_LiftCar
	{working = 1, stopped = 2};

enum eSTATES_LiftCar
	{atGround = 1, atTop, rising, risingAtGround, risingStopped, scending, 
	 scendingAtTop, scendingStopped};

enum eINPULS_LiftCar
	{IP_push = 1, IP_blocking = 2, IP_release = 3};
	

/* External Declarations */

extern unsigned long time_LiftWithAlarmMode;
extern struct tCHNOUT_mLiftWithAlarmMode CHNOUT_mLiftWithAlarmMode;
extern union tSTATUS_Alarmswitch status_Alarmswitch;

/* Global Declarations */

union tSTATUS_LiftCar status_LiftCar;
const union tSTATUS_LiftCar *pStatus_LiftCar = &status_LiftCar;
const int MODTAB_LiftCar[2] =       /* [Alarmswitch states] */
	{working, stopped};


/* Function Prototypes */

void fIMSG_C4_LeaveGrnd(void);
void fIMSG_C4_LeaveTop(void);
void fIMSG_C4_ReachGrnd(void);
void fIMSG_C4_ReachTop(void);
int fPULSE_LiftCar (enum eOUTPLS_LiftWithAlarmMode name_);
void fINIT_LiftCar (void);

/* Input Channel Functions */

void fIMSG_C4_LeaveGrnd(void)
{
	switch(MODTAB_LiftCar[status_Alarmswitch.read_access_.STATE - 1])
	{
	case stopped:
		switch(status_LiftCar.read_access_.STATE)
		{
		case risingAtGround:
		 	status_LiftCar.write_access_.STATE = risingStopped;
		 	CHNOUT_mLiftWithAlarmMode.message_.CHAN_Act_Motor.name_ = C3_MotOff;
		 	OUT_LiftWithAlarmMode.C3_MotOff ();
			break;
		default:
			return;
		}
		break;
	case working:
		switch(status_LiftCar.read_access_.STATE)
		{
		case risingAtGround:
		 	status_LiftCar.write_access_.STATE = rising;
			break;
		default:
			return;
		}
		break;
	default:
		return;
	}
	return;
}

void fIMSG_C4_LeaveTop(void)
{
	switch(MODTAB_LiftCar[status_Alarmswitch.read_access_.STATE - 1])
	{
	case stopped:
		switch(status_LiftCar.read_access_.STATE)
		{
		case scendingAtTop:
		 	status_LiftCar.write_access_.STATE = scendingStopped;
		 	CHNOUT_mLiftWithAlarmMode.message_.CHAN_Act_Motor.name_ = C3_MotOff;
		 	OUT_LiftWithAlarmMode.C3_MotOff ();
			break;
		default:
			return;
		}
		break;
	case working:
		switch(status_LiftCar.read_access_.STATE)
		{
		case scendingAtTop:
		 	status_LiftCar.write_access_.STATE = scending;
			break;
		default:
			return;
		}
		break;
	default:
		return;
	}
	return;
}

void fIMSG_C4_ReachGrnd(void)
{
	switch(MODTAB_LiftCar[status_Alarmswitch.read_access_.STATE - 1])
	{
	case stopped:
		switch(status_LiftCar.read_access_.STATE)
		{
		case scendingStopped:
		 	status_LiftCar.write_access_.STATE = atGround;
			break;
		default:
			return;
		}
		break;
	case working:
		switch(status_LiftCar.read_access_.STATE)
		{
		case scending:
		 	status_LiftCar.write_access_.STATE = atGround;
		 	CHNOUT_mLiftWithAlarmMode.message_.CHAN_Act_Motor.name_ = C3_MotOff;
		 	OUT_LiftWithAlarmMode.C3_MotOff ();
			break;
		default:
			return;
		}
		break;
	default:
		return;
	}
	return;
}

void fIMSG_C4_ReachTop(void)
{
	switch(MODTAB_LiftCar[status_Alarmswitch.read_access_.STATE - 1])
	{
	case stopped:
		switch(status_LiftCar.read_access_.STATE)
		{
		case risingStopped:
		 	status_LiftCar.write_access_.STATE = atTop;
			break;
		default:
			return;
		}
		break;
	case working:
		switch(status_LiftCar.read_access_.STATE)
		{
		case rising:
		 	status_LiftCar.write_access_.STATE = atTop;
		 	CHNOUT_mLiftWithAlarmMode.message_.CHAN_Act_Motor.name_ = C3_MotOff;
		 	OUT_LiftWithAlarmMode.C3_MotOff ();
			break;
		default:
			return;
		}
		break;
	default:
		return;
	}
	return;
}
		
int fPULSE_LiftCar (enum eOUTPLS_LiftWithAlarmMode name_)
{
	switch(name_)
	{
		/* INPULSE blocking */
	case O3_blocking:		/* PULSE CAST from PROCESS Alarmswitch */
		switch(MODTAB_LiftCar[status_Alarmswitch.read_access_.STATE - 1])
		{
		case stopped:
			switch(status_LiftCar.read_access_.STATE)
			{
			case rising:
				status_LiftCar.write_access_.STATE = risingStopped;
				CHNOUT_mLiftWithAlarmMode.message_.CHAN_Act_Motor.name_ = C3_MotOff;
				OUT_LiftWithAlarmMode.C3_MotOff ();
				break;
			case scending:
				status_LiftCar.write_access_.STATE = scendingStopped;
				CHNOUT_mLiftWithAlarmMode.message_.CHAN_Act_Motor.name_ = C3_MotOff;
				OUT_LiftWithAlarmMode.C3_MotOff ();
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
		/* INPULSE push */
	case O4_push:		/* PULSE CAST from PROCESS Button */
		switch(MODTAB_LiftCar[status_Alarmswitch.read_access_.STATE - 1])
		{
		case working:
			switch(status_LiftCar.read_access_.STATE)
			{
			case atGround:
				status_LiftCar.write_access_.STATE = risingAtGround;
				CHNOUT_mLiftWithAlarmMode.message_.CHAN_Act_Motor.name_ = C3_MotRaise;
				OUT_LiftWithAlarmMode.C3_MotRaise ();
				break;
			case atTop:
				status_LiftCar.write_access_.STATE = scendingAtTop;
				CHNOUT_mLiftWithAlarmMode.message_.CHAN_Act_Motor.name_ = C3_MotScend;
				OUT_LiftWithAlarmMode.C3_MotScend ();
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
		/* INPULSE release */
	case O3_release:		/* PULSE CAST from PROCESS Alarmswitch */
		switch(MODTAB_LiftCar[status_Alarmswitch.read_access_.STATE - 1])
		{
		case working:
			switch(status_LiftCar.read_access_.STATE)
			{
			case risingStopped:
				status_LiftCar.write_access_.STATE = rising;
				CHNOUT_mLiftWithAlarmMode.message_.CHAN_Act_Motor.name_ = C3_MotRaise;
				OUT_LiftWithAlarmMode.C3_MotRaise ();
				break;
			case scendingStopped:
				status_LiftCar.write_access_.STATE = scending;
				CHNOUT_mLiftWithAlarmMode.message_.CHAN_Act_Motor.name_ = C3_MotScend;
				OUT_LiftWithAlarmMode.C3_MotScend ();
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
	default:
		return 0;
	}
	return 1;
}

/* Process Initialization Function */

void fINIT_LiftCar (void)
{
	status_LiftCar.write_access_.MODE = working;
	status_LiftCar.write_access_.STATE = atGround;
}		

/*********************************************************************
	End of Module for PROCESS LiftCar
*********************************************************************/
/* Actifsource ID=[e9267837-2596-11e1-ae2f-a14f3e396de6,474f129b-2ffa-11e2-8ce2-c76b5b13ae26,741c1ae4-2ff8-11e2-8ce2-c76b5b13ae26,278e1b7e-2ffa-11e2-8ce2-c76b5b13ae26,47515c8f-2ffa-11e2-8ce2-c76b5b13ae26,741e64d7-2ff8-11e2-8ce2-c76b5b13ae26,742a4c1c-2ff8-11e2-8ce2-c76b5b13ae26,91gMwakuleZFxtx4miWiOMsJoCI=] */