#include "Logger.h"

Logger &Logger::getInstance()
{
    if (m_pInstance == nullptr)
        m_pInstance.reset(new Logger());
    return *m_pInstance;
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

Logger::Logger()
{
    cout << __PRETTY_FUNCTION__ << endl;
}

Logger::~Logger()
{
    cout << __PRETTY_FUNCTION__ << endl;
}
