/*
 * JsonUtil.c
 *
 *  Created on: 14.04.2017
 *      Author: ruti
 */


/* === INCLUDE FILES =============================================================== */
#include "JsonUtil.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AnimationSocket.h"

/* === JSON DEFINITION =============================================================== */
const char* TOKEN_ID                              = "id";
const char* TOKEN_ERROR                           = "error";

const char* TOKEN_BIND                            = "bind";
const char* TOKEN_UNBIND                          = "unbind";

const char* TOKEN_EXPLORER_TREE                   = "tree";
const char* TOKEN_GET                             = "get";

const char* TOKEN_TEST_BENCH_STATE                = "testbenchState";
const char* TOKEN_TEST_BENCH_STATE_RESET          = "reset";
const char* TOKEN_TEST_BENCH_STATE_COMPLETE       = "complete";

const char* TOKEN_TEST_BENCH_EVENT                = "testbenchEvent";
const char* TOKEN_TEST_BENCH_ACTION               = "testbenchAction";
const char* TOKEN_TEST_REQUIRED_INPUT             = "requiredInput";
const char* TOKEN_TEST_REQUIRED_OUTPUT            = "requiredOutput";

const char* TOKEN_VALUE                           = "value";
const char* TOKEN_INDEX                           = "index";

/* === DECLARATION ================================================================= */
static int getJsonObjectFromBuffer(char* jsonString);
static int subString(const char* input, int offset, int len, char* dest);

/* === LOCAL VARIABLES ============================================================= */
static char _stringBufferCache[2000];

