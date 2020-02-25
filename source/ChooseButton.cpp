#include "../header/ChooseButton.hpp"

ChooseButton::ChooseButton( std::string name, int width, int height )
{
	name_ = name;
	width_ = width;
	height_ = height;
	rectangle_.setSize( sf::Vector2f( width_, height_ ) );
    setButtonColor();
    setButtonPosition();
    setFont();
    setText();
    setTextPosition();
}

ChooseButton::~ChooseButton()
{
	// Empty body
}

void ChooseButton::changeButtonPosition( float posX, float posY )
{
	positionX_ = posX;
	positionY_ = posY;
	rectangle_.setPosition( sf::Vector2f( posX, posY ) );
	setTextPosition();
}

void ChooseButton::setButtonPosition()
{
	positionX_ = Utilities::WIDTH * 0.5 - rectangle_.getGlobalBounds().width * 0.5;
    positionY_ = Utilities::HEIGHT * 0.33 - rectangle_.getGlobalBounds().height * 1.5 + height_ * 2 + 150;
    rectangle_.setPosition( sf::Vector2f( positionX_, positionY_ ) );
}

void ChooseButton::setTextPosition()
{
	float positionX = getPositionX() + ( rectangle_.getGlobalBounds().width - text_.getGlobalBounds().width ) * 0.5;
    float positionY = getPositionY() + ( rectangle_.getGlobalBounds().height - text_.getGlobalBounds().height ) * 0.3;
    text_.setPosition( sf::Vector2f( positionX, positionY ) );
}
