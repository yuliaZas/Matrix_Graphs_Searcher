//
// Created by Yulia.
//

#ifndef UNTITLED2_DATAFORSERVER_H
#define UNTITLED2_DATAFORSERVER_H

#include "ClientHandler.h"


/*Save data for the threads*/
class DataForServer {
private:

    ClientHandler *clientHandle;
    int port;
    int socket;

public:


    DataForServer(int portNum1, ClientHandler *clientHandler1);

    DataForServer(int portNum1, ClientHandler *clientHandler1, int socket);

    ClientHandler *getClientHandle() const;

    int getPort() const;

    int getSocket() const;
};


#endif //UNTITLED2_DATAFORSERVER_H
