/*********************************************************************
	SYSTEM Kesselsteuerung
	IMPLEMENTATION Kessel
	Header File for CIP SHELL sKesselUnit
	Filename: sKesselUnit.h
	generated by CIP Tool(R)
	
	activated code options:
		C code
		use message interface
			naming option: use default prefix
		use postfix
			KesselUnit 
		'unsigned char' for delays
*********************************************************************/

#if !defined(_sKesselUnit_hKesselUnit_)
	#define _sKesselUnit_hKesselUnit_
/* Code Option Constants */

#if defined(_EINPUT__)
	#undef _EINPUT__
#endif 

#if defined(_PENDING__)
	#undef _PENDING__
#endif 

/* Channel Enumerations */

#if !defined(_eCHAN_KesselUnit_)
	#define _eCHAN_KesselUnit_

	enum eCHAN_KesselUnit
		{C_Act_Kessel = 4, C_Act_TempRegler = 6, C_Evt_HauptSchalter = 2, 
		 C_Evt_Kessel = 3, C_Evt_TempRegler = 5};

#endif // _eCHAN_KesselUnit_

/*********************************************************************
	CODE  GENERATION  FEATURE
	This global message enumeration can be used 
	for implementation purposes.
*********************************************************************/

enum eMSG_KesselUnitKesselUnit
	{F_C2_KesselAus_ = 1, F_C2_KesselEin_ = 2, F_C3_UeberN1_ = 3, F_C3_UeberN2_ = 4, 
	 F_C3_UnterN1_ = 5, F_C3_UnterN2_ = 6, F_C5_UeberT_ = 7, F_C5_UnterT_ = 8, 
	 F_C4_Fuellen_ = 9, F_C4_Leeren_ = 10, F_C6_HeizAus_ = 11, F_C6_HeizEin_ = 12};

/********************************************************************/

#if !defined(_eMSG_Evt_HauptSchalter_)
	#define _eMSG_Evt_HauptSchalter_

	enum eMSG_Evt_HauptSchalter
		{C2_KesselAus = 2, C2_KesselEin = 1};

#endif // _eMSG_Evt_HauptSchalter_

#if !defined(_eMSG_Evt_Kessel_)
	#define _eMSG_Evt_Kessel_

	enum eMSG_Evt_Kessel
		{C3_UeberN1 = 2, C3_UeberN2 = 4, C3_UnterN1 = 1, C3_UnterN2 = 3};

#endif // _eMSG_Evt_Kessel_

#if !defined(_eMSG_Act_Kessel_)
	#define _eMSG_Act_Kessel_

	enum eMSG_Act_Kessel
		{C4_Fuellen = 1, C4_Leeren = 3};

#endif // _eMSG_Act_Kessel_

#if !defined(_eMSG_Evt_TempRegler_)
	#define _eMSG_Evt_TempRegler_

	enum eMSG_Evt_TempRegler
		{C5_UeberT = 2, C5_UnterT = 1};

#endif // _eMSG_Evt_TempRegler_

#if !defined(_eMSG_Act_TempRegler_)
	#define _eMSG_Act_TempRegler_

	enum eMSG_Act_TempRegler
		{C6_HeizAus = 1, C6_HeizEin = 2};

#endif // _eMSG_Act_TempRegler_

/* Input Interface Type */

struct tIN_KesselUnit
{
	void (*C2_KesselAus)(void);
	void (*C2_KesselEin)(void);
	void (*C3_UeberN1)(void);
	void (*C3_UeberN2)(void);
	void (*C3_UnterN1)(void);
	void (*C3_UnterN2)(void);
	void (*C5_UeberT)(void);
	void (*C5_UnterT)(void);
};

/* Output Interface Type */

struct tOUT_KesselUnit
{
	void (*C4_Fuellen)(void);
	void (*C4_Leeren)(void);
	void (*C6_HeizAus)(void);
	void (*C6_HeizEin)(void);
};


/* Trigger Interface Type */

struct tTRG_KesselUnit
{
	void (*TICK_) (void);		/* increment CIP MACHINE time */
	void (*STEP_) (void);		/*  trigger CIP MACHINE transition */
	void (*CHAIN_) (void);		/* trigger pending chain CIP MACHINE transition */
	void (*TIMEUP_) (void);		/* trigger pending timeup CIP MACHINE transition */
	void (*READ_) (void);		/* trigger CIP MACHINE to read from internal message buffer */
	void (*AUTO_) (void);		/* trigger pending auto CIP MACHINE transition */
};

/* External Interface Declarations */

extern struct tIN_KesselUnit IN_KesselUnit;		/* Input Channel Interface defined in sKesselUnit.c */
extern struct tOUT_KesselUnit OUT_KesselUnit;		/* Output Channel Interface defined in sKesselUnit.c */
extern struct tTRG_KesselUnit TRG_KesselUnit;		/* Trigger Interface defined in sKesselUnit.c */

/* Unit Initialization Function, defined in mKesselUnit.c
	called by User to initialize CIP Machine
		returning 1 if successful
		returning 0 if failed */

int fINIT_KesselUnit(void);

/* User defined Initialization Function for CIP Shell Interface Initialization 
	called by Unit Initialization Function */

void iMSG_KesselUnit(void);

#endif // _sKesselUnit_hKesselUnit_

/*********************************************************************
	End of CIP UNIT Header File for CIP SHELL sKesselUnit
*********************************************************************/
/* Actifsource ID=[b7934a9b-259a-11e1-ae2f-a14f3e396de6,c511814e-37d0-11e2-9d61-05c638030bc3,4bc43bb6-2fdf-11e2-a23a-331776341c66,cb79ac2d-37d0-11e2-9d61-05c638030bc3,c5166352-37d0-11e2-9d61-05c638030bc3,c5166357-37d0-11e2-9d61-05c638030bc3,M3ayegO7i/fA1grVLIKkB9cg/UE=] */
