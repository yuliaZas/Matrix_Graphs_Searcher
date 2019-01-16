//
// Created by Yulia.
//

#include "DataForServer.h"

/* Constructors. */

DataForServer::DataForServer(int port1, ClientHandler *clientHandle1) {
    this->clientHandle = clientHandle1;
    this->port = port1;
    this->socket = 0;
}

DataForServer::DataForServer(int port1, ClientHandler *clientHandle1, int socket1) {
    this->clientHandle = clientHandle1;
    this->port = port1;
    this->socket = socket1;
}

/* Getters. */

ClientHandler *DataForServer::getClientHandle() const {
    return this->clientHandle;
}

int DataForServer::getPort() const {
    return this->port;
}

int DataForServer::getSocket() const {
    return this->socket;
}
