#include "Logger.h"

// initialize the instance
Logger Logger::m_instance;

Logger &Logger::getInstance()
{
    return m_instance;
}

void Logger::LOG(string msg)
{
    m_logFile.open("log.txt", ios::app);
    if (m_logFile)
    {
        m_logFile << msg;
        m_logFile.close();
    }
    else
    {
        cerr << "Failed to open log.txt" << endl;
    }
}
