/*******************************************************************
        SYSTEM ClusterGroup_System_Library
        Module for PROCESS GroupA_Lamp_A_B_C1
        Filename: GroupA_Lamp_A_B_C1.c
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

#define SELF status_GroupA_Lamp_A_B_C1_HANS.write_access_
#define STATUS (pStatus_GroupA_Lamp_A_B_C1_HANS->read_access_)
#define TIME time_LampUnit_HANS

/* Process Enumerations */

enum eMODES_GroupA_Lamp_A_B_C1
	{normal_1 = 1, normal_2 = 2};

enum eSTATES_GroupA_Lamp_A_B_C1
	{delayed = 1, off_, on_};

enum eINPULS_GroupA_Lamp_A_B_C1
	{IP_on = 1, IP_off = 2, TIMEUP_ = 3};
	

/* External Declarations */

extern unsigned long time_LampUnit_HANS;
extern struct tTMQE_mLampUnit_HANS *tuhead_mLampUnit_HANS, *tutail_mLampUnit_HANS;
extern struct tCHNOUT_mLampUnit_HANS CHNOUT_mLampUnit_HANS;
extern struct tTIMING_mLampUnit TIMING_mLampUnit_HANS[9];
extern union tSTATUS_GroupA_Button_A_B_C1_HANS status_GroupA_Button_A_B_C1_HANS;
extern union tSTATUS_GroupA_Button_A_B_C2_HANS status_GroupA_Button_A_B_C2_HANS;
void fSETTIM_mLampUnit_HANS (unsigned long *delay_, struct tTMEL_mLampUnit_HANS *timer_, struct tTMQE_mLampUnit_HANS *timeup_);
void fSTOPTIM_mLampUnit_HANS (struct tTMEL_mLampUnit_HANS *timer_, struct tTMQE_mLampUnit_HANS *timeup_);

/* Global Declarations */

static unsigned long delay_;
struct tPRINST_GroupA_Lamp_A_B_C1_HANS IO_GroupA_Lamp_A_B_C1_HANS;
union tSTATUS_GroupA_Lamp_A_B_C1_HANS status_GroupA_Lamp_A_B_C1_HANS;
const union tSTATUS_GroupA_Lamp_A_B_C1_HANS *pStatus_GroupA_Lamp_A_B_C1_HANS = &status_GroupA_Lamp_A_B_C1_HANS;
const int MODTAB_GroupA_Lamp_A_B_C1_HANS[2][2] =       /* [GroupA_Button_A_B_C1 states][GroupA_Button_A_B_C2 states] */
	{{normal_1, normal_1},
	{normal_1, normal_1}};


/* Function Prototypes */

int fPULSE_GroupA_Lamp_A_B_C1_HANS (enum eOUTPLS_LampUnit_HANS name_);
void fINIT_GroupA_Lamp_A_B_C1_HANS (void);

/* Input Channel Functions */

