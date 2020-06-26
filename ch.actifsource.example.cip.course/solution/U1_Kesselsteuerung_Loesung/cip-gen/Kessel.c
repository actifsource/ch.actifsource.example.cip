/*******************************************************************
        SYSTEM Kesselsteuerung_Loesung
        Module for PROCESS Kessel
        Filename: Kessel.c
        generated by CIP Tool(R)

        activated code options:
        	C code
        	use message interface
        		naming option: use default prefix
        	use postfix
        		KesselUnit 
        	enable mode inspection
        	'unsigned long' for delays
*********************************************************************/

/* Include Files */

#include "mKesselUnit.h"
#include "tKesselUnit.h"

/* Process Macro Definitions */

#define EXCEPTION return;
#define SELF status_Kessel.write_access_
#define STATUS (pStatus_Kessel->read_access_)
#define TIME time_KesselUnit
#define ende() TRTAB_ende \
	[status_Schalter.read_access_.STATE - 1] != 0

/* Process Enumerations */

enum eMODES_Kessel
	{normal = 1};

enum eSTATES_Kessel
	{leer = 1, leerFuellend, tlwVollFuellend, tlwVollLeerend, vollLeerend};

enum eINPULS_Kessel
	{IP_start = 2};
	

/* External Declarations */

extern unsigned long time_KesselUnit;
extern struct tCHNOUT_mKesselUnit CHNOUT_mKesselUnit;
extern union tSTATUS_Schalter status_Schalter;
int fPULSE_TempRegler (enum eOUTPLS_KesselUnit name_);

/* Global Declarations */

union tSTATUS_Kessel status_Kessel;
const union tSTATUS_Kessel *pStatus_Kessel = &status_Kessel;
const static unsigned char TRTAB_ende[2] =      /* [Schalter states] */
	{1, 0};


/* Function Prototypes */

static void test(void);

void fIMSG_C3_UeberN1(void);
void fIMSG_C3_UeberN2(void);
void fIMSG_C3_UnterN1(void);
void fIMSG_C3_UnterN2(void);
int fPULSE_Kessel (enum eOUTPLS_KesselUnit name_);
void fINIT_Kessel (void);
void fDUMP_Kessel (void);

/* Trace Function Prototypes */


/* User Functions */

static void test(void)
{
	SELF.MODE;
}
			
/* Input Channel Functions */

void fIMSG_C3_UeberN1(void)
{
	switch(status_Kessel.read_access_.STATE)
	{
	case leerFuellend:
	 	printf("       TRANSITION '4 UeberN1' Kessel.normal: STATE leerFuellend -> tlwVollFuellend  [5b7e2b8c-2fd9-11e2-a23a-331776341c66]\n");
	 	status_Kessel.write_access_.STATE = tlwVollFuellend;
	 	{
	 		struct tTRACE_CHANGE_KesselUnit elements[2];
	 		fTRACE_APPEND_CHANGE_KesselUnit(&elements[0], 4, 1, 3);
	 		fTRACE_APPEND_CHANGE_KesselUnit(&elements[1], 4, 1, 7);
	 		TRACE_KesselUnit.CHANGE_(2, elements);
	 	}
	 	fPULSE_TempRegler (O4_startTR);
		break;
	default:
		return;
	}
	return;
}

void fIMSG_C3_UeberN2(void)
{
	switch(status_Kessel.read_access_.STATE)
	{
	case tlwVollFuellend:
	 	printf("       TRANSITION '6 UeberN2' Kessel.normal: STATE tlwVollFuellend -> vollLeerend  [5b7e2b94-2fd9-11e2-a23a-331776341c66]\n");
	 	status_Kessel.write_access_.STATE = vollLeerend;
	 	{
	 		struct tTRACE_CHANGE_KesselUnit elements[2];
	 		fTRACE_APPEND_CHANGE_KesselUnit(&elements[0], 4, 1, 5);
	 		fTRACE_APPEND_CHANGE_KesselUnit(&elements[1], 4, 1, 8);
	 		TRACE_KesselUnit.CHANGE_(2, elements);
	 	}
	 	CHNOUT_mKesselUnit.message_.CHAN_Act_Kessel.name_ = C4_Leeren;
	 	OUT_KesselUnit.C4_Leeren ();
		break;
	default:
		return;
	}
	return;
}

