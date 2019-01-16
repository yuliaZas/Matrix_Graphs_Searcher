//
// Created by Yulia.
//

#include "MyClientHandler.h"

MyClientHandler::MyClientHandler(Solver<ISearchable<std::pair<int, int>> *, State<std::pair<int, int>> *> *solver,
                                 CacheManager *cacheManager) {

    this->cacheManager = cacheManager;
    this->solver = solver;
}

void MyClientHandler::handleClient(int socket) {
    string data;
    string matrix;//maze
    string start;
    string goal;

    data = this->dataReader(socket);

    if (data.empty() == true) {
        close(socket);
        return;
    }

    string currLine;
    istringstream string_stream;
    string_stream.str(data);
    vector<string> linesVec;

    while (getline(string_stream, currLine)) {
        linesVec.push_back(currLine);
    }

    goal = linesVec.back();
    linesVec.pop_back();
    start = linesVec.back();
    linesVec.pop_back();

    for (auto iter = linesVec.begin(); iter < linesVec.end(); ++iter) {
        matrix += (*iter) + "\n";
    }
    matrix.pop_back();

    size_t  matrix_hash    = GetHashOfString(matrix);
    size_t  start_hash = GetHashOfString(start);
    size_t  goal_hash  = GetHashOfString(goal);

    string problem = to_string(matrix_hash) + "," + to_string(start_hash) + "," + to_string(goal_hash);

    mtx.lock();

    std::string result;
    if (this->cacheManager->solutionExists(problem) == true) {
        result = this->cacheManager->getSolution(problem);
    }
    else {
        try {
            ISearcher<pair<int, int>>* searcher;
            searcher = new BestFS<pair<int, int>>();
            Solver<ISearchable<pair<int, int>>*,vector<State<pair<int, int>>*>> *solver =
                    new SearchableSolver(searcher);

            MatrixInterpreter mi;
            vector<vector<int>> mazeVec = mi.matrixInter(matrix);

            pair<int,int> startPos = this->strToIntPair(start);
            State<pair<int,int>>* sP = new State<pair<int,int>>(startPos,0);
            pair<int,int> goalPos = this->strToIntPair(goal);
            State<pair<int,int>>* gP = new State<pair<int,int>>(goalPos,0);

            ISearchable<pair<int,int>>* searchable = new matrixMaze(mazeVec, sP, gP);
            State<pair<int,int>>* path = solver->solveProblem(searchable)
                    [solver->solveProblem(searchable).size() - 1];

            result = pathGetter(path);

            delete(searchable);
            delete(solver);
            delete(searcher);

            this->cacheManager->saveSolution(problem, result);

        } catch (exception &e) {
            mtx.unlock();
            close(socket);
            return;
        }
    }
    mtx.unlock();

    result += '\n';
    int n = write(socket, result.c_str(), (result.length()));
    if (n < 0) {
        close(socket);
        return;
    }
    close(socket);
}

std::string MyClientHandler::pathGetter(State<pair<int, int>> *path) {
    State<pair<int,int>>* curr = path;
    State<pair<int,int>>* prev = curr->getPrev();
    string res;

    while (prev != nullptr) {
        pair<int,int> currPos  = curr->getState();
        pair<int,int> prevPos = prev->getState();
        if (currPos.first == prevPos.first + 1 ) {
            res.insert(0, ",down");
        } else if (currPos.first == prevPos.first - 1) {
            res.insert(0, ",up");
        } else if (currPos.second == prevPos.second - 1) {
            res.insert(0, ",left");
        } else if (currPos.second == prevPos.second + 1) {
            res.insert(0, ",right");
        }
        curr  = prev;
        prev = curr->getPrev();
    }

    res.erase(0,1);
    return res;
}

std::string MyClientHandler::dataReader(int socket) {

    bool end = false;
    char buff[1024];
    int numBytesToRead;
    string data;
    string dataToRead;
    string dataToRet;

    while (end == false) {
        bzero(buff, 1024);
        numBytesToRead = (int)read(socket, buff, 1023);

        if (numBytesToRead < 0) {
            return "";
        }

        dataToRead = buff;
        data += dataToRead;

        if (dataToRead.find("end") != string::npos) {
            end = true;
        }
    }

    dataToRet = data.substr(0, data.find("end"));
    dataToRet.erase(remove(dataToRet.begin(), dataToRet.end(), '\r'), dataToRet.end());

    return dataToRet;

}

size_t MyClientHandler::GetHashOfString(string str) {
    return hash<string>{}(str);
}

pair<int,int> MyClientHandler::strToIntPair(string str) {
    pair<int,int> intPair;

    stringstream line;
    line.str(str);
    vector<int> parsedLine;

    while (line.good()){
        string tempVal;
        getline(line, tempVal, ',');
        if (!tempVal.empty()) {
            parsedLine.push_back(stoi(tempVal));
        }
    }

    if (parsedLine.size() == 2) {
       intPair.first = parsedLine.at(0);
       intPair.second = parsedLine.at(1);
    }
    return intPair;
}
