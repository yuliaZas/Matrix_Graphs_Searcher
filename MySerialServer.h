//
// Created by Yulia.
//

#ifndef UNTITLED2_MYSERIALSERVER_H
#define UNTITLED2_MYSERIALSERVER_H

#include "Server.h"

class MySerialServer : public Server{
public:
    void open(int i, ClientHandler handler) override;

    void close() override;
};


#endif //UNTITLED2_MYSERIALSERVER_H
