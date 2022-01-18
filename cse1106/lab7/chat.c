// Chat Network Application
// Jason Losh

//-----------------------------------------------------------------------------
// Compile notes for C99 code
//-----------------------------------------------------------------------------

// gcc -std=c99 -o chat chat.c udp.c

//-----------------------------------------------------------------------------
// Device includes, defines, and assembler directives
//-----------------------------------------------------------------------------

#include <stdlib.h>          // EXIT_ codes
#include <stdbool.h>         // bool
#include <stdio.h>           // printf, scanf
#include <string.h>          // strlen, strcmp

#include "udp.h"

#define SERVER_LISTENER_PORT 4096
#define CLIENT_LISTENER_PORT 4097

#define MAX_CHARS_PER_MESSAGE 80

//-----------------------------------------------------------------------------
// Main
//-----------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    char *remoteIp;
    char *mode;
    int remotePort;

    char str[MAX_CHARS_PER_MESSAGE+1];
    bool quit = false;

    bool sendMode;

    // Verify arguments are good
    bool goodArguments = (argc == 3);
    if (goodArguments)
    {
        remoteIp = argv[1];
        mode = argv[2];
        goodArguments = (strcmp(mode, "server") == 0) || (strcmp(mode, "client") == 0);
    }
    if (!goodArguments)
    {
        printf("usage: chat IPV4_ADDRESS MODE\n");
        printf("  where:\n");
        printf("  IPV4_ADDRESS is address of the remote machine\n");
        printf("  MODE is either client or server\n");
        exit(EXIT_FAILURE);
    }

    // Determine if client or server
    bool client = strcmp(mode, "client") == 0;

    // TODO: Open listener port number dependent on client/server role


    // TODO: Determine remote port that you will send data to
    //       If you are server, send to client port, and vice versa

    // TODO: Determine if it is your turn to send data or not,
    //       based on server or client mode
    // sendMode = ...

    // Start chat loop, alternating between sending and receiving messages
    while(!quit)
    {
        // send text
        if (sendMode)
        {
            // TODO: Add code to get string from user and send
            // TODO: Handle an error is sendData returns false
            // TODO: Leave while loop if QUIT was sent
        }
        // wait for text
        else
        {
            // TODO: Add code to wait for a string from remote user
            // TODO: Leave while loop if QUIT is received
        }
        // alternate between send and receive mode
        sendMode = !sendMode;
    }

    // TODO: Close listener port
    return EXIT_SUCCESS;
}
