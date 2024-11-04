/*******************************************************************
        SYSTEM ClusterGroup_System_Library
        Module for PROCESS GroupB_Lamp_C
        Filename: GroupB_Lamp_C.c
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

#define SELF status_GroupB_Lamp_C_HANS.write_access_
#define STATUS (pStatus_GroupB_Lamp_C_HANS->read_access_)
#define TIME time_LampUnit_HANS
#define lampTypeGate() TRTAB_lampTypeGate \
	[status_GroupB_Lamp_A_C_HANS.read_access_.STATE - 1] != 0
#define lampTypeGate2() TRTAB_lampTypeGate2 \
	[status_GroupB_Lamp_A_B_C2_HANS.read_access_.STATE - 1] != 0

/* Process Enumerations */

enum eMODES_GroupB_Lamp_C
	{normal = 1, normal2 = 2};

enum eSTATES_GroupB_Lamp_C
	{delayed = 1, off_, on_};

enum eINPULS_GroupB_Lamp_C
	{IP_off = 1, IP_on, TIMEUP_};
	

/* External Declarations */

extern unsigned long time_LampUnit_HANS;
extern struct tTMQE_mLampUnit_HANS *tuhead_mLampUnit_HANS, *tutail_mLampUnit_HANS;
extern struct tCHNOUT_mLampUnit_HANS CHNOUT_mLampUnit_HANS;
extern struct tTIMING_mLampUnit TIMING_mLampUnit_HANS[9];
extern union tSTATUS_GroupB_Button_A_B_C2_HANS status_GroupB_Button_A_B_C2_HANS;
extern union tSTATUS_GroupB_Button_C_HANS status_GroupB_Button_C_HANS;
extern union tSTATUS_GroupB_Lamp_A_B_C2_HANS status_GroupB_Lamp_A_B_C2_HANS;
extern union tSTATUS_GroupB_Lamp_A_C_HANS status_GroupB_Lamp_A_C_HANS;
void fSETTIM_mLampUnit_HANS (unsigned long *delay_, struct tTMEL_mLampUnit_HANS *timer_, struct tTMQE_mLampUnit_HANS *timeup_);
void fSTOPTIM_mLampUnit_HANS (struct tTMEL_mLampUnit_HANS *timer_, struct tTMQE_mLampUnit_HANS *timeup_);

/* Global Declarations */

static unsigned long delay_;
struct tPRINST_GroupB_Lamp_C_HANS IO_GroupB_Lamp_C_HANS;
union tSTATUS_GroupB_Lamp_C_HANS status_GroupB_Lamp_C_HANS;
const union tSTATUS_GroupB_Lamp_C_HANS *pStatus_GroupB_Lamp_C_HANS = &status_GroupB_Lamp_C_HANS;
const int MODTAB_GroupB_Lamp_C_HANS[2][2][3] =       /* [GroupB_Button_C states][GroupB_Button_A_B_C2 states][GroupB_Lamp_A_C states] */
	{{{normal2, normal, normal2},
	{normal2, normal, normal2}},
	{{normal2, normal, normal2},
	{normal2, normal, normal2}}};

const static unsigned char TRTAB_lampTypeGate[3] =      /* [GroupB_Lamp_A_C states] */
	{1, 1, 0};

const static unsigned char TRTAB_lampTypeGate2[3] =      /* [GroupB_Lamp_A_B_C2 states] */
	{1, 0, 0};


/* Function Prototypes */

int fPULSE_GroupB_Lamp_C_HANS (enum eOUTPLS_LampUnit_HANS name_);
void fINIT_GroupB_Lamp_C_HANS (void);

/* Input Channel Functions */

