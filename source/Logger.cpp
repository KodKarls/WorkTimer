#include "../header/Logger.hpp"

const std::string Logger::PriorityNames_[] =
{
    "INFO",
    "ERROR"
};

void Logger::write( const std::string& date, Priority priority, const std::string& message )
{
    file_       << date
                << "\n"
                << PriorityNames_[ priority ]
                << ": "
                << message
                << "\n" 
                << std::endl;
}
