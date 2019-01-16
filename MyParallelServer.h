//
// Created by Yulia.
//

#ifndef UNTITLED2_MYPARALLELSERVER_H
#define UNTITLED2_MYPARALLELSERVER_H

#include <pthread.h>
#include <string.h>
#include <string>
#include <vector>
#include <thread>
#include <sstream>
#include "Server.h"
#include "ClientHandler.h"
//#include "ArgumentsForOpenServer.h"

using namespace server_side;
using namespace std;

class MyParallelServer : public Server {
private:
    /* Holds all the opened pthreads. */
    std::vector<pthread_t*> threads;

public:
    /**
    * Create and open the server, for each accepted client we open a thread.
    * We stop accepting after a timeout event, in this case we call stop function.
    * @param port The port to listen on.
    * @param clientHandler The client handler to use for each client.
    */
    void open(int port, ClientHandler *clientHandler) override;
    void close() override;

private:
    static void* callHandler(void*);
};

#endif //UNTITLED2_MYPARALLELSERVER_H