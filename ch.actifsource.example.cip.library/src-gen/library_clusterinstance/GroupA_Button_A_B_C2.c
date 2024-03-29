/*******************************************************************
        SYSTEM ClusterGroup_System_Library
        Module for PROCESS GroupA_Button_A_B_C2
        Filename: GroupA_Button_A_B_C2.c
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
#define SELF status_GroupA_Button_A_B_C2_HANS.write_access_
#define STATUS (pStatus_GroupA_Button_A_B_C2_HANS->read_access_)
#define TIME time_LampUnit_HANS
#define fUPDM1_GroupA_Lamp_A_B_C1() status_GroupA_Lamp_A_B_C1_HANS.write_access_.MODE = \
 	MODTAB_GroupA_Lamp_A_B_C1_HANS[status_GroupA_Button_A_B_C1_HANS.read_access_.STATE - 1] \
 	[status_GroupA_Button_A_B_C2_HANS.read_access_.STATE - 1]
#define fUPDM1_GroupA_Lamp_A_B_C2() status_GroupA_Lamp_A_B_C2_HANS.write_access_.MODE = \
 	MODTAB_GroupA_Lamp_A_B_C2_HANS[status_GroupA_Button_A_B_C2_HANS.read_access_.STATE - 1]
#define fUPDM2_GroupA_Lamp_C() status_GroupA_Lamp_C_HANS.write_access_.MODE = \
 	MODTAB_GroupA_Lamp_C_HANS[status_GroupA_Button_C_HANS.read_access_.STATE - 1] \
 	[status_GroupA_Button_A_B_C2_HANS.read_access_.STATE - 1] \
 	[status_GroupA_Lamp_A_C_HANS.read_access_.STATE - 1]
#define ButtonGate() TRTAB_ButtonGate \
	[status_GroupA_Lamp_C_HANS.read_access_.STATE - 1] != 0

/* Process Enumerations */

enum eMODES_GroupA_Button_A_B_C2
	{normal = 1};

enum eSTATES_GroupA_Button_A_B_C2
	{pushed = 1, released};


/* External Declarations */

extern unsigned long time_LampUnit_HANS;
extern struct tCHNOUT_mLampUnit_HANS CHNOUT_mLampUnit_HANS;
extern struct tPRACS_GroupA_Lamp_A_B_C1_HANS GroupA_Lamp_A_B_C1_HANS;
extern struct tPRACS_GroupA_Lamp_A_C_HANS GroupA_Lamp_A_C_HANS;
extern union tSTATUS_GroupA_Button_A_B_C1_HANS status_GroupA_Button_A_B_C1_HANS;
extern union tSTATUS_GroupA_Button_C_HANS status_GroupA_Button_C_HANS;
extern union tSTATUS_GroupA_Lamp_A_B_C1_HANS status_GroupA_Lamp_A_B_C1_HANS;
extern union tSTATUS_GroupA_Lamp_A_B_C2_HANS status_GroupA_Lamp_A_B_C2_HANS;
extern union tSTATUS_GroupA_Lamp_A_C_HANS status_GroupA_Lamp_A_C_HANS;
extern union tSTATUS_GroupA_Lamp_C_HANS status_GroupA_Lamp_C_HANS;
extern const int MODTAB_GroupA_Lamp_A_B_C1_HANS[2][2];
extern const int MODTAB_GroupA_Lamp_A_B_C2_HANS[2];
extern const int MODTAB_GroupA_Lamp_C_HANS[2][2][3];
int fPULSE_GroupA_Lamp_A_C_HANS (enum eOUTPLS_LampUnit_HANS name_);
int fPULSE_GroupA_Lamp_C_HANS (enum eOUTPLS_LampUnit_HANS name_);
int fPULSE_GroupA_Lamp_A_B_C2_HANS (enum eOUTPLS_LampUnit_HANS name_);

/* Global Declarations */

union tSTATUS_GroupA_Button_A_B_C2_HANS status_GroupA_Button_A_B_C2_HANS;
const union tSTATUS_GroupA_Button_A_B_C2_HANS *pStatus_GroupA_Button_A_B_C2_HANS = &status_GroupA_Button_A_B_C2_HANS;
const static unsigned char TRTAB_ButtonGate[3] =      /* [GroupA_Lamp_C states] */
	{1, 0, 0};


/* Function Prototypes */

void fICHAN_ButtonEvents4_HANS (enum eMSG_ButtonEvents4_HANS name_);
void fINIT_GroupA_Button_A_B_C2_HANS (void);

/* Input Channel Functions */

void fICHAN_ButtonEvents4_HANS(enum eMSG_ButtonEvents4_HANS name_)
{
	switch(name_)
	{
		/* MESSAGE Push of INPORT EVENT_PORT */
	case C8_Push:
		switch(status_GroupA_Button_A_B_C2_HANS.read_access_.STATE)
		{
		case released:
		 	status_GroupA_Button_A_B_C2_HANS.write_access_.STATE = pushed;
		 	fUPDM2_GroupA_Lamp_C();
		 	fUPDM1_GroupA_Lamp_A_B_C1();
		 	fUPDM1_GroupA_Lamp_A_B_C2();
		 	fPULSE_GroupA_Lamp_A_C_HANS (O10_on);
		 	fPULSE_GroupA_Lamp_A_B_C2_HANS (O10_on);
			break;
		default:
			return;
		}		
		break;
		/* MESSAGE Release of INPORT EVENT_PORT */
	case C8_Release:
		switch(status_GroupA_Button_A_B_C2_HANS.read_access_.STATE)
		{
		case pushed:
		 	status_GroupA_Button_A_B_C2_HANS.write_access_.STATE = released;
		 	fUPDM2_GroupA_Lamp_C();
		 	fUPDM1_GroupA_Lamp_A_B_C1();
		 	fUPDM1_GroupA_Lamp_A_B_C2();
		 	fPULSE_GroupA_Lamp_C_HANS (O10_off);
		 	fPULSE_GroupA_Lamp_A_B_C2_HANS (O10_off);
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

void fINIT_GroupA_Button_A_B_C2_HANS (void)
{
	status_GroupA_Button_A_B_C2_HANS.write_access_.MODE = normal;
	status_GroupA_Button_A_B_C2_HANS.write_access_.STATE = released;
}		

/*********************************************************************
	End of Module for PROCESS GroupA_Button_A_B_C2
*********************************************************************/
/* Actifsource ID=[e9267837-2596-11e1-ae2f-a14f3e396de6,8417413c-b789-11ea-9e22-1112d6355503,841740f2-b789-11ea-9e22-1112d6355503,841741d7-b789-11ea-9e22-1112d6355503,8417413a-b789-11ea-9e22-1112d6355503,841741bd-b789-11ea-9e22-1112d6355503,8417405e-b789-11ea-9e22-1112d6355503,mzi15gSSM/6ZLIOKWQXmMQgwokY=] */
