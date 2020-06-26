/*
 * MessageHandler.h
 *
 *  Created on: 14.04.2017
 *      Author: ruti
 */

#ifndef _MESSAGE_HANDLER_H
#define _MESSAGE_HANDLER_H

/* === INCLUDE FILES =============================================================== */
#include <stdio.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/* === INCLUDE FILES =============================================================== */
#include "Type.h"
#include "JsonUtil.h"

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendResponse
 -----------------------------------------------------------------------------------
 Description    : send any message to the socket

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendResponse(t_ConnectionContext* connection, const char *message);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendLogInfoResponse
 -----------------------------------------------------------------------------------
 Description    : Send log info to the socket 
                  {\"log\":[{\"time\":16666, \"st\": 2,\"msg\":\"Test Message\"}]}

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendLogInfoResponse(t_ConnectionContext* connection, const char *log);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendLogWarningResponse
 -----------------------------------------------------------------------------------
 Description    : Send log warning to the socket  
                  {\"log\":[{\"time\":16666, \"st\": 1,\"msg\":\"Test Message\"}]}

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendLogWarningResponse(t_ConnectionContext* connection, const char *log);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendTestbenchLogResponse
 -----------------------------------------------------------------------------------
 Description    : Send test bench response to the socket 

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendTestbenchLogResponse(t_ConnectionContext* connection, const char *log);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendCompleteResponse
 -----------------------------------------------------------------------------------
 Description    : Send complete response to the socket

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendCompleteResponse(t_ConnectionContext* connection);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendErrorResponse
 -----------------------------------------------------------------------------------
 Description    : Send error response to the socket 

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendErrorResponse(t_ConnectionContext* connection, const char *error);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendElement
 -----------------------------------------------------------------------------------
 Description    : Send element state to the socket
                  {\"elm\":[{\"id\":[4,2,3,1],\"st\":1,\"seq\":220}]}

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendElement(t_ConnectionContext* connection, unsigned int processId, unsigned int multiplicityIndex, int modeState, int sequenceNumber);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_getBindId
 -----------------------------------------------------------------------------------
 Description    : Read bind id from tokens

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_getBindId(t_TokensContext* tokenContext, t_JsonId* jsonId);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_isResetRequest
 -----------------------------------------------------------------------------------
 Description    : Check if the next request is a reset request

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_isResetRequest(t_TokensContext* tokenContext);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_getTestBenchEventId
 -----------------------------------------------------------------------------------
 Description    : returns the event id from the json tokens

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_getTestBenchEventId(t_TokensContext* tokenContext, t_JsonId* jsonId);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendStartTypeHistory
 -----------------------------------------------------------------------------------
 Description    : Send start type history to the socket

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendStartTypeHistory(t_ConnectionContext* connection, t_JsonId *modulId);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendStartTypeSnapshot
 -----------------------------------------------------------------------------------
 Description    : Send start type snapshot to the socket

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendStartTypeSnapshot(t_ConnectionContext* connection, t_JsonId *modulId);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendStartTypeUpdate
 -----------------------------------------------------------------------------------
 Description    : Send start type update to the socket

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendStartTypeUpdate(t_ConnectionContext* connection, t_JsonId *modulId);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendTestbenchAction
 -----------------------------------------------------------------------------------
 Description    : Send action to the socket

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendTestbenchAction(t_ConnectionContext* connection, int actionId, char *value, char *index);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendRequiredInput
 -----------------------------------------------------------------------------------
 Description    : Send required input to the socket

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendRequiredInput(t_ConnectionContext* connection, int inputId);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_hasValue
 -----------------------------------------------------------------------------------
 Description    : check if the next token is a value token.

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_hasValue(t_TokensContext* tokenContext);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_hasIndex
 -----------------------------------------------------------------------------------
 Description    : check if the next token is a index token.

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_hasIndex(t_TokensContext* tokenContext);

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_getConnectionData
 -----------------------------------------------------------------------------------
 Description    : extract the connection data from the connection context 

 Parameters     : -

 Return values  : -return the connection data.
 ----------------------------------------------------------------------------------- */
t_ConnectionData* MessageHandler_getConnectionData(t_ConnectionContext* connection);


#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _MESSAGE_HANDLER_H

/* Actifsource ID=[a1af57d5-030d-11e6-b47b-f140d082a724,4ae31ce4-2fda-11e2-a23a-331776341c66,304ffac5-2fda-11e2-a23a-331776341c66,Hash] */