/* ---------------------------------------------------------------------------------
 Function       : getJsonObjectFromBuffer
 -----------------------------------------------------------------------------------
 Description    : Read next json object from buffer

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
static Boolean getJsonObjectFromBuffer(char* jsonString)
{
	int jsonEndIndex = 0;
	int index = 0;
	int stringBufferCacheSize;
	char tempStringBufferCache[2000];

	stringBufferCacheSize = strlen(_stringBufferCache);
	if (stringBufferCacheSize == 0) return 1;
	if (_stringBufferCache[0] != '{') {
		return False;
	}

	for (index = 0; index < stringBufferCacheSize; index++) {

		if (_stringBufferCache[index] != '}') continue;

		if (index + 1 < stringBufferCacheSize) {
			if (_stringBufferCache[index + 1] == '{') {
				jsonEndIndex = index + 1;
				break;
			}
		}
		if (index + 1 == stringBufferCacheSize) {
			jsonEndIndex = index + 1;
			break;
		}
	}
	if (jsonEndIndex == 0) {
		return False;
	}

	strncpy(jsonString, _stringBufferCache, jsonEndIndex + 1);
	if (stringBufferCacheSize > jsonEndIndex) {
		strcpy(tempStringBufferCache, _stringBufferCache);
		strcpy(_stringBufferCache, &tempStringBufferCache[jsonEndIndex + 1]);
	} else {
		strcpy(_stringBufferCache, "");
	}
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : subString
 -----------------------------------------------------------------------------------
 Description    : sub string 

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
static Boolean subString(const char* input, int offset, int len, char* dest)
{
  int input_len = strlen (input);

  if (offset + len > input_len)
  {
     return False;
  }

  strncpy (dest, input + offset, len);
  dest[len] = '\0';

  return True;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_readMessage
 -----------------------------------------------------------------------------------
 Description    : Read next json message from socket.

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_readMessage(t_ConnectionContext* connection, char* jsonString)
{
	char readBuffer[500];

	jsonString[0] = '\0';
	if(!getJsonObjectFromBuffer(jsonString))
	{
		return False;
	}
	if (strlen(jsonString) > 0)
	{
		return True;
	}

	if (!AnimationSocket_Read(connection, readBuffer))
	{
		return False;
	}
	sprintf(_stringBufferCache + strlen(_stringBufferCache), readBuffer);

	if(!getJsonObjectFromBuffer(jsonString))
	{
		return False;
	}
	if (strlen(jsonString) > 0)
	{
		return True;
	}
	return False;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_parsMessage
 -----------------------------------------------------------------------------------
 Description    : pars message to token context

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_parsMessage(char* jsonString, t_TokensContext* tokenContext)
{
	jsmn_parser parser;

	tokenContext->resultSize = 0;
	tokenContext->tokenindex = 0;
	strcpy(tokenContext->jsonMessage, jsonString);

	jsmn_init(&parser);
	tokenContext->resultSize = jsmn_parse(&parser, jsonString, strlen(jsonString), tokenContext->tokens, 1000);
	if (tokenContext->resultSize >= 0)
	{
		return True;
	}
	return False;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_getNextToken
 -----------------------------------------------------------------------------------
 Description    : get the next token

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_getNextToken(t_TokensContext *tokenContext, jsmntok_t *token)
{
	if (tokenContext->resultSize > tokenContext->tokenindex)
	{
		*token = tokenContext->tokens[tokenContext->tokenindex];
		tokenContext->tokenindex++;
		return True;
	}
	return False;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_getNextObjectToken
 -----------------------------------------------------------------------------------
 Description    : get the next object token

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_getNextObjectToken(t_TokensContext *tokenContext, jsmntok_t objectToken, jsmntok_t *token)
{
	if (!JsonUtl_getNextToken(tokenContext, token)) return False;
	if (token->end <= objectToken.end) return True;
	JsonUtl_releaseLastToken(tokenContext);
	return False;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_releaseLastToken
 -----------------------------------------------------------------------------------
 Description    : release last token in the token context

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_releaseLastToken(t_TokensContext *tokenContext)
{
	if (0 < tokenContext->tokenindex)
	{
		tokenContext->tokenindex--;
		return True;
	}
	return False;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_isObject
 -----------------------------------------------------------------------------------
 Description    : check if the token is a object

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_isObject(jsmntok_t token)
{
	if (token.type == JSMN_OBJECT)
	{
		return True;
	}
	return False;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_isArray
 -----------------------------------------------------------------------------------
 Description    : check it the token is a array

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_isArray(jsmntok_t token)
{
	if (token.type == JSMN_ARRAY)
	{
		return True;
	}
	return False;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_isPrimitive
 -----------------------------------------------------------------------------------
 Description    : check if the token is a primitive

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_isPrimitive(jsmntok_t token)
{
	if (token.type == JSMN_PRIMITIVE)
	{
		return True;
	}
	return False;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_getTokenJsonId
 -----------------------------------------------------------------------------------
 Description    :get json id from token.

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_getTokenJsonId(t_TokensContext *tokenContext, t_JsonId* jsonId)
{
	int id;
	int index = 0;
	jsmntok_t token;

	if (!JsonUtl_getNextToken(tokenContext, &token)) return False;
	if (!JsonUtl_equalsTokenString(token, tokenContext, TOKEN_ID)) return False;
	if (!JsonUtl_getNextToken(tokenContext, &token)) return False;
	if (!JsonUtl_isArray(token)) return False;  //[

	for (index = 0; index < MaxJsonIdSize; index++)
	{
		if (!JsonUtl_getNextToken(tokenContext, &token)) break;
		if (!JsonUtl_getTokenInteger(token, tokenContext, &id)) break;
		jsonId->id[index] = id;
	}
	JsonUtl_releaseLastToken(tokenContext);
	jsonId->idSize = index;
	return  True;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_getTokenInteger
 -----------------------------------------------------------------------------------
 Description    : get integer from token.

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_getTokenInteger(jsmntok_t token, t_TokensContext *tokenContext, int* data)
{
	 char primitive[100];

	 if(token.type != JSMN_PRIMITIVE)
	 {
		 return False;
	 }

	 if (!subString(tokenContext->jsonMessage, token.start, token.end - token.start, primitive))
	 {
		 return False;
	 }

	 /* Begin Protected Region [[Integer]] */
	 *data = atoi(primitive);
	 /* End Protected Region   [[Integer]] */
	 return True;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_getTokenDouble
 -----------------------------------------------------------------------------------
 Description    : get double from token.

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_getTokenDouble(jsmntok_t token, t_TokensContext *tokenContext, double* data)
{
	 char primitive[100];

	 if(token.type != JSMN_PRIMITIVE)
	 {
		 return False;
	 }

	 if (!subString(tokenContext->jsonMessage, token.start, token.end - token.start, primitive))
	 {
		 return False;
	 }

	 /* Begin Protected Region [[double]] */
	 *data = atof(primitive);
	 /* End Protected Region   [[double]] */
	 return True;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_getTokenString
 -----------------------------------------------------------------------------------
 Description    : get string from token.

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_getTokenString(jsmntok_t token, t_TokensContext *tokenContext, char* dest)
{
	 if(token.type != JSMN_STRING)
	 {
		 return False;
	 }
	 if (!subString(tokenContext->jsonMessage, token.start, token.end - token.start, dest))
	 {
		 return False;
	 }
	 return True;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_equalsTokenString
 -----------------------------------------------------------------------------------
 Description    : check it the token is equals the string

 Parameters     : -

 Return values  : -return true equals.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_equalsTokenString(jsmntok_t token, t_TokensContext *tokenContext, const char *compString)
{
	int size=0;
	int index = 0;
	char tempString[100];
	if (!JsonUtl_getTokenString(token, tokenContext, tempString))
	{
		return False;
	}

	size = strlen(tempString );
	if (size != strlen(compString)) return 0;

	for (index = 0; index < size; index++) {
		if (tempString[index] == compString[index]) continue;
		return False;
	}
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_initStringBuffer
 -----------------------------------------------------------------------------------
 Description    : Init stringbuffer

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_initStringBuffer(char *stringBuffer)
{
	stringBuffer[0] = '\0';
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_appendString
 -----------------------------------------------------------------------------------
 Description    : Append String to stringbuffer

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_appendString(char *stringBuffer, const char *string)
{
	sprintf(stringBuffer + strlen(stringBuffer), string);
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_appendInteger
 -----------------------------------------------------------------------------------
 Description    : Append integer to stringbuffer

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_appendInteger(char *stringBuffer, int data)
{
	char dataAsString[50];
	sprintf(dataAsString, "%d", data);
	JsonUtl_appendString(stringBuffer, dataAsString);
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_appendDouble
 -----------------------------------------------------------------------------------
 Description    : Append double to stringbuffer

 Parameters     : -

 Return values  : -return true success.
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_appendDouble(char *stringBuffer, double data)
{
	char dataAsString[50];
	sprintf(dataAsString, "%lf", data);
	JsonUtl_appendString(stringBuffer, dataAsString);
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : JsonUtl_appendJsonId
 -----------------------------------------------------------------------------------
 Description    :

 Parameters     : -

 Return values  : -
 ----------------------------------------------------------------------------------- */
Boolean JsonUtl_appendJsonId(char *stringBuffer, t_JsonId *jsonId)
{
	int index = 0;

	JsonUtl_appendString(stringBuffer, "[");

	for (index = 0; index < jsonId->idSize; index++)
	{
		if (index > 0) {
			JsonUtl_appendString(stringBuffer, ",");
		}
		JsonUtl_appendInteger(stringBuffer, jsonId->id[index]);
	}

	JsonUtl_appendString(stringBuffer, "]");
	return True;
}

/* Begin Protected Region [[appendJson]] */

/* End Protected Region   [[appendJson]] */

/* Actifsource ID=[0a94a285-030d-11e6-b47b-f140d082a724,4ae31ce4-2fda-11e2-a23a-331776341c66,304ffac5-2fda-11e2-a23a-331776341c66,Hash] */
