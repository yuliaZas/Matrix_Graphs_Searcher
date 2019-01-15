//
// Created by Yulia.
//

#ifndef UNTITLED2_CLIENTHANDLER_H
#define UNTITLED2_CLIENTHANDLER_H

#include <sstream>
#include <iostream>

using namespace std;

/*Defines a Client Handler object*/
class ClientHandler {
public:
    /**
     * Writes server's output to output stream, after getting input from the server through the input stream.
     */
    virtual void handleClient(int) = 0;
};

#endif //UNTITLED2_CLIENTHANDLER_H
