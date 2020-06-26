/*
 * MessageHandler.c
 *
 *  Created on: 14.04.2017
 *      Author: ruti
 */


/* === INCLUDE FILES =============================================================== */
#include "MessageHandler.h"
#include "AnimationSocket.h"
#include <stdio.h>

/* ---------------------------------------------------------------------------------
 Function       : consoleLog
 -----------------------------------------------------------------------------------
 Description    : log message to console.

 Parameters     : - message

 Return values  : -
 ----------------------------------------------------------------------------------- */
static void consoleLog(const char* message, const char *log)
{
	printf("%s%s \n", message, log);
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendResponse
 -----------------------------------------------------------------------------------
 Description    : send any message to the socket

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendResponse(t_ConnectionContext* connection, const char *message)
{
	if(!AnimationSocket_Write(connection, message))
	{
		consoleLog("Error: ", message);
		return False;
	}
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendLogInfoResponse
 -----------------------------------------------------------------------------------
 Description    : Send log info to the socket 
                  {\"log\":[{\"time\":16666, \"st\": 2,\"msg\":\"Test Message\"}]}

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendLogInfoResponse(t_ConnectionContext* connection, const char *log)
{
	char message[100];
	consoleLog("Log: ", log);
	JsonUtl_initStringBuffer(message);
	JsonUtl_appendString(message, "{\"log\":[{\"st\": 2,\"msg\":\"");
	JsonUtl_appendString(message, log);
	JsonUtl_appendString(message, "\"}]}");
	return MessageHandler_sendResponse(connection, message);
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendLogWarningResponse
 -----------------------------------------------------------------------------------
 Description    : Send log warning to the socket  
                  {\"log\":[{\"time\":16666, \"st\": 1,\"msg\":\"Test Message\"}]}

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendLogWarningResponse(t_ConnectionContext* connection, const char *log)
{
	char message[100];
	consoleLog("Log: ", log);
	JsonUtl_initStringBuffer(message);
	JsonUtl_appendString(message, "{\"log\":[{\"st\": 1,\"msg\":\"");
	JsonUtl_appendString(message, log);
	JsonUtl_appendString(message, "\"}]}");
	return MessageHandler_sendResponse(connection, message);
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendTestbenchLogResponse
 -----------------------------------------------------------------------------------
 Description    : Send test bench response to the socket 

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendTestbenchLogResponse(t_ConnectionContext* connection, const char *log)
{
	char message[100];
	consoleLog("Log: ", log);
	JsonUtl_initStringBuffer(message);
	JsonUtl_appendString(message, "{\"testbenchLog\":[{\"type\":\"add\",\"msg\":\"");
	JsonUtl_appendString(message, log);
	JsonUtl_appendString(message, "\"}]}");
	return MessageHandler_sendResponse(connection, message);
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendErrorResponse
 -----------------------------------------------------------------------------------
 Description    : Send error response to the socket 

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendErrorResponse(t_ConnectionContext* connection, const char *error)
{
	char message[100];
	consoleLog("Error: ", error);
	JsonUtl_initStringBuffer(message);
	JsonUtl_appendString(message, "{\"error\":[{\"nr\":1,\"msg\":\"");
	JsonUtl_appendString(message, error);
	JsonUtl_appendString(message, "\"}]}");
	return MessageHandler_sendResponse(connection, message);
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendCompleteResponse
 -----------------------------------------------------------------------------------
 Description    : Send complete response to the socket

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendCompleteResponse(t_ConnectionContext* connection)
{
	char * message = "{\"testbenchState\":\"complete\"}";
	if(!MessageHandler_sendResponse(connection, message))
	{
		return False;
	}
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendStartTypeHistory
 -----------------------------------------------------------------------------------
 Description    : Send start type history to the socket

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendStartTypeHistory(t_ConnectionContext* connection, t_JsonId *modulId)
{
	char message[100];
	JsonUtl_initStringBuffer(message);
	JsonUtl_appendString(message, "{\"elmStartType\":{\"id\":");
	JsonUtl_appendJsonId(message, modulId);
	JsonUtl_appendString(message, ",\"type\":\"history\"}}");
	consoleLog("ElmStartType: ", "history");
	return MessageHandler_sendResponse(connection, message);
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendStartTypeSnapshot
 -----------------------------------------------------------------------------------
 Description    : Send start type snapshot to the socket

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendStartTypeSnapshot(t_ConnectionContext* connection, t_JsonId *modulId)
{
	char message[100];
	JsonUtl_initStringBuffer(message);
	JsonUtl_appendString(message, "{\"elmStartType\":{\"id\":");
	JsonUtl_appendJsonId(message, modulId);
	JsonUtl_appendString(message, ",\"type\":\"snapshot\"}}");
	consoleLog("ElmStartType: ", "snapshot");
	return MessageHandler_sendResponse(connection, message);
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendStartTypeUpdate
 -----------------------------------------------------------------------------------
 Description    : Send start type update to the socket

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendStartTypeUpdate(t_ConnectionContext* connection, t_JsonId *modulId)
{
	char message[100];
	JsonUtl_initStringBuffer(message);
	JsonUtl_appendString(message, "{\"elmStartType\":{\"id\":");
	JsonUtl_appendJsonId(message, modulId);
	JsonUtl_appendString(message, ",\"type\":\"update\"}}");
	consoleLog("ElmStartType: ", "update");
	return MessageHandler_sendResponse(connection, message);
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendElement
 -----------------------------------------------------------------------------------
 Description    : Send element state to the socket
                  {\"elm\":[{\"id\":[4,2,3,1],\"st\":1,\"seq\":220}]}

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendElement(t_ConnectionContext* connection, unsigned int processId, unsigned int multiplicityIndex, int changeId, int sequenceNumber)
{
	char message[100];
	t_JsonId elementId;
	elementId.id[0] = processId;
	elementId.id[1] = multiplicityIndex;
	elementId.id[2] = changeId;
	elementId.idSize = 3;

	JsonUtl_initStringBuffer(message);
	JsonUtl_appendString(message, "{\"elm\":[{\"id\":");
	JsonUtl_appendJsonId(message, &elementId);
	JsonUtl_appendString(message, ",\"st\":1,\"seq\":");
	JsonUtl_appendInteger(message, sequenceNumber);
	JsonUtl_appendString(message, "}]}");

	consoleLog("Element: ", message);
	return MessageHandler_sendResponse(connection, message);
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendTestbenchAction
 -----------------------------------------------------------------------------------
 Description    : Send action to the socket

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendTestbenchAction(t_ConnectionContext* connection, int actionId, char *value, char *index)
{
	char message[1000];
	JsonUtl_initStringBuffer(message);
	JsonUtl_appendString(message, "{\"testbenchAction\": {\"id\":[");
	JsonUtl_appendInteger(message, actionId);
	JsonUtl_appendString(message, "]");
	if (value != NULL) 
	{
		JsonUtl_appendString(message, ",\"value\":");
		JsonUtl_appendString(message, value);
		JsonUtl_appendString(message, "");
	}
	if (index != NULL)
	{
		JsonUtl_appendString(message, ",\"index\":");
		JsonUtl_appendString(message, index);
		JsonUtl_appendString(message, "");
	} 
	JsonUtl_appendString(message, "}}");
	return MessageHandler_sendResponse(connection, message);
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_sendRequiredInput
 -----------------------------------------------------------------------------------
 Description    : Send required input to the socket

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_sendRequiredInput(t_ConnectionContext* connection, int inputId)
{
	char message[100];
	JsonUtl_initStringBuffer(message);
	JsonUtl_appendString(message, "{\"requiredInput\": {\"id\":[");
	JsonUtl_appendInteger(message, inputId);
	JsonUtl_appendString(message, "]");
	JsonUtl_appendString(message, "}}");
	return MessageHandler_sendResponse(connection, message);
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_getBindId
 -----------------------------------------------------------------------------------
 Description    : Read bind id from tokens

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_getBindId(t_TokensContext* tokenContext, t_JsonId* jsonId)
{
	jsmntok_t token;

	if (!JsonUtl_getNextToken(tokenContext, &token)) return False;
	if (!JsonUtl_isArray(token)) return False;  //[

	if (!JsonUtl_getNextToken(tokenContext, &token)) return False;
	if (!JsonUtl_isObject(token)) return False; //{

	if (!JsonUtl_getTokenJsonId(tokenContext, jsonId)) return False;
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_isResetRequest
 -----------------------------------------------------------------------------------
 Description    : Check if the next request is a reset request

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_isResetRequest(t_TokensContext* tokenContext)
{
	jsmntok_t token;
	if (!JsonUtl_getNextToken(tokenContext, &token)) return False;
	if (!JsonUtl_equalsTokenString(token, tokenContext, TOKEN_TEST_BENCH_STATE_RESET)) return False;
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_getTestBenchEventId
 -----------------------------------------------------------------------------------
 Description    : returns the event id from the json tokens

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_getTestBenchEventId(t_TokensContext* tokenContext, t_JsonId* jsonId)
{
	jsmntok_t token;
	if (!JsonUtl_getNextToken(tokenContext, &token)) return False;
	if (!JsonUtl_isObject(token)) return False;
	if (!JsonUtl_getTokenJsonId(tokenContext, jsonId)) return False;
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_hasValue
 -----------------------------------------------------------------------------------
 Description    : check if the next token is a value token.

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_hasValue(t_TokensContext* tokenContext)
{
	jsmntok_t token;
	if (!JsonUtl_getNextToken(tokenContext, &token)) return False;
	if (!JsonUtl_equalsTokenString(token, tokenContext, TOKEN_VALUE)) return False;
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_hasIndex
 -----------------------------------------------------------------------------------
 Description    : check if the next token is a index token.

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean MessageHandler_hasIndex(t_TokensContext* tokenContext)
{
	jsmntok_t token;
	if (!JsonUtl_getNextToken(tokenContext, &token)) return False;
	if (!JsonUtl_equalsTokenString(token, tokenContext, TOKEN_INDEX)) return False;
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : MessageHandler_getConnectionData
 -----------------------------------------------------------------------------------
 Description    : extract the connection data from the connection context 

 Parameters     : -

 Return values  : -return the connection data.
 ----------------------------------------------------------------------------------- */
t_ConnectionData* MessageHandler_getConnectionData(t_ConnectionContext* connection)
{
	t_ConnectionData *data =  (t_ConnectionData *) connection->userData;
	return data;
}

/* Actifsource ID=[13375425-030d-11e6-b47b-f140d082a724,4ae31ce4-2fda-11e2-a23a-331776341c66,304ffac5-2fda-11e2-a23a-331776341c66,Hash] */
