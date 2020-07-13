#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <SFML/System/String.hpp>

namespace Utitilies
{
	// Variables
	extern int TIME;

	// Functions
	sf::String setPolishSigns( const std::string& text );

	void setTime( int time );
	const int getTime();
}

#endif
