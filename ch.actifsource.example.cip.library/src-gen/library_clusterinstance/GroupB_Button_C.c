/*******************************************************************
        SYSTEM ClusterGroup_System_Library
        Module for PROCESS GroupB_Button_C
        Filename: GroupB_Button_C.c
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

#define EXCEPTION return;
#define SELF status_GroupB_Button_C_HANS.write_access_
#define STATUS (pStatus_GroupB_Button_C_HANS->read_access_)
#define TIME time_LampUnit_HANS
#define fUPDM3_GroupB_Lamp_C() status_GroupB_Lamp_C_HANS.write_access_.MODE = \
 	MODTAB_GroupB_Lamp_C_HANS[status_GroupB_Button_C_HANS.read_access_.STATE - 1] \
 	[status_GroupB_Button_A_B_C2_HANS.read_access_.STATE - 1] \
 	[status_GroupB_Lamp_A_C_HANS.read_access_.STATE - 1]
#define typeGate() TRTAB_typeGate \
	[status_GroupB_Button_A_B_C1_HANS.read_access_.STATE - 1] != 0

/* Process Enumerations */

enum eMODES_GroupB_Button_C
	{normal = 1};

enum eSTATES_GroupB_Button_C
	{pushed = 1, released};


/* External Declarations */

extern unsigned long time_LampUnit_HANS;
extern struct tCHNOUT_mLampUnit_HANS CHNOUT_mLampUnit_HANS;
extern union tSTATUS_GroupB_Button_A_B_C1_HANS status_GroupB_Button_A_B_C1_HANS;
extern union tSTATUS_GroupB_Button_A_B_C2_HANS status_GroupB_Button_A_B_C2_HANS;
extern union tSTATUS_GroupB_Lamp_A_C_HANS status_GroupB_Lamp_A_C_HANS;
extern union tSTATUS_GroupB_Lamp_C_HANS status_GroupB_Lamp_C_HANS;
extern const int MODTAB_GroupB_Lamp_C_HANS[2][2][3];
int fPULSE_GroupB_Lamp_C_HANS (enum eOUTPLS_LampUnit_HANS name_);
int fPULSE_GroupB_Lamp_A_B_C2_HANS (enum eOUTPLS_LampUnit_HANS name_);

/* Global Declarations */

union tSTATUS_GroupB_Button_C_HANS status_GroupB_Button_C_HANS;
const union tSTATUS_GroupB_Button_C_HANS *pStatus_GroupB_Button_C_HANS = &status_GroupB_Button_C_HANS;
const static unsigned char TRTAB_typeGate[2] =      /* [GroupB_Button_A_B_C1 states] */
	{1, 1};


/* Function Prototypes */

void fICHAN_ButtonEvents8_HANS (enum eMSG_ButtonEvents8_HANS name_);
void fINIT_GroupB_Button_C_HANS (void);

/* Input Channel Functions */

void fICHAN_ButtonEvents8_HANS(enum eMSG_ButtonEvents8_HANS name_)
{
	switch(name_)
	{
		/* MESSAGE Push of INPORT EVENT_PORT */
	case C16_Push:
		switch(status_GroupB_Button_C_HANS.read_access_.STATE)
		{
		case released:
		 	status_GroupB_Button_C_HANS.write_access_.STATE = pushed;
		 	fUPDM3_GroupB_Lamp_C();
		 	fPULSE_GroupB_Lamp_C_HANS (O13_on);
		 	fPULSE_GroupB_Lamp_A_B_C2_HANS (O13_on);
			break;
		default:
			return;
		}		
		break;
		/* MESSAGE Release of INPORT EVENT_PORT */
	case C16_Release:
		switch(status_GroupB_Button_C_HANS.read_access_.STATE)
		{
		case pushed:
		 	status_GroupB_Button_C_HANS.write_access_.STATE = released;
		 	fUPDM3_GroupB_Lamp_C();
		 	fPULSE_GroupB_Lamp_C_HANS (O13_off);
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

void fINIT_GroupB_Button_C_HANS (void)
{
	status_GroupB_Button_C_HANS.write_access_.MODE = normal;
	status_GroupB_Button_C_HANS.write_access_.STATE = released;
}		

/*********************************************************************
	End of Module for PROCESS GroupB_Button_C
*********************************************************************/
/* Actifsource ID=[e9267837-2596-11e1-ae2f-a14f3e396de6,8417413c-b789-11ea-9e22-1112d6355503,841740f2-b789-11ea-9e22-1112d6355503,841741d7-b789-11ea-9e22-1112d6355503,8417413a-b789-11ea-9e22-1112d6355503,841741d6-b789-11ea-9e22-1112d6355503,8414cf35-b789-11ea-9e22-1112d6355503,+X34z8gFVwmj6SSB61w6R+sRZAg=] */
