/*
 * JsonUtil.h
 *
 *  Created on: 14.04.2017
 *      Author: ruti
 */

#ifndef _JSON_UTIL_H
#define _JSON_UTIL_H

/* === INCLUDE FILES =============================================================== */
#include <stdio.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/* === INCLUDE FILES =============================================================== */
#include "Jsmn.h"
#include "Type.h"
#include "AnimationSocket.h"

/* === DEFINITION ==================================================================== */
#define MaxJsonIdSize 10

/* === JSON DEFINITION =============================================================== */
extern const char* TOKEN_ID;
extern const char* TOKEN_ERROR;

extern const char* TOKEN_BIND;
extern const char* TOKEN_UNBIND;

extern const char* TOKEN_EXPLORER_TREE;
extern const char* TOKEN_GET;

extern const char* TOKEN_TEST_BENCH_STATE;
extern const char* TOKEN_TEST_BENCH_STATE_RESET;
extern const char* TOKEN_TEST_BENCH_STATE_COMPLETE;

extern const char* TOKEN_TEST_BENCH_EVENT;
extern const char* TOKEN_TEST_BENCH_ACTION;
extern const char* TOKEN_TEST_REQUIRED_INPUT;
extern const char* TOKEN_TEST_REQUIRED_OUTPUT;      

extern const char* TOKEN_VALUE;
extern const char* TOKEN_INDEX;

/* === TYPEs =============================================================== */
typedef struct
{
	int id[MaxJsonIdSize];
	int idSize;
} t_JsonId;

typedef struct
{
	int tokenindex;
	int resultSize;
	jsmntok_t tokens[1000];
	char jsonMessage[1000];
} t_TokensContext;

typedef struct
{
	Boolean isBinded;
	t_JsonId bindId;
	int sequenceNumber;
} t_ConnectionData;


/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_readMessage
 -----------------------------------------------------------------------------------
 Description    : Read next json message from socket.

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_readMessage(t_ConnectionContext* connection, char* jsonString);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_parsMessage
 -----------------------------------------------------------------------------------
 Description    : pars message to token context

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_parsMessage(char* jsonString, t_TokensContext* tokenContext);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_getNextToken
 -----------------------------------------------------------------------------------
 Description    : get the next token

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_getNextToken(t_TokensContext *tokensContext, jsmntok_t *token);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_getNextObjectToken
 -----------------------------------------------------------------------------------
 Description    : get the next object token

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_getNextObjectToken(t_TokensContext *tokenContext, jsmntok_t objectToken, jsmntok_t *token);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_releaseLastToken
 -----------------------------------------------------------------------------------
 Description    : release last token in the token context

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_releaseLastToken(t_TokensContext *tokenContext);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_isObject
 -----------------------------------------------------------------------------------
 Description    : check if the token is a object

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_isObject(jsmntok_t token);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_isArray
 -----------------------------------------------------------------------------------
 Description    : check it the token is a array

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_isArray(jsmntok_t token);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_isPrimitive
 -----------------------------------------------------------------------------------
 Description    : check if the token is a primitive

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_isPrimitive(jsmntok_t token);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_getTokenString
 -----------------------------------------------------------------------------------
 Description    : get string from token.

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_getTokenString(jsmntok_t token, t_TokensContext *tokensContext, char* dest);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_getTokenJsonId
 -----------------------------------------------------------------------------------
 Description    :get json id from token.

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_getTokenJsonId(t_TokensContext *tokenContext, t_JsonId* jsonId);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_getTokenInteger
 -----------------------------------------------------------------------------------
 Description    : get integer from token.

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_getTokenInteger(jsmntok_t token, t_TokensContext *tokensContext, int* data);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_getTokenDouble
 -----------------------------------------------------------------------------------
 Description    : get double from token.

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_getTokenDouble(jsmntok_t token, t_TokensContext *tokenContext, double* data);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_equalsTokenString
 -----------------------------------------------------------------------------------
 Description    : check it the token is equals the string

 Parameters     : -

 Return values  : -return true equals.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_equalsTokenString(jsmntok_t token, t_TokensContext *tokensContext, const char *compString);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_initStringBuffer
 -----------------------------------------------------------------------------------
 Description    : Init stringbuffer

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_initStringBuffer(char *stringBuffer);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_appendString
 -----------------------------------------------------------------------------------
 Description    : Append String to stringbuffer

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_appendString(char *stringBuffer, const char *string);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_appendInteger
 -----------------------------------------------------------------------------------
 Description    : Append integer to stringbuffer

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_appendInteger(char *stringBuffer, int data);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_appendDouble
 -----------------------------------------------------------------------------------
 Description    : Append double to stringbuffer

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_appendDouble(char *stringBuffer, double data);

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_appendJsonId
 -----------------------------------------------------------------------------------
 Description    :

 Parameters     : -

 Return values  : -
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_appendJsonId(char *stringBuffer, t_JsonId *jsonId);

/* Begin Protected Region [[appendJson]] */

/* End Protected Region   [[appendJson]] */

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _JSON_UTIL_H

/* Actifsource ID=[8329c71c-030d-11e6-b47b-f140d082a724,6fa016b4-f5a7-11ee-8944-afc67c286a4c,6f9fef7b-f5a7-11ee-8944-afc67c286a4c,Hash] */
