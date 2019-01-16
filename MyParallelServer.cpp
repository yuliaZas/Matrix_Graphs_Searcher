//
// Created by Yulia.
//


#include "MyParallelServer.h"

void MyParallelServer::open(int port, ClientHandler *clientHandler) {

    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    bool first_client_served = false;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    if (sockfd < 0) {
        perror("Error occurred while opening the socket.");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons((uint16_t)((size_t)port));

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Failed to make bind.");
        exit(1);
    }

    bool timeOut = false;
    while (timeOut == false) {

        if (first_client_served) {
            timeval timeout;
            timeout.tv_sec = 10;
            timeout.tv_usec = 0;

            setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        }

        listen(sockfd,5);
        clilen = sizeof(cli_addr);

        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

        first_client_served = true;

        if (newsockfd < 0) {
            perror("timeout occurred");
            timeOut = true;
        } else {
            auto data = new DataForServer(port, clientHandler, newsockfd);
            pthread_t* pthread = new pthread_t;
            this->threads.push_back(pthread);
            pthread_create(pthread, &attr, this->handleCaller ,(void*)(data));
        }
    }

    pthread_attr_destroy(&attr);
    close();
}

void MyParallelServer::close() {

    void* status;
    for (auto iter = this->threads.begin(); iter != this->threads.end(); ++iter) {
        pthread_join((*(*iter)), &status);
        free((*iter));
    }

    this->threads.clear();
}

void *MyParallelServer::handleCaller(void* args) {
    auto * arguments = (DataForServer*) args;
    arguments->getClientHandle()->handleClient(arguments->getSocket());
}