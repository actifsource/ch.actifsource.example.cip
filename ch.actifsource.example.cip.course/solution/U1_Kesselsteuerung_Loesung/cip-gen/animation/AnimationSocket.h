/*
 * AnimationSocket.h
 *
 *  Created on: 14.04.2017
 *      Author: ruti
 */


#ifndef _ANIMATION_SOCKET_H
#define _ANIMATION_SOCKET_H

/* === INCLUDE FILES =============================================================== */
#include <stdio.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/* === INCLUDE FILES =============================================================== */
#include "Type.h"

/* === DEFINES ===================================================================== */
/* Begin Protected Region [[define]] */
#define SERVER_PORT 11111
/* End Protected Region   [[define]] */

/* === TYPES ======================================================================= */
typedef struct
{
	Boolean  connected;
	int      clientfd;
	void     *userData;     // Placeholder for connection-specific data
} t_ConnectionContext;


/* ---------------------------------------------------------------------------------
 Function       : AnimationSocket_Start
 -----------------------------------------------------------------------------------
 Description    : Start the socket on SERVER_PORT

 Parameters     : - 

 Return values  : -true if the server is running.
 ----------------------------------------------------------------------------------- */
Boolean AnimationSocket_Start(void);

/* ---------------------------------------------------------------------------------
 Function       : AnimationSocket_AcceptClient
 -----------------------------------------------------------------------------------
 Description    : accept client connection from animation server.

 Parameters     : - t_ConnectionContext connection context data

 Return values  : -true success
 ----------------------------------------------------------------------------------- */
Boolean AnimationSocket_AcceptClient(t_ConnectionContext* connection);

/* ---------------------------------------------------------------------------------
 Function       : AnimationSocket_Read
 -----------------------------------------------------------------------------------
 Description    : Read data from socket.

 Parameters     : - t_ConnectionContext connection context data

 Return values  : --true success
 ----------------------------------------------------------------------------------- */
Boolean AnimationSocket_Read(t_ConnectionContext* connection, char* buffer);

/* ---------------------------------------------------------------------------------
 Function       : AnimationSocket_Write
 -----------------------------------------------------------------------------------
 Description    : Write data to socket.

 Parameters     : - t_ConnectionContext connection context data

 Return values  : --true success
 ----------------------------------------------------------------------------------- */
Boolean AnimationSocket_Write(t_ConnectionContext* connection, const char* sendBuffer);

/* ---------------------------------------------------------------------------------
 Function       : AnimationSocket_Close
 -----------------------------------------------------------------------------------
 Description    : Close the socket connection.

 Parameters     : - t_ConnectionContext connection context data

 Return values  : -
 ----------------------------------------------------------------------------------- */
Boolean AnimationSocket_Close(t_ConnectionContext* connection);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _ANIMATION_SOCKET_H

/* Actifsource ID=[2baec1d4-030d-11e6-b47b-f140d082a724,4ae31ce4-2fda-11e2-a23a-331776341c66,304ffac5-2fda-11e2-a23a-331776341c66,Hash] */
