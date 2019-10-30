#include "../header/Utilities.hpp"

namespace Utilities
{
    std::string getTimeStr()
    {
        std::time_t now = std::chrono::system_clock::to_time_t( std::chrono::system_clock::now() );
        std::string s( 30, '\0' );
        std::strftime( &s[ 0 ], s.size(), "%Y-%m-%d %H:%M:%S", std::localtime( &now ) );
        return s;
    }
}
