#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <thread>
#include <SFML/Graphics/Text.hpp>

namespace Utilities
{
    std::string getTimeStr();
    void sleep( int delay );
    sf::String setPolishLetters( const std::string& text );

    const int width = 600;
    const int height = 600;
    const std::string appName = "Czasomierz";
}

#endif
