#include "Logger.hpp"

Logger* Logger::m_instance = nullptr;

Logger::Logger()
{
}

Logger* Logger::Get()
{
    //Ensure single instance of Logger
    if(!m_instance)
    {
        m_instance = new Logger;
        Logger::Get()->log.open("log/GameLog.log");
    }
    return m_instance;
}

void Logger::Log(std::string logText)
{
    log << logText << std::endl;
}

Logger::~Logger()
{
    log.flush();
    log.close();
    delete m_instance;
    m_instance = nullptr;
}

