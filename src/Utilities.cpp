#include "Utilities.hpp"

namespace Utitilies
{
	sf::String setPolishSigns( const std::string& text )
	{
		sf::String result = "";
        std::basic_string< sf::Uint32 > temp;
        sf::Utf8::toUtf32( text.begin(), text.end(), std::back_inserter( temp ) );
        result = temp;
        return result;
	}
}