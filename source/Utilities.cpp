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

    void sleep( int delay )
    {
        std::this_thread::sleep_for( std::chrono::milliseconds( delay ) );
    }

    sf::String setPolishLetters( const std::string& text )
    {
        sf::String result = "";
        std::basic_string< sf::Uint32 > temp;
        sf::Utf8::toUtf32( text.begin(), text.end(), std::back_inserter( temp ) );
        result = temp;
        return result; 
    }
}
