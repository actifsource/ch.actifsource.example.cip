/*********************************************************************
	SYSTEM Kesselsteuerung
	IMPLEMENTATION Kessel
	Header File for CIP MACHINE mKesselUnit
	Filename: mKesselUnit.h
	generated by CIP Tool(R)
	
	activated code options:
		C code
		use message interface
			naming option: use default prefix
		use postfix
			KesselUnit 
		'unsigned char' for delays
*********************************************************************/

#if !defined(_mKesselUnit_hKesselUnit_)
	#define _mKesselUnit_hKesselUnit_

/* Include Files */

#include <stdlib.h>
#include "sKesselUnit.h"

/* Macro Definitions */

#if !defined(FALSE)
	#define FALSE 0
#endif // FALSE

#if !defined(TRUE)
	#define TRUE 1
#endif // TRUE

/* Global Output Type */

struct tCHAN_Act_Kessel
{
	enum eMSG_Act_Kessel name_;
};

struct tCHAN_Act_TempRegler
{
	enum eMSG_Act_TempRegler name_;
};

union tCHAN_mKesselUnit
{
	struct tCHAN_Act_Kessel CHAN_Act_Kessel;
	struct tCHAN_Act_TempRegler CHAN_Act_TempRegler;
};

struct tCHNOUT_mKesselUnit
{
	union tCHAN_mKesselUnit message_;
};

/* Types for Process Kessel */

struct tPRSTAT_Kessel
{
	int STATE;
};

union tSTATUS_Kessel
{
	struct tPRSTAT_Kessel write_access_;
	struct tPRSTAT_Kessel read_access_;
};

/* Types for Process Schalter */

struct tPRSTAT_Schalter
{
	int STATE;
};

union tSTATUS_Schalter
{
	struct tPRSTAT_Schalter write_access_;
	struct tPRSTAT_Schalter read_access_;
};

/* Types for Process TempRegler */

struct tPRSTAT_TempRegler
{
	int STATE;
};

union tSTATUS_TempRegler
{
	struct tPRSTAT_TempRegler write_access_;
	struct tPRSTAT_TempRegler read_access_;
};

#endif // _mKesselUnit_hKesselUnit_

/*********************************************************************
	End of Header File for CIP MACHINE mKesselUnit
*********************************************************************/
/* Actifsource ID=[79d4b5d7-259a-11e1-ae2f-a14f3e396de6,c511814e-37d0-11e2-9d61-05c638030bc3,4bc43bb6-2fdf-11e2-a23a-331776341c66,cb79ac2d-37d0-11e2-9d61-05c638030bc3,c5166357-37d0-11e2-9d61-05c638030bc3,c5166352-37d0-11e2-9d61-05c638030bc3,u9Nvf8+U0injD7QaCMs3C/qiY3g=] */