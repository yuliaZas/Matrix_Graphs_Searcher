//
// Created by Yulia.
//

#ifndef UNTITLED2_CLIENTHANDLER_H
#define UNTITLED2_CLIENTHANDLER_H

#include <sstream>
#include <iostream>

using namespace std;

class ClientHandler {
public:
    virtual void handleClient(int) = 0;
};

#endif //UNTITLED2_CLIENTHANDLER_H
