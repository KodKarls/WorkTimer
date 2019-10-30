#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <fstream>

class Logger
{
public:
    enum Priority
    {
        INFO,
        ERROR
    };

    void write( const std::string& date, Priority priority, const std::string& message );

    static Logger& getLogger()
    {
        static Logger singleton;
        return singleton;
    }

    template< typename T >
	Logger& operator <<(const T& write)
	{
		file_ << write;
		return *this;
	}

private:
    Logger()
    {
        file_.open( "files/log.log", std::ios::out | std::ios::app );
    }
    Logger( const Logger& ) = delete;
    Logger( Logger&& ) = delete;

    ~Logger()
    {
        file_.close();
    }

    std::ofstream file_;
    static const std::string PriorityNames_[];
};

#endif
