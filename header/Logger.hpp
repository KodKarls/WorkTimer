#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>

class Logger
{
private:
    std::fstream file_;

    Logger()
    {
        file_.open( "files/log.log", std::ios::out | std::ios::ate );
    }

    Logger( const Logger& ) = delete;

    Logger( Logger&& ) = delete;

    ~Logger()
    {
        file_.close();
    }

public:
    template< typename T >
    Logger& operator<<( const T& write )
    {
        file_ << write;
        return *this;
    }

    static Logger& getSingleton()
    {
        static Logger singleton;
        return singleton;
    }
};

#endif
