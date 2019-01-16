//
// Created by Yulia.
//

#ifndef UNTITLED2_MYSERIALSERVER_H
#define UNTITLED2_MYSERIALSERVER_H

#include "Server.h"
#include "ClientHandler.h"

class MySerialServer : public server_side::Server{
public:
    void open(int i, ClientHandler* handler) override;

    void close() override;
};


#endif //UNTITLED2_MYSERIALSERVER_H
