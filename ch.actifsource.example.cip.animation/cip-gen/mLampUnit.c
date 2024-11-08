/*********************************************************************
	SYSTEM LampSystem
	IMPLEMENTATION LampImpl_c
	Module for CIP MACHINE mLampUnit
	Filename: mLampUnit.c
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

/* External Declarations */

void fICHAN_ButtonEvents_HANS (enum eMSG_ButtonEvents_HANS name_);
void fINIT_Button_HANS (void);
void fINIT_Lamp_HANS (void);
void fDUMP_Button_HANS (void);
void fDUMP_Lamp_HANS (void);

/* Global Declarations */

unsigned long time_LampUnit_HANS = 0;
struct tCHNOUT_mLampUnit_HANS CHNOUT_mLampUnit_HANS;
struct tTIMING_mLampUnit TIMING_mLampUnit_HANS;
struct tTMQE_mLampUnit_HANS *tuhead_mLampUnit_HANS, *tutail_mLampUnit_HANS;

/* Function Prototypes */

void fSETTIM_mLampUnit_HANS (unsigned long *delay_, struct tTMEL_mLampUnit_HANS *timer_, struct tTMQE_mLampUnit_HANS *timeup_);
void fSTOPTIM_mLampUnit_HANS (struct tTMEL_mLampUnit_HANS *timer_, struct tTMQE_mLampUnit_HANS *timeup_);
void fSTEP_LampUnit_HANS(void);
void fCHAIN_LampUnit_HANS(void);
void fTIMEUP_LampUnit_HANS(void);
void fREAD_LampUnit_HANS(void);

/* AUTO_ Handler Function */

static void fAUTOHDL_LampUnit_HANS(void)
{
		/* dummy function handling no AUTO_ */
}

/* Timer Functions */

static void fTICK_LampUnit_HANS(void)
{
	++time_LampUnit_HANS;
	if (TIMING_mLampUnit_HANS.set_)
	{
		TIMING_mLampUnit_HANS.tkhndl_();
	}
}

void fSETTIM_mLampUnit_HANS (unsigned long *delay_, struct tTMEL_mLampUnit_HANS *timer_, struct tTMQE_mLampUnit_HANS *timeup_)
{
	if (*delay_ > 0)
	{
		if (!timer_->set_)
		{
			++TIMING_mLampUnit_HANS.set_;
		}
		timer_->set_ = TRUE;
		timer_->end_ = time_LampUnit_HANS + *delay_;
		if (tuhead_mLampUnit_HANS == timeup_)
		{
			tuhead_mLampUnit_HANS = tuhead_mLampUnit_HANS->next_;
		}
		if (timeup_->preced_)
		{
			timeup_->preced_->next_ = timeup_->next_;
		}
		if (timeup_->next_)
		{
			timeup_->next_->preced_ = timeup_->preced_;
		}
		if (tutail_mLampUnit_HANS == timeup_)
		{
			tutail_mLampUnit_HANS = timeup_->preced_;
		}
		timeup_->preced_ = 0;
		timeup_->next_ = 0;
	}
	else 
	{
		if (timer_->set_)
		{
			--TIMING_mLampUnit_HANS.set_;
		}
		timer_->set_ = FALSE;
		if (tuhead_mLampUnit_HANS != timeup_ && ! timeup_->preced_ && ! timeup_->next_)
		{
			if (!tuhead_mLampUnit_HANS)
			{
				tuhead_mLampUnit_HANS = tutail_mLampUnit_HANS = timeup_;
			}
			else 
			{
				tutail_mLampUnit_HANS->next_ = timeup_;
				timeup_->preced_ = tutail_mLampUnit_HANS;
				tutail_mLampUnit_HANS = timeup_;
			}
		}
	}
}

void fSTOPTIM_mLampUnit_HANS (struct tTMEL_mLampUnit_HANS *timer_, struct tTMQE_mLampUnit_HANS *timeup_)
{
	if (timer_->set_)
	{
		--TIMING_mLampUnit_HANS.set_;
	}
	timer_->set_ = FALSE;
	if (tuhead_mLampUnit_HANS == timeup_)
	{
		tuhead_mLampUnit_HANS = tuhead_mLampUnit_HANS->next_;
	}
	if (timeup_->preced_)
	{
		timeup_->preced_->next_ = timeup_->next_;
	}
	if (timeup_->next_)
	{
		timeup_->next_->preced_ = timeup_->preced_;
	}
	if (tutail_mLampUnit_HANS == timeup_)
	{
		tutail_mLampUnit_HANS = timeup_->preced_;
	}
	timeup_->preced_ = 0;
	timeup_->next_ = 0;
}

/* Control Functions */

	/* Step Function for CIP Machine */

void fSTEP_LampUnit_HANS(void)
{
	if (tuhead_mLampUnit_HANS != 0)
	{
		TIMING_mLampUnit_HANS.tuhndl_();
	}
	return;
}

	/* Chain Function for CIP Machine */

void fCHAIN_LampUnit_HANS(void)
{
	return;
}

	/* Timeup Function for CIP Machine */

void fTIMEUP_LampUnit_HANS(void)
{
	if (tuhead_mLampUnit_HANS != 0)
	{
		TIMING_mLampUnit_HANS.tuhndl_();
	}
	return;
}

	/* Read Function for CIP Machine */

void fREAD_LampUnit_HANS(void)
{
	return;
}


/* Initialization Function */

int fDUMP_LampUnit_HANS(void)
{
	fDUMP_Button_HANS();
	fDUMP_Lamp_HANS();
 	return 1;
}

/* Initialization Function */

int fINIT_LampUnit_HANS(void)
{
	tuhead_mLampUnit_HANS = tutail_mLampUnit_HANS = 0;
	TRG_LampUnit_HANS.TICK_ = fTICK_LampUnit_HANS;
	TRG_LampUnit_HANS.CHAIN_ = fCHAIN_LampUnit_HANS;
	TRG_LampUnit_HANS.TIMEUP_ = fTIMEUP_LampUnit_HANS;
	TRG_LampUnit_HANS.STEP_ = fSTEP_LampUnit_HANS;
	TRG_LampUnit_HANS.READ_ = fREAD_LampUnit_HANS;
	TRG_LampUnit_HANS.AUTO_ = fAUTOHDL_LampUnit_HANS;
	IN_LampUnit_HANS.ButtonEvents = fICHAN_ButtonEvents_HANS;
	iCHAN_LampUnit_HANS();
	if (!OUT_LampUnit_HANS.LampActions)
	{
		return 0;
	}
	iTRACE_LampUnit_HANS();
	if (!TRACE_LampUnit_HANS.DUMP_)
	{
		return 0;
	}
	if (!TRACE_LampUnit_HANS.CHANGE_)
	{
		return 0;
	}
	fINIT_Button_HANS ();
	fINIT_Lamp_HANS ();
	return 1;
}

/*********************************************************************
	End of Module for CIP MACHINE mLampUnit
*********************************************************************/

/* Actifsource ID=[a9fcef86-9d17-11e1-90e4-e1fd5739c0f6,6f9fef7b-f5a7-11ee-8944-afc67c286a4c,6f9fc82e-f5a7-11ee-8944-afc67c286a4c,6f9fef98-f5a7-11ee-8944-afc67c286a4c,6f9fef7a-f5a7-11ee-8944-afc67c286a4c,6f9fef79-f5a7-11ee-8944-afc67c286a4c,LlVu+kFTK8qc1y04CuAf0GtnDTQ=] */
