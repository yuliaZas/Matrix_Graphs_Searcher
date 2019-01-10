//
// Created by Yulia.
//

#ifndef UNTITLED2_MYTESTCLIENTHANDLER_H
#define UNTITLED2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
private:
    //Solver solver;
    CacheManager mc;

public:
    void handleClient(int stream1, int stream2) override;
};


#endif //UNTITLED2_MYTESTCLIENTHANDLER_H
