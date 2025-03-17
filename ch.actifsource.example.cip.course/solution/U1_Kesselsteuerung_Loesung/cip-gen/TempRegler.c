/*******************************************************************
        SYSTEM Kesselsteuerung_Loesung
        Module for PROCESS TempRegler
        Filename: TempRegler.c
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
#define SELF status_TempRegler.write_access_
#define STATUS (pStatus_TempRegler->read_access_)
#define TIME time_KesselUnit
#define wirdLeer() TRTAB_wirdLeer \
	[status_Kessel.read_access_.STATE - 1] != 0

/* Process Enumerations */

enum eMODES_TempRegler
	{normal = 1};

enum eSTATES_TempRegler
	{kaltAus = 1, kaltEin, warmAus};

enum eINPULS_TempRegler
	{IP_startTR = 1, IP_stopTR};
	

/* External Declarations */

extern unsigned long time_KesselUnit;
extern struct tCHNOUT_mKesselUnit CHNOUT_mKesselUnit;
extern union tSTATUS_Kessel status_Kessel;

/* Global Declarations */

union tSTATUS_TempRegler status_TempRegler;
const union tSTATUS_TempRegler *pStatus_TempRegler = &status_TempRegler;
const static unsigned char TRTAB_wirdLeer[5] =      /* [Kessel states] */
	{1, 0, 0, 0, 0};


/* Function Prototypes */

void fIMSG_C5_UeberT(void);
void fIMSG_C5_UnterT(void);
int fPULSE_TempRegler (enum eOUTPLS_KesselUnit name_);
void fINIT_TempRegler (void);
void fDUMP_TempRegler (void);

/* Trace Function Prototypes */


/* Input Channel Functions */

void fIMSG_C5_UeberT(void)
{
	switch(status_TempRegler.read_access_.STATE)
	{
	case kaltAus:
	 	printf("       TRANSITION '7 UeberT' TempRegler.normal: STATE kaltAus -> warmAus  [5b8ecd1e-2fd9-11e2-a23a-331776341c66]\n");
	 	status_TempRegler.write_access_.STATE = warmAus;
	 	{
	 		struct tTRACE_CHANGE_KesselUnit elements[2];
	 		fTRACE_APPEND_CHANGE_KesselUnit(&elements[0], 5, 1, 3);
	 		fTRACE_APPEND_CHANGE_KesselUnit(&elements[1], 5, 1, 5);
	 		TRACE_KesselUnit.CHANGE_(2, elements);
	 	}
		break;
	case kaltEin:
	 	printf("       TRANSITION '3 UeberT' TempRegler.normal: STATE kaltEin -> warmAus  [5b8ecd0e-2fd9-11e2-a23a-331776341c66]\n");
	 	status_TempRegler.write_access_.STATE = warmAus;
	 	{
	 		struct tTRACE_CHANGE_KesselUnit elements[2];
	 		fTRACE_APPEND_CHANGE_KesselUnit(&elements[0], 5, 1, 3);
	 		fTRACE_APPEND_CHANGE_KesselUnit(&elements[1], 5, 1, 6);
	 		TRACE_KesselUnit.CHANGE_(2, elements);
	 	}
	 	CHNOUT_mKesselUnit.message_.CHAN_Act_TempRegler.name_ = C6_HeizAus;
	 	OUT_KesselUnit.C6_HeizAus ();
		break;
	default:
		return;
	}
	return;
}

