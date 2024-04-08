/*
 * AnimationSocket.c
 *
 *  Created on: 14.04.2017
 *      Author: ruti
 */


/* === INCLUDE FILES =============================================================== */
#include "AnimationSocket.h"
#include <stdio.h>

/* === DEFINES ===================================================================== */
/* Begin Protected Region [[config]] */
// Windows
#ifdef __WIN32
	#include <winsock.h>
#endif

// Apple
#ifdef __APPLE__
	#include "TargetConditionals.h"
	#ifdef TARGET_OS_MAC
		#include <sys/types.h>
		#include <sys/socket.h>
		#include <netinet/in.h>
		#include <arpa/inet.h>
		void closesocket(int socket) { close(socket); }
		#define SOCKET int
	#endif
#endif

// Linux
#ifdef __linux__
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <arpa/inet.h>
	void closesocket(int socket) { close(socket); }
	#ifndef SOCKET
	#define SOCKET int
	#endif
#endif
/* End Protected Region   [[config]] */

#define BACKLOG 10
#define MAXRECV 300

/* === LOCAL VARIABLES ============================================================= */
static SOCKET        sockfd = 0;
static struct        sockaddr_in server;
static struct        sockaddr_in client;

#ifdef __WIN32
static WSADATA       wsaData;
#endif

/* ---------------------------------------------------------------------------------
 Function       : AnimationSocket_Start
 -----------------------------------------------------------------------------------
 Description    : Start the socket on SERVER_PORT

 Parameters     : - 

 Return values  : -true if the server is running.
 ----------------------------------------------------------------------------------- */
Boolean AnimationSocket_Start(void)
{
	#ifdef __WIN32
	WSAStartup(MAKEWORD(1, 1), &wsaData);
	#endif

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		return False;
	}

	server.sin_family = AF_INET;
	server.sin_port = htons(SERVER_PORT);
	server.sin_addr.s_addr = INADDR_ANY;
	memset(&(server.sin_zero), '/0', 8);

	if (bind(sockfd,(struct sockaddr *)&server,sizeof(struct sockaddr)) == -1)
	{
		return False;
	}

	if (listen(sockfd, BACKLOG) == -1)
	{
		return False;
	}
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : AnimationSocket_AcceptClient
 -----------------------------------------------------------------------------------
 Description    : accept client connection from animation server.

 Parameters     : - t_ConnectionContext connection context data

 Return values  : -true success
 ----------------------------------------------------------------------------------- */
Boolean AnimationSocket_AcceptClient(t_ConnectionContext* connection)
{
	int sin_size;
	sin_size = sizeof(struct sockaddr_in);
	if ((connection->clientfd = accept(sockfd, (struct sockaddr *)&client, &sin_size)) == -1)
	{
		connection->connected = False;
		return False;
	}
	connection->connected = True;
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : AnimationSocket_Read
 -----------------------------------------------------------------------------------
 Description    : Read data from socket.

 Parameters     : - t_ConnectionContext connection context data

 Return values  : --true success
 ----------------------------------------------------------------------------------- */
Boolean AnimationSocket_Read(t_ConnectionContext* connection, char* buffer)
{
	int bytesRcvd;

	if (!connection->connected)
	{
		return False;
	}
	if ((bytesRcvd = recv(connection->clientfd, buffer, MAXRECV, 0)) <= 0)
	{
		return False;
	}

	buffer[bytesRcvd] = '\0';
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : AnimationSocket_Write
 -----------------------------------------------------------------------------------
 Description    : Write data to socket.

 Parameters     : - t_ConnectionContext connection context data

 Return values  : --true success
 ----------------------------------------------------------------------------------- */
Boolean AnimationSocket_Write(t_ConnectionContext* connection, const char* sendBuffer)
{
	int cnt = 0;

	if (!connection->connected)
	{
		return False;
	}

	cnt = send(connection->clientfd, sendBuffer, strlen(sendBuffer), 0);
	if (cnt < 0)
	{
		return False;
	}
	return True;
}

/* ---------------------------------------------------------------------------------
 Function       : AnimationSocket_Close
 -----------------------------------------------------------------------------------
 Description    : Close the socket connection.

 Parameters     : - t_ConnectionContext connection context data

 Return values  : -
 ----------------------------------------------------------------------------------- */
Boolean AnimationSocket_Close(t_ConnectionContext* connection)
{
	if (connection->connected)
	{
		closesocket(connection->clientfd);
		connection->connected = False;
	}
	return True;
}

/* Actifsource ID=[ff54cd5a-030b-11e6-b47b-f140d082a724,6fa016b4-f5a7-11ee-8944-afc67c286a4c,6f9fef7b-f5a7-11ee-8944-afc67c286a4c,Hash] */
