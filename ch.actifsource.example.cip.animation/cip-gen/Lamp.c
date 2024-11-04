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
#include "tLampUnit.h"

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
void fDUMP_Lamp_HANS (void);

/* Trace Function Prototypes */


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
				printf("       TRANSITION '2 off' Lamp.normal: STATE on_ -> delayed  [6f9fc848-f5a7-11ee-8944-afc67c286a4c]\n");
				delay_ =  3;	/* DELAY DELAY_OPERATION */
				status_Lamp_HANS.write_access_.STATE = delayed;
				{
					struct tTRACE_CHANGE_LampUnit_HANS elements[2];
					fTRACE_APPEND_CHANGE_LampUnit_HANS(&elements[0], 1, 1, 1);
					fTRACE_APPEND_CHANGE_LampUnit_HANS(&elements[1], 1, 1, 5);
					TRACE_LampUnit_HANS.CHANGE_(2, elements);
				}
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
				printf("       TRANSITION '3 on' Lamp.normal: STATE delayed -> on_  [6f9fc84b-f5a7-11ee-8944-afc67c286a4c]\n");
				delay_ =  3;	/* DELAY DELAY_OPERATION */
				status_Lamp_HANS.write_access_.STATE = on_;
				{
					struct tTRACE_CHANGE_LampUnit_HANS elements[2];
					fTRACE_APPEND_CHANGE_LampUnit_HANS(&elements[0], 1, 1, 3);
					fTRACE_APPEND_CHANGE_LampUnit_HANS(&elements[1], 1, 1, 6);
					TRACE_LampUnit_HANS.CHANGE_(2, elements);
				}
				fSETTIM_mLampUnit_HANS(&delay_, 
					&IO_Lamp_HANS.timer_, 
					&IO_Lamp_HANS.timeup_);
			}
			break;
		case off_:
			printf("       TRANSITION '1 on' Lamp.normal: STATE off_ -> on_  [6f9fc845-f5a7-11ee-8944-afc67c286a4c]\n");
			status_Lamp_HANS.write_access_.STATE = on_;
			{
				struct tTRACE_CHANGE_LampUnit_HANS elements[2];
				fTRACE_APPEND_CHANGE_LampUnit_HANS(&elements[0], 1, 1, 3);
				fTRACE_APPEND_CHANGE_LampUnit_HANS(&elements[1], 1, 1, 4);
				TRACE_LampUnit_HANS.CHANGE_(2, elements);
			}
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
		printf("       TRANSITION '4 TIMEUP_' Lamp.normal: STATE delayed -> off_  [6f9fc84c-f5a7-11ee-8944-afc67c286a4c]\n");
		status_Lamp_HANS.write_access_.STATE = off_;
		{
			struct tTRACE_CHANGE_LampUnit_HANS elements[2];
			fTRACE_APPEND_CHANGE_LampUnit_HANS(&elements[0], 1, 1, 2);
			fTRACE_APPEND_CHANGE_LampUnit_HANS(&elements[1], 1, 1, 7);
			TRACE_LampUnit_HANS.CHANGE_(2, elements);
		}
		CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions.name_ = C2_Dark;
		OUT_LampUnit_HANS.LampActions(CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions.name_);
		break;
	default:
		break;
	}
}

/* Process Dump Function */

void fDUMP_Lamp_HANS(void)
{
	struct tTRACE_DUMP_LampUnit_HANS element;
	int state =  status_Lamp_HANS.read_access_.STATE;
	fTRACE_APPEND_DUMP_LampUnit_HANS(&element, 1, 1, normal, state, state);
	TRACE_LampUnit_HANS.DUMP_(&element);
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
/* Actifsource ID=[e9267837-2596-11e1-ae2f-a14f3e396de6,6f9fef7b-f5a7-11ee-8944-afc67c286a4c,6f9fc82e-f5a7-11ee-8944-afc67c286a4c,6f9fef98-f5a7-11ee-8944-afc67c286a4c,6f9fef79-f5a7-11ee-8944-afc67c286a4c,6f9fef78-f5a7-11ee-8944-afc67c286a4c,6f9fef6e-f5a7-11ee-8944-afc67c286a4c,8tMTvb2gszuUiga+6iqPT/tWKl0=] */
