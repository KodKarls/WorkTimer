#ifndef CLOCK_BLOCK_HPP
#define CLOCK_BLOCK_HPP

#include "Logger.hpp"
#include <SFML/Graphics.hpp>

class ClockBlock
{
public:
	ClockBlock( int width, int height, int positionX = 0, int positionY = 0 );
	~ClockBlock();

	void setColor( short red = 60, short green = 179, short blue = 113, short alpha = 230 );
	sf::RectangleShape& getShape();

private:
	int width_;
    int height_;
	sf::RectangleShape rectangle_;
	int positionX_;
	int positionY_;
};

#endif