int fPULSE_GroupA_Lamp_A_B_C1_HANS (enum eOUTPLS_LampUnit_HANS name_)
{
	switch(name_)
	{
		/* INPULSE off */
	case O8_off:		/* PULSE CAST from PROCESS GroupA_Button_A_B_C1 */
	case O6_off:		/* PULSE CAST from PROCESS GroupA_Button_A_C */
		switch(MODTAB_GroupA_Lamp_A_B_C1_HANS[status_GroupA_Button_A_B_C1_HANS.read_access_.STATE - 1]
		[status_GroupA_Button_A_B_C2_HANS.read_access_.STATE - 1])
		{
		case normal_1:
			switch(status_GroupA_Lamp_A_B_C1_HANS.read_access_.STATE)
			{
			case on_:
				{
					delay_ =  3;	/* DELAY DELAY_OPERATION */
					status_GroupA_Lamp_A_B_C1_HANS.write_access_.STATE = delayed;
					fSETTIM_mLampUnit_HANS(&delay_, 
						&IO_GroupA_Lamp_A_B_C1_HANS.timer_, 
						&IO_GroupA_Lamp_A_B_C1_HANS.timeup_);
				}
				break;
			default:
				break;
			}
			break;
		case normal_2:
			switch(status_GroupA_Lamp_A_B_C1_HANS.read_access_.STATE)
			{
			case on_:
				{
					delay_ =  3;	/* DELAY DELAY_OPERATION */
					status_GroupA_Lamp_A_B_C1_HANS.write_access_.STATE = delayed;
					fSETTIM_mLampUnit_HANS(&delay_, 
						&IO_GroupA_Lamp_A_B_C1_HANS.timer_, 
						&IO_GroupA_Lamp_A_B_C1_HANS.timeup_);
				}
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
		break;
		/* INPULSE on */
	case O8_on:		/* PULSE CAST from PROCESS GroupA_Button_A_B_C1 */
		switch(MODTAB_GroupA_Lamp_A_B_C1_HANS[status_GroupA_Button_A_B_C1_HANS.read_access_.STATE - 1]
		[status_GroupA_Button_A_B_C2_HANS.read_access_.STATE - 1])
		{
		case normal_1:
			switch(status_GroupA_Lamp_A_B_C1_HANS.read_access_.STATE)
			{
			case delayed:
				{
					delay_ =  3;	/* DELAY DELAY_OPERATION */
					status_GroupA_Lamp_A_B_C1_HANS.write_access_.STATE = on_;
					fSETTIM_mLampUnit_HANS(&delay_, 
						&IO_GroupA_Lamp_A_B_C1_HANS.timer_, 
						&IO_GroupA_Lamp_A_B_C1_HANS.timeup_);
				}
				break;
			case off_:
				status_GroupA_Lamp_A_B_C1_HANS.write_access_.STATE = on_;
				CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions3.name_ = C3_Bright;
				OUT_LampUnit_HANS.LampActions3(CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions3.name_);
				break;
			default:
				break;
			}
			break;
		case normal_2:
			switch(status_GroupA_Lamp_A_B_C1_HANS.read_access_.STATE)
			{
			case delayed:
				{
					delay_ =  3;	/* DELAY DELAY_OPERATION */
					status_GroupA_Lamp_A_B_C1_HANS.write_access_.STATE = on_;
					fSETTIM_mLampUnit_HANS(&delay_, 
						&IO_GroupA_Lamp_A_B_C1_HANS.timer_, 
						&IO_GroupA_Lamp_A_B_C1_HANS.timeup_);
				}
				break;
			case off_:
				status_GroupA_Lamp_A_B_C1_HANS.write_access_.STATE = on_;
				CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions3.name_ = C3_Bright;
				OUT_LampUnit_HANS.LampActions3(CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions3.name_);
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

/* Timer Functions */

static void fTICK_GroupA_Lamp_A_B_C1_HANS (void)
{
	if (IO_GroupA_Lamp_A_B_C1_HANS.timer_.set_ &&
		IO_GroupA_Lamp_A_B_C1_HANS.timer_.end_ == time_LampUnit_HANS)
	{
		IO_GroupA_Lamp_A_B_C1_HANS.timer_.set_ = FALSE;
		--TIMING_mLampUnit_HANS[0].set_;
		if (tuhead_mLampUnit_HANS != &IO_GroupA_Lamp_A_B_C1_HANS.timeup_ &&
			!IO_GroupA_Lamp_A_B_C1_HANS.timeup_.preced_ &&
			!IO_GroupA_Lamp_A_B_C1_HANS.timeup_.next_)
		{
			if (!tuhead_mLampUnit_HANS)
			{
				tuhead_mLampUnit_HANS = tutail_mLampUnit_HANS = &IO_GroupA_Lamp_A_B_C1_HANS.timeup_;
			}
			else
			{
				tutail_mLampUnit_HANS->next_ = &IO_GroupA_Lamp_A_B_C1_HANS.timeup_;
				IO_GroupA_Lamp_A_B_C1_HANS.timeup_.preced_ = tutail_mLampUnit_HANS;
				tutail_mLampUnit_HANS = &IO_GroupA_Lamp_A_B_C1_HANS.timeup_;
			}
		}
	}			
}

static void fTUHNDL_GroupA_Lamp_A_B_C1(void)
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
	switch(MODTAB_GroupA_Lamp_A_B_C1_HANS[status_GroupA_Button_A_B_C1_HANS.read_access_.STATE - 1]
	[status_GroupA_Button_A_B_C2_HANS.read_access_.STATE - 1])
	{
	case normal_1:
		switch(status_GroupA_Lamp_A_B_C1_HANS.read_access_.STATE)
		{
		case delayed:
			status_GroupA_Lamp_A_B_C1_HANS.write_access_.STATE = off_;
			CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions3.name_ = C3_Dark;
			OUT_LampUnit_HANS.LampActions3(CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions3.name_);
			break;
		default:
			break;
		}
		break;
	case normal_2:
		switch(status_GroupA_Lamp_A_B_C1_HANS.read_access_.STATE)
		{
		case delayed:
			status_GroupA_Lamp_A_B_C1_HANS.write_access_.STATE = off_;
			CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions3.name_ = C3_Dark;
			OUT_LampUnit_HANS.LampActions3(CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions3.name_);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

/* Process Initialization Function */

void fINIT_GroupA_Lamp_A_B_C1_HANS (void)
{
	status_GroupA_Lamp_A_B_C1_HANS.write_access_.MODE = normal_1;
	status_GroupA_Lamp_A_B_C1_HANS.write_access_.STATE = off_;
	IO_GroupA_Lamp_A_B_C1_HANS.timer_.set_ = FALSE;
	IO_GroupA_Lamp_A_B_C1_HANS.timeup_.preced_ = 0;
	IO_GroupA_Lamp_A_B_C1_HANS.timeup_.next_ = 0;
	IO_GroupA_Lamp_A_B_C1_HANS.timeup_.proctype_ = 0;
	TIMING_mLampUnit_HANS[0].tkhndl_ = fTICK_GroupA_Lamp_A_B_C1_HANS;
	TIMING_mLampUnit_HANS[0].tuhndl_ = fTUHNDL_GroupA_Lamp_A_B_C1;
}		

/*********************************************************************
	End of Module for PROCESS GroupA_Lamp_A_B_C1
*********************************************************************/
/* Actifsource ID=[e9267837-2596-11e1-ae2f-a14f3e396de6,8417413c-b789-11ea-9e22-1112d6355503,841740f2-b789-11ea-9e22-1112d6355503,841741d7-b789-11ea-9e22-1112d6355503,8417413a-b789-11ea-9e22-1112d6355503,841741bd-b789-11ea-9e22-1112d6355503,84174047-b789-11ea-9e22-1112d6355503,51ril4MMKDKV+Js7ImG57Q1Ka2k=] */
