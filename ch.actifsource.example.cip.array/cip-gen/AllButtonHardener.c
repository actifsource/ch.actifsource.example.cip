/*******************************************************************
        SYSTEM ChairArray
        Module for PROCESS AllButtonHardener
        Filename: AllButtonHardener.c
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
#define SELF status_AllButtonHardener.write_access_
#define STATUS (pStatus_AllButtonHardener->read_access_)
#define TIME time_

/* Process Enumerations */

enum eMODES_AllButtonHardener
	{normal = 1};

enum eSTATES_AllButtonHardener
	{pushed = 1, released};

enum eINPULS_AllButtonHardener
	{TIMEUP_ = 1, CHAIN_ = 2};
	

/* External Declarations */

extern unsigned long time_;
extern struct tTMQE_mChairUnit *tuhead_mChairUnit, *tutail_mChairUnit, *chhead_mChairUnit, *chtail_mChairUnit;
extern struct tCHNOUT_mChairUnit CHNOUT_mChairUnit;
extern struct tTIMING_mChairUnit TIMING_mChairUnit[2];
extern struct tCHNING_mChairUnit CHNING_mChairUnit;
int fPULSE_PassengersControl (enum eOUTPLS_ name_,
  struct tID_PassengersControl *procid_);
void fSETTIM_mChairUnit (unsigned long *delay_, struct tTMEL_mChairUnit *timer_, struct tTMQE_mChairUnit *timeup_);
void fSTOPTIM_mChairUnit (struct tTMEL_mChairUnit *timer_, struct tTMQE_mChairUnit *timeup_);
void fSETCHN_mChairUnit (struct tTMQE_mChairUnit *chain_);

/* Global Declarations */

static unsigned long delay_;
struct tPRINST_AllButtonHardener IO_AllButtonHardener;
union tSTATUS_AllButtonHardener status_AllButtonHardener;
const union tSTATUS_AllButtonHardener *pStatus_AllButtonHardener = &status_AllButtonHardener;

/* Function Prototypes */

static void testFunction(void);

void fICHAN_Evt_AllButtonHardener (enum eMSG_Evt_AllButtonHardener name_);
void fINIT_AllButtonHardener (void);

/* User Functions */

static void testFunction(void)
{
	SELF.MODE;
}
			
/* Multiple Cast Functions */

static void fCAST_PassengersControl(enum eOUTPLS_ name_)
{
	struct tID_PassengersControl ID_PassengersControl;
	switch(name_)
	{	
	case O11_push:
	case O11_released:
		for (ID_PassengersControl.cushionIndex = 0; ID_PassengersControl.cushionIndex < CUSHION_COUNT; ID_PassengersControl.cushionIndex++)
		{
			fPULSE_PassengersControl(name_, &ID_PassengersControl);
		}
		break;
	default: 
		break;
	}
}	
/* Input Channel Functions */

void fICHAN_Evt_AllButtonHardener(enum eMSG_Evt_AllButtonHardener name_)
{
	switch(name_)
	{
		/* MESSAGE Push of INPORT AllButtonHarder */
	case C6_Push:
		switch(status_AllButtonHardener.read_access_.STATE)
		{
		case released:
		 	status_AllButtonHardener.write_access_.STATE = pushed;
		 	fSETCHN_mChairUnit(&IO_AllButtonHardener.chain_);
		 	fSTOPTIM_mChairUnit(&IO_AllButtonHardener.timer_, 
		 		&IO_AllButtonHardener.timeup_);
		 	fCAST_PassengersControl (O11_push);
			break;
		default:
			return;
		}		
		break;
		/* MESSAGE Release of INPORT AllButtonHarder */
	case C6_Release:
		switch(status_AllButtonHardener.read_access_.STATE)
		{
		case pushed:
		 	status_AllButtonHardener.write_access_.STATE = released;
		 	fCAST_PassengersControl (O11_released);
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
		
/* Timer Functions */

static void fTICK_AllButtonHardener (void)
{
	if (IO_AllButtonHardener.timer_.set_ &&
		IO_AllButtonHardener.timer_.end_ == time_)
	{
		IO_AllButtonHardener.timer_.set_ = FALSE;
		--TIMING_mChairUnit[0].set_;
		if (tuhead_mChairUnit != &IO_AllButtonHardener.timeup_ &&
			!IO_AllButtonHardener.timeup_.preced_ &&
			!IO_AllButtonHardener.timeup_.next_)
		{
			if (!tuhead_mChairUnit)
			{
				tuhead_mChairUnit = tutail_mChairUnit = &IO_AllButtonHardener.timeup_;
			}
			else
			{
				tutail_mChairUnit->next_ = &IO_AllButtonHardener.timeup_;
				IO_AllButtonHardener.timeup_.preced_ = tutail_mChairUnit;
				tutail_mChairUnit = &IO_AllButtonHardener.timeup_;
			}
		}
	}			
}

static void fTUHNDL_AllButtonHardener(void)
{
	struct tTMQE_mChairUnit *element_ = tuhead_mChairUnit;
	if (tuhead_mChairUnit == tutail_mChairUnit)
	{
		tuhead_mChairUnit = tutail_mChairUnit = 0;
	}
	else 
	{
		tuhead_mChairUnit = element_->next_;
		element_->next_ = 0;
		tuhead_mChairUnit->preced_ = 0;
	}
}

static void fCHHNDL_AllButtonHardener(void)
{
	struct tTMQE_mChairUnit *element_ = chhead_mChairUnit;
	if (chhead_mChairUnit == chtail_mChairUnit)
	{
		chhead_mChairUnit = chtail_mChairUnit = 0;
	}
	else 
	{
		chhead_mChairUnit = element_->next_;
		element_->next_ = 0;
		chhead_mChairUnit->preced_ = 0;
	}
}

/* Process Initialization Function */

void fINIT_AllButtonHardener (void)
{
	status_AllButtonHardener.write_access_.STATE = released;
	IO_AllButtonHardener.timer_.set_ = FALSE;
	IO_AllButtonHardener.timeup_.preced_ = 0;
	IO_AllButtonHardener.timeup_.next_ = 0;
	IO_AllButtonHardener.timeup_.proctype_ = 0;
	IO_AllButtonHardener.chain_.preced_ = 0;
	IO_AllButtonHardener.chain_.next_ = 0;
	IO_AllButtonHardener.chain_.proctype_ = 0;
	TIMING_mChairUnit[0].tkhndl_ = fTICK_AllButtonHardener;
	TIMING_mChairUnit[0].tuhndl_ = fTUHNDL_AllButtonHardener;
	CHNING_mChairUnit.chhndl_ = fCHHNDL_AllButtonHardener;
}		

/*********************************************************************
	End of Module for PROCESS AllButtonHardener
*********************************************************************/
/* Actifsource ID=[e9267837-2596-11e1-ae2f-a14f3e396de6,2e7be38b-c77a-11ea-9e9f-c1d3048691bc,2e797237-c77a-11ea-9e9f-c1d3048691bc,2e7be3c2-c77a-11ea-9e9f-c1d3048691bc,2e7be389-c77a-11ea-9e9f-c1d3048691bc,2e7be388-c77a-11ea-9e9f-c1d3048691bc,2e797257-c77a-11ea-9e9f-c1d3048691bc,YD56BghpSFuHu/0l3WanOROIFig=] */
