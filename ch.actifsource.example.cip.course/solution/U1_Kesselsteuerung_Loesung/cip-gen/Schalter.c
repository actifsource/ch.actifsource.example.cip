/*******************************************************************
        SYSTEM Kesselsteuerung_Loesung
        Module for PROCESS Schalter
        Filename: Schalter.c
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
#define SELF status_Schalter.write_access_
#define STATUS (pStatus_Schalter->read_access_)
#define TIME time_KesselUnit

/* Process Enumerations */

enum eMODES_Schalter
	{normal = 1};

enum eSTATES_Schalter
	{Aus = 1, Ein};


/* External Declarations */

extern unsigned long time_KesselUnit;
extern struct tCHNOUT_mKesselUnit CHNOUT_mKesselUnit;
int fPULSE_Kessel (enum eOUTPLS_KesselUnit name_);

/* Global Declarations */

union tSTATUS_Schalter status_Schalter;
const union tSTATUS_Schalter *pStatus_Schalter = &status_Schalter;

/* Function Prototypes */

void fIMSG_C2_KesselAus(void);
void fIMSG_C2_KesselEin(void);
void fINIT_Schalter (void);
void fDUMP_Schalter (void);

/* Trace Function Prototypes */


/* Input Channel Functions */

void fIMSG_C2_KesselAus(void)
{
	switch(status_Schalter.read_access_.STATE)
	{
	case Ein:
	 	printf("       TRANSITION '2 KesselAus' Schalter.normal: STATE Ein -> Aus  [5b8a11d6-2fd9-11e2-a23a-331776341c66]\n");
	 	status_Schalter.write_access_.STATE = Aus;
	 	{
	 		struct tTRACE_CHANGE_KesselUnit elements[2];
	 		fTRACE_APPEND_CHANGE_KesselUnit(&elements[0], 3, 1, 1);
	 		fTRACE_APPEND_CHANGE_KesselUnit(&elements[1], 3, 1, 4);
	 		TRACE_KesselUnit.CHANGE_(2, elements);
	 	}
		break;
	default:
		return;
	}
	return;
}

void fIMSG_C2_KesselEin(void)
{
	switch(status_Schalter.read_access_.STATE)
	{
	case Aus:
	 	printf("       TRANSITION '1 KesselEin' Schalter.normal: STATE Aus -> Ein  [5b8a11d2-2fd9-11e2-a23a-331776341c66]\n");
	 	status_Schalter.write_access_.STATE = Ein;
	 	{
	 		struct tTRACE_CHANGE_KesselUnit elements[2];
	 		fTRACE_APPEND_CHANGE_KesselUnit(&elements[0], 3, 1, 2);
	 		fTRACE_APPEND_CHANGE_KesselUnit(&elements[1], 3, 1, 3);
	 		TRACE_KesselUnit.CHANGE_(2, elements);
	 	}
	 	fPULSE_Kessel (O3_start);
		break;
	default:
		return;
	}
	return;
}
		
/* Process Dump Function */

void fDUMP_Schalter(void)
{
	struct tTRACE_DUMP_KesselUnit element;
	int state =  status_Schalter.read_access_.STATE;
	fTRACE_APPEND_DUMP_KesselUnit(&element, 3, 1, normal, state, state);
	TRACE_KesselUnit.DUMP_(&element);
}

/* Process Initialization Function */

void fINIT_Schalter (void)
{
	status_Schalter.write_access_.MODE = normal;
	status_Schalter.write_access_.STATE = Aus;
}		

/*********************************************************************
	End of Module for PROCESS Schalter
*********************************************************************/
/* Actifsource ID=[e9267837-2596-11e1-ae2f-a14f3e396de6,304ffac5-2fda-11e2-a23a-331776341c66,5b61a23d-2fd9-11e2-a23a-331776341c66,21741d8a-2fda-11e2-a23a-331776341c66,305244b9-2fda-11e2-a23a-331776341c66,5b6fd36a-2fd9-11e2-a23a-331776341c66,5b8a11b8-2fd9-11e2-a23a-331776341c66,/McJtYxs7JXTpqCnTfL+jnNVIq4=] */
