/*******************************************************************
        SYSTEM U2_LiftWithAlarmMode
        Module for PROCESS LiftCar
        Filename: LiftCar.c
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

/* Process Macro Definitions */

#define EXCEPTION return;
#define SELF status_LiftCar.write_access_
#define STATUS (pStatus_LiftCar->read_access_)
#define TIME time_LiftUnit

/* Process Enumerations */

enum eMODES_LiftCar
	{working = 1, stopped = 2};

enum eSTATES_LiftCar
	{atGround = 1, atTop, rising, risingAtGround, risingStopped, scending, 
	 scendingAtTop, scendingStopped};

enum eINPULS_LiftCar
	{IP_push = 1};
	

/* External Declarations */

extern unsigned char time_LiftUnit;
extern struct tCHNOUT_mLiftUnit CHNOUT_mLiftUnit;
extern union tSTATUS_Alarmswitch status_Alarmswitch;

/* Global Declarations */

union tSTATUS_LiftCar status_LiftCar;
const union tSTATUS_LiftCar *pStatus_LiftCar = &status_LiftCar;
const int MODTAB_LiftCar[2] =       /* [Alarmswitch states] */
	{, };


/* Function Prototypes */

void fIMSG_C4_LeaveGrnd(void);
void fIMSG_C4_LeaveTop(void);
void fIMSG_C4_ReachGrnd(void);
void fIMSG_C4_ReachTop(void);
int fPULSE_LiftCar (enum eOUTPLS_LiftUnit name_);
void fINIT_LiftCar (void);

/* Input Channel Functions */

void fIMSG_C4_LeaveGrnd(void)
{
	switch(MODTAB_LiftCar[status_Alarmswitch.read_access_.STATE - 1])
	{
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
	case working:
		switch(status_LiftCar.read_access_.STATE)
		{
		case scending:
		 	status_LiftCar.write_access_.STATE = atGround;
		 	CHNOUT_mLiftUnit.message_.CHAN_Act_Motor.name_ = C3_MotOff;
		 	OUT_LiftUnit.C3_MotOff ();
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
	case working:
		switch(status_LiftCar.read_access_.STATE)
		{
		case rising:
		 	status_LiftCar.write_access_.STATE = atTop;
		 	CHNOUT_mLiftUnit.message_.CHAN_Act_Motor.name_ = C3_MotOff;
		 	OUT_LiftUnit.C3_MotOff ();
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
		
int fPULSE_LiftCar (enum eOUTPLS_LiftUnit name_)
{
	switch(name_)
	{
		/* INPULSE push */
	case O6_push:		/* PULSE CAST from PROCESS Button */
		switch(MODTAB_LiftCar[status_Alarmswitch.read_access_.STATE - 1])
		{
		case working:
			switch(status_LiftCar.read_access_.STATE)
			{
			case atGround:
				status_LiftCar.write_access_.STATE = risingAtGround;
				CHNOUT_mLiftUnit.message_.CHAN_Act_Motor.name_ = C3_MotRaise;
				OUT_LiftUnit.C3_MotRaise ();
				break;
			case atTop:
				status_LiftCar.write_access_.STATE = scendingAtTop;
				CHNOUT_mLiftUnit.message_.CHAN_Act_Motor.name_ = C3_MotScend;
				OUT_LiftUnit.C3_MotScend ();
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
	status_LiftCar.write_access_.STATE = atGround;
}		

/*********************************************************************
	End of Module for PROCESS LiftCar
*********************************************************************/
/* Actifsource ID=[e9267837-2596-11e1-ae2f-a14f3e396de6,f47d8c9c-37d0-11e2-9d61-05c638030bc3,75706e22-2ffd-11e2-8ce2-c76b5b13ae26,f8d9e1eb-37d0-11e2-9d61-05c638030bc3,f47fd690-37d0-11e2-9d61-05c638030bc3,75706e25-2ffd-11e2-8ce2-c76b5b13ae26,7572df7d-2ffd-11e2-8ce2-c76b5b13ae26,L4nM0fU/548jfvHvVcLhrGGE1Vc=] */