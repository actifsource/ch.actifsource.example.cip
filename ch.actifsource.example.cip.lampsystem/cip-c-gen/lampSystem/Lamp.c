/*******************************************************************
        SYSTEM LampSystem
        Module for PROCESS Lamp
        Filename: Lamp.c
        generated by CIP Tool(R)

        activated code options:
        	C code
        	use channel interface
        		naming option: use default prefix
        	use postfix
        		 LampUnit_HANS
        	enable mode inspection
        	'unsigned long' for delays
*********************************************************************/

/* Include Files */

#include "mLampUnit.h"

/* Process Macro Definitions */

#define SELF status_Lamp_HANS.write_access_
#define STATUS (pStatus_Lamp_HANS->read_access_)
#define TIME time_LampUnit_HANS

/* Process Enumerations */

enum eMODES_Lamp
	{normal = 1};

enum eSTATES_Lamp
	{delayed = 1, off_, on_};

enum eINPULS_Lamp
	{IP_off = 1, IP_on, TIMEUP_};
	

/* External Declarations */

extern unsigned long time_LampUnit_HANS;
extern struct tTMQE_mLampUnit_HANS *tuhead_mLampUnit_HANS, *tutail_mLampUnit_HANS;
extern struct tCHNOUT_mLampUnit_HANS CHNOUT_mLampUnit_HANS;
extern struct tTIMING_mLampUnit TIMING_mLampUnit_HANS;
void fSETTIM_mLampUnit_HANS (unsigned long *delay_, struct tTMEL_mLampUnit_HANS *timer_, struct tTMQE_mLampUnit_HANS *timeup_);
void fSTOPTIM_mLampUnit_HANS (struct tTMEL_mLampUnit_HANS *timer_, struct tTMQE_mLampUnit_HANS *timeup_);

/* Global Declarations */

static unsigned long delay_;
struct tPRINST_Lamp_HANS IO_Lamp_HANS;
union tSTATUS_Lamp_HANS status_Lamp_HANS;
const union tSTATUS_Lamp_HANS *pStatus_Lamp_HANS = &status_Lamp_HANS;

/* Function Prototypes */

int fPULSE_Lamp_HANS (enum eOUTPLS_LampUnit_HANS name_);
void fINIT_Lamp_HANS (void);

/* Input Channel Functions */

int fPULSE_Lamp_HANS (enum eOUTPLS_LampUnit_HANS name_)
{
	switch(name_)
	{
		/* INPULSE off */
	case O2_off:		/* PULSE CAST from PROCESS Button */
		switch(status_Lamp_HANS.read_access_.STATE)
		{
		case on_:
			{
				printf("       TRANSITION '2 off' Lamp.normal: STATE on_ -> delayed  [7848c6ef-b785-11ea-9e22-1112d6355503]\n");
				delay_ =  3;	/* DELAY DELAY_OPERATION */
				status_Lamp_HANS.write_access_.STATE = delayed;
				fSETTIM_mLampUnit_HANS(&delay_, 
					&IO_Lamp_HANS.timer_, 
					&IO_Lamp_HANS.timeup_);
			}
			break;
		default:
			break;
		}
		break;
		/* INPULSE on */
	case O2_on:		/* PULSE CAST from PROCESS Button */
		switch(status_Lamp_HANS.read_access_.STATE)
		{
		case delayed:
			{
				printf("       TRANSITION '3 on' Lamp.normal: STATE delayed -> on_  [7848c6f2-b785-11ea-9e22-1112d6355503]\n");
				delay_ =  3;	/* DELAY DELAY_OPERATION */
				status_Lamp_HANS.write_access_.STATE = on_;
				fSETTIM_mLampUnit_HANS(&delay_, 
					&IO_Lamp_HANS.timer_, 
					&IO_Lamp_HANS.timeup_);
			}
			break;
		case off_:
			printf("       TRANSITION '1 on' Lamp.normal: STATE off_ -> on_  [7848c6ec-b785-11ea-9e22-1112d6355503]\n");
			status_Lamp_HANS.write_access_.STATE = on_;
			CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions.name_ = C2_Bright;
			OUT_LampUnit_HANS.LampActions(CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions.name_);
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

/* Timer Functions */

static void fTICK_Lamp_HANS (void)
{
	if (IO_Lamp_HANS.timer_.set_ &&
		IO_Lamp_HANS.timer_.end_ == time_LampUnit_HANS)
	{
		IO_Lamp_HANS.timer_.set_ = FALSE;
		--TIMING_mLampUnit_HANS.set_;
		if (tuhead_mLampUnit_HANS != &IO_Lamp_HANS.timeup_ &&
			!IO_Lamp_HANS.timeup_.preced_ &&
			!IO_Lamp_HANS.timeup_.next_)
		{
			if (!tuhead_mLampUnit_HANS)
			{
				tuhead_mLampUnit_HANS = tutail_mLampUnit_HANS = &IO_Lamp_HANS.timeup_;
			}
			else
			{
				tutail_mLampUnit_HANS->next_ = &IO_Lamp_HANS.timeup_;
				IO_Lamp_HANS.timeup_.preced_ = tutail_mLampUnit_HANS;
				tutail_mLampUnit_HANS = &IO_Lamp_HANS.timeup_;
			}
		}
	}			
}

static void fTUHNDL_Lamp(void)
{
	struct tTMQE_mLampUnit_HANS *element_ = tuhead_mLampUnit_HANS;
	if (tuhead_mLampUnit_HANS == tutail_mLampUnit_HANS)
	{
		tuhead_mLampUnit_HANS = tutail_mLampUnit_HANS = 0;
	}
	else 
	{
		tuhead_mLampUnit_HANS = element_->next_;
		element_->next_ = 0;
		tuhead_mLampUnit_HANS->preced_ = 0;
	}
	switch(status_Lamp_HANS.read_access_.STATE)
	{
	case delayed:
		printf("       TRANSITION '4 TIMEUP_' Lamp.normal: STATE delayed -> off_  [7848c6f3-b785-11ea-9e22-1112d6355503]\n");
		status_Lamp_HANS.write_access_.STATE = off_;
		CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions.name_ = C2_Dark;
		OUT_LampUnit_HANS.LampActions(CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions.name_);
		break;
	default:
		break;
	}
}

/* Process Initialization Function */

void fINIT_Lamp_HANS (void)
{
	status_Lamp_HANS.write_access_.MODE = normal;
	status_Lamp_HANS.write_access_.STATE = off_;
	IO_Lamp_HANS.timer_.set_ = FALSE;
	IO_Lamp_HANS.timeup_.preced_ = 0;
	IO_Lamp_HANS.timeup_.next_ = 0;
	IO_Lamp_HANS.timeup_.proctype_ = 0;
	TIMING_mLampUnit_HANS.tkhndl_ = fTICK_Lamp_HANS;
	TIMING_mLampUnit_HANS.tuhndl_ = fTUHNDL_Lamp;
}		

/*********************************************************************
	End of Module for PROCESS Lamp
*********************************************************************/
/* Actifsource ID=[e9267837-2596-11e1-ae2f-a14f3e396de6,7848c712-b785-11ea-9e22-1112d6355503,7848c6d5-b785-11ea-9e22-1112d6355503,7848c72b-b785-11ea-9e22-1112d6355503,7848c710-b785-11ea-9e22-1112d6355503,7848c70f-b785-11ea-9e22-1112d6355503,7848c705-b785-11ea-9e22-1112d6355503,F2FznNvsYozgG8Qg9tGwDf8jf0g=] */
