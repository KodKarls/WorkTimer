#include "../header/ClockBlock.hpp"

ClockBlock::ClockBlock( int width, int height,
						int positionX, int positionY )  :	width_( width ), height_( height ),
															positionX_( positionX ), positionY_( positionY ),
															rectangle_( sf::RectangleShape() )
{
	rectangle_ = sf::RectangleShape( sf::Vector2f( width_, height_ ) );
	setColor();
	rectangle_.setPosition( positionX_, positionY_ );
}


ClockBlock::~ClockBlock()
{
	// Empty body
}

void ClockBlock::setColor( short red, short green, short blue, short alpha )
{
	rectangle_.setFillColor( sf::Color( red, green, blue, alpha ) );
}

sf::RectangleShape& ClockBlock::getShape()
{
	return rectangle_;
}
