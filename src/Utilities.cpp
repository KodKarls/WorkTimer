#include "Utilities.hpp"

namespace Utitilies
{
	// Variables
	int TIME = 0;

	// Functions
	sf::String setPolishSigns( const std::string& text )
	{
		sf::String result = "";
        std::basic_string< sf::Uint32 > temp;
        sf::Utf8::toUtf32( text.begin(), text.end(), std::back_inserter( temp ) );
        result = temp;
        return result;
	}

	void setTime( int time )
	{
		TIME = time;
	}

	const int getTime()
	{
		return TIME;
	}
}