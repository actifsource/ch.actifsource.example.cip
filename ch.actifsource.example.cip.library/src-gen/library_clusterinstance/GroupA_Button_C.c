/*******************************************************************
        SYSTEM ClusterGroup_System_Library
        Module for PROCESS GroupA_Button_C
        Filename: GroupA_Button_C.c
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
#define SELF status_GroupA_Button_C_HANS.write_access_
#define STATUS (pStatus_GroupA_Button_C_HANS->read_access_)
#define TIME time_LampUnit_HANS
#define fUPDM3_GroupA_Lamp_C() status_GroupA_Lamp_C_HANS.write_access_.MODE = \
 	MODTAB_GroupA_Lamp_C_HANS[status_GroupA_Button_C_HANS.read_access_.STATE - 1] \
 	[status_GroupA_Button_A_B_C2_HANS.read_access_.STATE - 1] \
 	[status_GroupA_Lamp_A_C_HANS.read_access_.STATE - 1]
#define typeGate() TRTAB_typeGate \
	[status_GroupA_Button_A_B_C1_HANS.read_access_.STATE - 1] != 0

/* Process Enumerations */

enum eMODES_GroupA_Button_C
	{normal = 1};

enum eSTATES_GroupA_Button_C
	{pushed = 1, released};


/* External Declarations */

extern unsigned long time_LampUnit_HANS;
extern struct tCHNOUT_mLampUnit_HANS CHNOUT_mLampUnit_HANS;
extern union tSTATUS_GroupA_Button_A_B_C1_HANS status_GroupA_Button_A_B_C1_HANS;
extern union tSTATUS_GroupA_Button_A_B_C2_HANS status_GroupA_Button_A_B_C2_HANS;
extern union tSTATUS_GroupA_Lamp_A_C_HANS status_GroupA_Lamp_A_C_HANS;
extern union tSTATUS_GroupA_Lamp_C_HANS status_GroupA_Lamp_C_HANS;
extern const int MODTAB_GroupA_Lamp_C_HANS[2][2][3];
int fPULSE_GroupA_Lamp_C_HANS (enum eOUTPLS_LampUnit_HANS name_);
int fPULSE_GroupA_Lamp_A_B_C2_HANS (enum eOUTPLS_LampUnit_HANS name_);

/* Global Declarations */

union tSTATUS_GroupA_Button_C_HANS status_GroupA_Button_C_HANS;
const union tSTATUS_GroupA_Button_C_HANS *pStatus_GroupA_Button_C_HANS = &status_GroupA_Button_C_HANS;
const static unsigned char TRTAB_typeGate[2] =      /* [GroupA_Button_A_B_C1 states] */
	{1, 1};


/* Function Prototypes */

void fICHAN_ButtonEvents3_HANS (enum eMSG_ButtonEvents3_HANS name_);
void fINIT_GroupA_Button_C_HANS (void);

/* Input Channel Functions */

void fICHAN_ButtonEvents3_HANS(enum eMSG_ButtonEvents3_HANS name_)
{
	switch(name_)
	{
		/* MESSAGE Push of INPORT EVENT_PORT */
	case C4_Push:
		switch(status_GroupA_Button_C_HANS.read_access_.STATE)
		{
		case released:
		 	status_GroupA_Button_C_HANS.write_access_.STATE = pushed;
		 	fUPDM3_GroupA_Lamp_C();
		 	fPULSE_GroupA_Lamp_C_HANS (O4_on);
		 	fPULSE_GroupA_Lamp_A_B_C2_HANS (O4_on);
			break;
		default:
			return;
		}		
		break;
		/* MESSAGE Release of INPORT EVENT_PORT */
	case C4_Release:
		switch(status_GroupA_Button_C_HANS.read_access_.STATE)
		{
		case pushed:
		 	status_GroupA_Button_C_HANS.write_access_.STATE = released;
		 	fUPDM3_GroupA_Lamp_C();
		 	fPULSE_GroupA_Lamp_C_HANS (O4_off);
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

void fINIT_GroupA_Button_C_HANS (void)
{
	status_GroupA_Button_C_HANS.write_access_.MODE = normal;
	status_GroupA_Button_C_HANS.write_access_.STATE = released;
}		

/*********************************************************************
	End of Module for PROCESS GroupA_Button_C
*********************************************************************/
/* Actifsource ID=[e9267837-2596-11e1-ae2f-a14f3e396de6,8417413c-b789-11ea-9e22-1112d6355503,841740f2-b789-11ea-9e22-1112d6355503,841741d7-b789-11ea-9e22-1112d6355503,8417413a-b789-11ea-9e22-1112d6355503,841741bd-b789-11ea-9e22-1112d6355503,8414cf35-b789-11ea-9e22-1112d6355503,x2SQsOsEtWAA1p2fRgsWL1UiOrY=] */
