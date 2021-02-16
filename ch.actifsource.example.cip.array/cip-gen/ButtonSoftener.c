/*******************************************************************
        SYSTEM ChairArray
        Module for PROCESS ButtonSoftener
        Filename: ButtonSoftener.c
        generated by CIP Tool(R)

        activated code options:
        	C code
        	use channel interface
        		naming option: use default prefix
        	'unsigned long' for delays
*********************************************************************/

/* Include Files */

#include "mChairUnit.h"

/* Process Macro Definitions */

#define EXCEPTION return;
#define ID (*id_)
#define SELF (*self_)
#define STATUS (pStatus_ButtonSoftener->read_access_)
#define TIME time_

/* Process Enumerations */

enum eMODES_ButtonSoftener
	{normal = 1};

enum eSTATES_ButtonSoftener
	{pushed = 1, released};


/* External Declarations */

extern unsigned long time_;
extern struct tCHNOUT_mChairUnit CHNOUT_mChairUnit;
int fPULSE_PassengersControl (enum eOUTPLS_ name_,
  struct tID_PassengersControl *procid_);

/* Global Declarations */

union tSTATUS_ButtonSoftener status_ButtonSoftener;
const union tSTATUS_ButtonSoftener *pStatus_ButtonSoftener = &status_ButtonSoftener;
static struct tPRSTAT_ButtonSoftener *self_;
static struct tID_ButtonSoftener currentid_;
static const struct tID_ButtonSoftener *id_ = &currentid_;

/* Function Prototypes */

void fICHAN_Evt_ButtonSofter (enum eMSG_Evt_ButtonSofter name_,
   struct tID_Evt_ButtonSofter *chanid_);
void fINIT_ButtonSoftener (void);

/* Multiple Cast Functions */

static void fCAST_PassengersControl(enum eOUTPLS_ name_,
   struct tID_ButtonSoftener *txid_)
{
	struct tID_PassengersControl ID_PassengersControl;
	ID_PassengersControl.cushionIndex = txid_->cushionIndex;
	switch(name_)
	{	
	case O5_push:
	case O5_release:
		fPULSE_PassengersControl(name_, &ID_PassengersControl);
		break;
	default: 
		break;
	}
}	
/* Input Channel Functions */

void fICHAN_Evt_ButtonSofter(enum eMSG_Evt_ButtonSofter name_,
   struct tID_Evt_ButtonSofter *chanid_)
{
	struct tID_ButtonSoftener ID_ButtonSoftener;
	int invalid_index_;
	if ((invalid_index_ = chanid_->cushionIndex) < 0 || chanid_->cushionIndex >= CUSHION_COUNT )
	{
		return;
	}
	currentid_.cushionIndex = chanid_->cushionIndex;
	ID_ButtonSoftener.cushionIndex = chanid_->cushionIndex;
	self_ = &status_ButtonSoftener.write_access_[currentid_.cushionIndex];
	switch(name_)
	{
		/* MESSAGE Push of INPORT ButtonSofter */
	case C4_Push:
		switch(status_ButtonSoftener.read_access_[currentid_.cushionIndex].STATE)
		{
		case released:
		 	status_ButtonSoftener.write_access_[currentid_.cushionIndex].STATE = pushed;
		 	fCAST_PassengersControl (O5_push, &ID_ButtonSoftener);
			break;
		default:
			return;
		}		
		break;
		/* MESSAGE Release of INPORT ButtonSofter */
	case C4_Release:
		switch(status_ButtonSoftener.read_access_[currentid_.cushionIndex].STATE)
		{
		case pushed:
		 	status_ButtonSoftener.write_access_[currentid_.cushionIndex].STATE = released;
		 	fCAST_PassengersControl (O5_release, &ID_ButtonSoftener);
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
		
/* Process Initialization Function */

void fINIT_ButtonSoftener (void)
{
	int LOCAL_cushionIndex;
	for (LOCAL_cushionIndex = 0; LOCAL_cushionIndex < CUSHION_COUNT; LOCAL_cushionIndex++)
	{
		status_ButtonSoftener.write_access_[LOCAL_cushionIndex].STATE = released;
	}
}		

/*********************************************************************
	End of Module for PROCESS ButtonSoftener
*********************************************************************/
/* Actifsource ID=[e9267837-2596-11e1-ae2f-a14f3e396de6,2e7be38b-c77a-11ea-9e9f-c1d3048691bc,2e797237-c77a-11ea-9e9f-c1d3048691bc,2e7be3c2-c77a-11ea-9e9f-c1d3048691bc,2e7be389-c77a-11ea-9e9f-c1d3048691bc,2e7be388-c77a-11ea-9e9f-c1d3048691bc,2e797292-c77a-11ea-9e9f-c1d3048691bc,YISMT40dUZ/HrJxOwLHrwPErK6I=] */