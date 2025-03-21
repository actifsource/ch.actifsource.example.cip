/*********************************************************************
  SYSTEM LampSystem
  IMPLEMENTATION LampImpl_c
  Error Header File for CIP MACHINE mLampUnit
  Filename: mainLampSystem_TestSuite_Console.h
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


#ifndef _MAIN_H
#define _MAIN_H

/* === INCLUDE FILES =============================================================== */
#include "sLampUnit.h"
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

/* Actifsource ID=[146c2b3d-30d5-11e7-a447-9b7f17a8ec30,6fa016b4-f5a7-11ee-8944-afc67c286a4c,IawGBuZ5IG9ttNdgKeKxe6Y3Bvw=] */
