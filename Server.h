//
// Created by Yulia.
//

#ifndef UNTITLED2_SERVER_H
#define UNTITLED2_SERVER_H

#include "MyTestClientHandler.h"

class Server {
public:
    virtual void open(int port, MyTestClientHandler) = 0;
    virtual void close() = 0;
};


#endif //UNTITLED2_SERVER_H