int fPULSE_GroupB_Lamp_C_HANS (enum eOUTPLS_LampUnit_HANS name_)
{
	switch(name_)
	{
		/* INPULSE off */
	case O13_off:		/* PULSE CAST from PROCESS GroupB_Button_C */
		switch(MODTAB_GroupB_Lamp_C_HANS[status_GroupB_Button_C_HANS.read_access_.STATE - 1]
		[status_GroupB_Button_A_B_C2_HANS.read_access_.STATE - 1]
		[status_GroupB_Lamp_A_C_HANS.read_access_.STATE - 1])
		{
		case normal:
			switch(status_GroupB_Lamp_C_HANS.read_access_.STATE)
			{
			case on_:
				{
					delay_ =  3;	/* DELAY DELAY_OPERATION */
					status_GroupB_Lamp_C_HANS.write_access_.STATE = delayed;
					fSETTIM_mLampUnit_HANS(&delay_, 
						&IO_GroupB_Lamp_C_HANS.timer_, 
						&IO_GroupB_Lamp_C_HANS.timeup_);
				}
				break;
			default:
				break;
			}
			break;
		case normal2:
			switch(status_GroupB_Lamp_C_HANS.read_access_.STATE)
			{
			case on_:
				{
					delay_ =  3;	/* DELAY DELAY_OPERATION */
					status_GroupB_Lamp_C_HANS.write_access_.STATE = delayed;
					fSETTIM_mLampUnit_HANS(&delay_, 
						&IO_GroupB_Lamp_C_HANS.timer_, 
						&IO_GroupB_Lamp_C_HANS.timeup_);
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
	case O19_off:		/* PULSE CAST from PROCESS GroupB_Button_A_B_C2 */
	case O13_on:		/* PULSE CAST from PROCESS GroupB_Button_C */
		switch(MODTAB_GroupB_Lamp_C_HANS[status_GroupB_Button_C_HANS.read_access_.STATE - 1]
		[status_GroupB_Button_A_B_C2_HANS.read_access_.STATE - 1]
		[status_GroupB_Lamp_A_C_HANS.read_access_.STATE - 1])
		{
		case normal:
			switch(status_GroupB_Lamp_C_HANS.read_access_.STATE)
			{
			case delayed:
				{
					delay_ =  3;	/* DELAY DELAY_OPERATION */
					status_GroupB_Lamp_C_HANS.write_access_.STATE = on_;
					fSETTIM_mLampUnit_HANS(&delay_, 
						&IO_GroupB_Lamp_C_HANS.timer_, 
						&IO_GroupB_Lamp_C_HANS.timeup_);
				}
				break;
			case off_:
				status_GroupB_Lamp_C_HANS.write_access_.STATE = on_;
				CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions5.name_ = C9_Bright;
				OUT_LampUnit_HANS.LampActions5(CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions5.name_);
				break;
			default:
				break;
			}
			break;
		case normal2:
			switch(status_GroupB_Lamp_C_HANS.read_access_.STATE)
			{
			case delayed:
				{
					delay_ =  3;	/* DELAY DELAY_OPERATION */
					status_GroupB_Lamp_C_HANS.write_access_.STATE = on_;
					fSETTIM_mLampUnit_HANS(&delay_, 
						&IO_GroupB_Lamp_C_HANS.timer_, 
						&IO_GroupB_Lamp_C_HANS.timeup_);
				}
				break;
			case off_:
				status_GroupB_Lamp_C_HANS.write_access_.STATE = on_;
				CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions5.name_ = C9_Bright;
				OUT_LampUnit_HANS.LampActions5(CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions5.name_);
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

static void fTICK_GroupB_Lamp_C_HANS (void)
{
	if (IO_GroupB_Lamp_C_HANS.timer_.set_ &&
		IO_GroupB_Lamp_C_HANS.timer_.end_ == time_LampUnit_HANS)
	{
		IO_GroupB_Lamp_C_HANS.timer_.set_ = FALSE;
		--TIMING_mLampUnit_HANS[6].set_;
		if (tuhead_mLampUnit_HANS != &IO_GroupB_Lamp_C_HANS.timeup_ &&
			!IO_GroupB_Lamp_C_HANS.timeup_.preced_ &&
			!IO_GroupB_Lamp_C_HANS.timeup_.next_)
		{
			if (!tuhead_mLampUnit_HANS)
			{
				tuhead_mLampUnit_HANS = tutail_mLampUnit_HANS = &IO_GroupB_Lamp_C_HANS.timeup_;
			}
			else
			{
				tutail_mLampUnit_HANS->next_ = &IO_GroupB_Lamp_C_HANS.timeup_;
				IO_GroupB_Lamp_C_HANS.timeup_.preced_ = tutail_mLampUnit_HANS;
				tutail_mLampUnit_HANS = &IO_GroupB_Lamp_C_HANS.timeup_;
			}
		}
	}			
}

static void fTUHNDL_GroupB_Lamp_C(void)
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
	switch(MODTAB_GroupB_Lamp_C_HANS[status_GroupB_Button_C_HANS.read_access_.STATE - 1]
	[status_GroupB_Button_A_B_C2_HANS.read_access_.STATE - 1]
	[status_GroupB_Lamp_A_C_HANS.read_access_.STATE - 1])
	{
	case normal:
		switch(status_GroupB_Lamp_C_HANS.read_access_.STATE)
		{
		case delayed:
			status_GroupB_Lamp_C_HANS.write_access_.STATE = off_;
			CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions5.name_ = C9_Dark;
			OUT_LampUnit_HANS.LampActions5(CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions5.name_);
			break;
		default:
			break;
		}
		break;
	case normal2:
		switch(status_GroupB_Lamp_C_HANS.read_access_.STATE)
		{
		case delayed:
			status_GroupB_Lamp_C_HANS.write_access_.STATE = off_;
			CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions5.name_ = C9_Dark;
			OUT_LampUnit_HANS.LampActions5(CHNOUT_mLampUnit_HANS.message_.CHAN_LampActions5.name_);
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

void fINIT_GroupB_Lamp_C_HANS (void)
{
	status_GroupB_Lamp_C_HANS.write_access_.MODE = normal;
	status_GroupB_Lamp_C_HANS.write_access_.STATE = off_;
	IO_GroupB_Lamp_C_HANS.timer_.set_ = FALSE;
	IO_GroupB_Lamp_C_HANS.timeup_.preced_ = 0;
	IO_GroupB_Lamp_C_HANS.timeup_.next_ = 0;
	IO_GroupB_Lamp_C_HANS.timeup_.proctype_ = 6;
	TIMING_mLampUnit_HANS[6].tkhndl_ = fTICK_GroupB_Lamp_C_HANS;
	TIMING_mLampUnit_HANS[6].tuhndl_ = fTUHNDL_GroupB_Lamp_C;
}		

/*********************************************************************
	End of Module for PROCESS GroupB_Lamp_C
*********************************************************************/
/* Actifsource ID=[e9267837-2596-11e1-ae2f-a14f3e396de6,8417413c-b789-11ea-9e22-1112d6355503,841740f2-b789-11ea-9e22-1112d6355503,841741d7-b789-11ea-9e22-1112d6355503,8417413a-b789-11ea-9e22-1112d6355503,841741d6-b789-11ea-9e22-1112d6355503,8414cf67-b789-11ea-9e22-1112d6355503,+CyFpw7qytdpiAnUS3HNb5yOdh4=] */