void fIMSG_C5_UnterT(void)
{
	switch(status_TempRegler.read_access_.STATE)
	{
	case warmAus:
		if (wirdLeer())
		{
			printf("       TRANSITION '5 UnterT' TempRegler.normal: STATE warmAus -> kaltAus  [5b8ecd16-2fd9-11e2-a23a-331776341c66]\n");
			status_TempRegler.write_access_.STATE = kaltAus;
			{
				struct tTRACE_CHANGE_KesselUnit elements[2];
				fTRACE_APPEND_CHANGE_KesselUnit(&elements[0], 5, 1, 1);
				fTRACE_APPEND_CHANGE_KesselUnit(&elements[1], 5, 1, 8);
				TRACE_KesselUnit.CHANGE_(2, elements);
			}
		}
		else
		{
			printf("       TRANSITION '4 UnterT' TempRegler.normal: STATE warmAus -> kaltEin  [5b8ecd12-2fd9-11e2-a23a-331776341c66]\n");
			status_TempRegler.write_access_.STATE = kaltEin;
			{
				struct tTRACE_CHANGE_KesselUnit elements[2];
				fTRACE_APPEND_CHANGE_KesselUnit(&elements[0], 5, 1, 2);
				fTRACE_APPEND_CHANGE_KesselUnit(&elements[1], 5, 1, 9);
				TRACE_KesselUnit.CHANGE_(2, elements);
			}
			CHNOUT_mKesselUnit.message_.CHAN_Act_TempRegler.name_ = C6_HeizEin;
			OUT_KesselUnit.C6_HeizEin ();
		}
		break;
	default:
		return;
	}
	return;
}
		
int fPULSE_TempRegler (enum eOUTPLS_KesselUnit name_)
{
	switch(name_)
	{
		/* INPULSE startTR */
	case O4_startTR:		/* PULSE CAST from PROCESS Kessel */
		switch(status_TempRegler.read_access_.STATE)
		{
		case kaltAus:
			printf("       TRANSITION '1 startTR' TempRegler.normal: STATE kaltAus -> kaltEin  [5b8ecd0a-2fd9-11e2-a23a-331776341c66]\n");
			status_TempRegler.write_access_.STATE = kaltEin;
			{
				struct tTRACE_CHANGE_KesselUnit elements[2];
				fTRACE_APPEND_CHANGE_KesselUnit(&elements[0], 5, 1, 2);
				fTRACE_APPEND_CHANGE_KesselUnit(&elements[1], 5, 1, 4);
				TRACE_KesselUnit.CHANGE_(2, elements);
			}
			CHNOUT_mKesselUnit.message_.CHAN_Act_TempRegler.name_ = C6_HeizEin;
			OUT_KesselUnit.C6_HeizEin ();
			break;
		default:
			break;
		}
		break;
		/* INPULSE stopTR */
	case O4_stopTR:		/* PULSE CAST from PROCESS Kessel */
		switch(status_TempRegler.read_access_.STATE)
		{
		case kaltEin:
			printf("       TRANSITION '6 stopTR' TempRegler.normal: STATE kaltEin -> kaltAus  [5b8ecd1a-2fd9-11e2-a23a-331776341c66]\n");
			status_TempRegler.write_access_.STATE = kaltAus;
			{
				struct tTRACE_CHANGE_KesselUnit elements[2];
				fTRACE_APPEND_CHANGE_KesselUnit(&elements[0], 5, 1, 1);
				fTRACE_APPEND_CHANGE_KesselUnit(&elements[1], 5, 1, 7);
				TRACE_KesselUnit.CHANGE_(2, elements);
			}
			CHNOUT_mKesselUnit.message_.CHAN_Act_TempRegler.name_ = C6_HeizAus;
			OUT_KesselUnit.C6_HeizAus ();
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

void fDUMP_TempRegler(void)
{
	struct tTRACE_DUMP_KesselUnit element;
	int state =  status_TempRegler.read_access_.STATE;
	fTRACE_APPEND_DUMP_KesselUnit(&element, 5, 1, normal, state, state);
	TRACE_KesselUnit.DUMP_(&element);
}

/* Process Initialization Function */

void fINIT_TempRegler (void)
{
	status_TempRegler.write_access_.MODE = normal;
	status_TempRegler.write_access_.STATE = kaltAus;
}		

/*********************************************************************
	End of Module for PROCESS TempRegler
*********************************************************************/
/* Actifsource ID=[e9267837-2596-11e1-ae2f-a14f3e396de6,304ffac5-2fda-11e2-a23a-331776341c66,5b61a23d-2fd9-11e2-a23a-331776341c66,21741d8a-2fda-11e2-a23a-331776341c66,305244b9-2fda-11e2-a23a-331776341c66,5b6fd36a-2fd9-11e2-a23a-331776341c66,5b8c82f4-2fd9-11e2-a23a-331776341c66,sSzmEnKpHmL8RTVICsAN9pCq6gI=] */