void fIMSG_C3_UnterN1(void)
{
	switch(status_Kessel.read_access_.STATE)
	{
	case tlwVollLeerend:
		if (ende())
		{
			printf("       TRANSITION '1 UnterN1' Kessel.normal: STATE tlwVollLeerend -> leer  [5b7bba84-2fd9-11e2-a23a-331776341c66]\n");
			status_Kessel.write_access_.STATE = leer;
			{
				struct tTRACE_CHANGE_KesselUnit elements[2];
				fTRACE_APPEND_CHANGE_KesselUnit(&elements[0], 4, 1, 1);
				fTRACE_APPEND_CHANGE_KesselUnit(&elements[1], 4, 1, 9);
				TRACE_KesselUnit.CHANGE_(2, elements);
			}
			fPULSE_TempRegler (O4_stopTR);
		}
		else
		{
			printf("       TRANSITION '5 UnterN1' Kessel.normal: STATE tlwVollLeerend -> leerFuellend  [5b7e2b90-2fd9-11e2-a23a-331776341c66]\n");
			status_Kessel.write_access_.STATE = leerFuellend;
			{
				struct tTRACE_CHANGE_KesselUnit elements[2];
				fTRACE_APPEND_CHANGE_KesselUnit(&elements[0], 4, 1, 2);
				fTRACE_APPEND_CHANGE_KesselUnit(&elements[1], 4, 1, 10);
				TRACE_KesselUnit.CHANGE_(2, elements);
			}
			CHNOUT_mKesselUnit.message_.CHAN_Act_Kessel.name_ = C4_Fuellen;
			OUT_KesselUnit.C4_Fuellen ();
		}
		break;
	default:
		return;
	}
	return;
}

void fIMSG_C3_UnterN2(void)
{
	switch(status_Kessel.read_access_.STATE)
	{
	case vollLeerend:
	 	printf("       TRANSITION '7 UnterN2' Kessel.normal: STATE vollLeerend -> tlwVollLeerend  [5b7e2b98-2fd9-11e2-a23a-331776341c66]\n");
	 	status_Kessel.write_access_.STATE = tlwVollLeerend;
	 	{
	 		struct tTRACE_CHANGE_KesselUnit elements[2];
	 		fTRACE_APPEND_CHANGE_KesselUnit(&elements[0], 4, 1, 4);
	 		fTRACE_APPEND_CHANGE_KesselUnit(&elements[1], 4, 1, 11);
	 		TRACE_KesselUnit.CHANGE_(2, elements);
	 	}
		break;
	default:
		return;
	}
	return;
}
		
int fPULSE_Kessel (enum eOUTPLS_KesselUnit name_)
{
	switch(name_)
	{
		/* INPULSE start */
	case O3_start:		/* PULSE CAST from PROCESS Schalter */
		switch(status_Kessel.read_access_.STATE)
		{
		case leer:
			printf("       TRANSITION '3 start' Kessel.normal: STATE leer -> leerFuellend  [5b7e2b88-2fd9-11e2-a23a-331776341c66]\n");
			status_Kessel.write_access_.STATE = leerFuellend;
			{
				struct tTRACE_CHANGE_KesselUnit elements[2];
				fTRACE_APPEND_CHANGE_KesselUnit(&elements[0], 4, 1, 2);
				fTRACE_APPEND_CHANGE_KesselUnit(&elements[1], 4, 1, 6);
				TRACE_KesselUnit.CHANGE_(2, elements);
			}
			CHNOUT_mKesselUnit.message_.CHAN_Act_Kessel.name_ = C4_Fuellen;
			OUT_KesselUnit.C4_Fuellen ();
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

/* Process Dump Function */

void fDUMP_Kessel(void)
{
	struct tTRACE_DUMP_KesselUnit element;
	int state =  status_Kessel.read_access_.STATE;
	fTRACE_APPEND_DUMP_KesselUnit(&element, 4, 1, normal, state, state);
	TRACE_KesselUnit.DUMP_(&element);
}

/* Process Initialization Function */

void fINIT_Kessel (void)
{
	status_Kessel.write_access_.MODE = normal;
	status_Kessel.write_access_.STATE = leer;
	status_Kessel.write_access_.anzahlZyklen = 0;
	status_Kessel.write_access_.zaehler = 0;
}		

/*********************************************************************
	End of Module for PROCESS Kessel
*********************************************************************/
/* Actifsource ID=[e9267837-2596-11e1-ae2f-a14f3e396de6,304ffac5-2fda-11e2-a23a-331776341c66,5b61a23d-2fd9-11e2-a23a-331776341c66,21741d8a-2fda-11e2-a23a-331776341c66,305244b9-2fda-11e2-a23a-331776341c66,5b6fd36a-2fd9-11e2-a23a-331776341c66,5b6fd36e-2fd9-11e2-a23a-331776341c66,yIHmTYOyRrVFel5411hpFIxmpuM=] */
