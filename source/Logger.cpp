#include "../header/Logger.hpp"

const std::string Logger::PriorityNames_[] =
{
    "INFO",
    "ERROR"
};

void Logger::write( Priority priority, const std::string& message, const std::string& date )
{
    file_       << date
                << "\n"
                << PriorityNames_[ priority ]
                << ": "
                << message
                << "\n" 
                << std::endl;
}
