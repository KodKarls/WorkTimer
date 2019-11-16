#ifndef EACH_SCREEN_HPP
#define EACH_SCREEN_HPP

#include <SFML/Graphics/RenderWindow.hpp>

class EachScreen
{
public:
    virtual int run( sf::RenderWindow &app ) = 0;
};

#endif
