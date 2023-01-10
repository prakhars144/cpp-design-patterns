#pragma once
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Logger
{
private:
    static Logger m_instance;
    fstream m_logFile;
    // default is faster
    Logger() = default;

public:
    static Logger &getInstance();
    void LOG(string msg);
    ~Logger() = default;
};
