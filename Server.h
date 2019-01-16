//
// Created by Yulia.
//

#ifndef UNTITLED2_SERVER_H
#define UNTITLED2_SERVER_H

#include "ClientHandler.h"

/*In charge to open the server on the given port and close it.*/
namespace server_side {
class Server {
public:
    /**
     * In charge to open the server on the given port.
     * @param port the port
     * @param handler the handler to use
     */
    virtual void open(int port, ClientHandler* handler) = 0;
    /**
     * Close the server
     */
    virtual void close() = 0;
    };
}

#endif //UNTITLED2_SERVER_H
