/*********************************************************************
  SYSTEM Kesselsteuerung_Loesung
  IMPLEMENTATION implementation
  Error Header File for CIP MACHINE mKesselUnit
  Filename: mainKesselsteuerung_Loesung_TestSuite_Console.h
  generated by CIP Tool(R)
  
  activated code options:
  	C code
  	use message interface
  		naming option: use default prefix
  	use postfix
  		KesselUnit 
  	enable mode inspection
  	'unsigned long' for delays
*********************************************************************/


#ifndef _MAIN_H
#define _MAIN_H

/* === INCLUDE FILES =============================================================== */
#include "sKesselUnit.h"
#include "animation/AnimationSocket.h"

/* === TYPEs =============================================================== */
/** Enum to specify the animation mode. */
typedef enum EAnimationMode
{
  eAnimationMode_Undefined,
  eAnimationMode_Manual,
  eAnimationMode_Regressive,
  eAnimationMode_Visual,
  eAnimationMode_Runner
} T_EAnimationMode;

/**
 * Returns the current animation connection
 */
t_ConnectionContext* Main_getConnectionContext(void);

/**
 * Returns the current animation mode.
 */
T_EAnimationMode Main_getAnimationMode(void);

#endif // _MAIN_H

/* Actifsource ID=[146c2b3d-30d5-11e7-a447-9b7f17a8ec30,4ae31ce4-2fda-11e2-a23a-331776341c66,qFU+ss/pjUaQh+8sizJNu9pT2UE=] */