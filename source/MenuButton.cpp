#include "../header/MenuButton.hpp"

int MenuButton::buttonCounter = 0;

MenuButton::MenuButton( std::string name )
{
	name_ = name;
	rectangle_.setSize( sf::Vector2f( width_, height_ ) );
    setButtonColor();
    setButtonPosition();
    setFont();
    setText();
    setTextPosition();
	buttonCounter++;
}

MenuButton::~MenuButton()
{
    buttonCounter = 0;
}

void MenuButton::setButtonPosition()
{
	positionX_ = Utilities::width * 0.5 - rectangle_.getGlobalBounds().width * 0.5;
    positionY_ = Utilities::height * 0.33 - rectangle_.getGlobalBounds().height * 1.5;
    switch( buttonCounter )
    {
        case 0:
            rectangle_.setPosition( sf::Vector2f( positionX_, positionY_ ) );
            break;

        case 1:
            positionY_ += height_ * 2;
            rectangle_.setPosition( sf::Vector2f( positionX_, positionY_ ) );
            break;

        case 2:
            positionY_ += height_ * 4;
            rectangle_.setPosition( sf::Vector2f( positionX_, positionY_ ) );
            break;

        default:
            Logger::getLogger().write( Logger::INFO, "Błędna ilość przycisków" );
            break;
    }
}

void MenuButton::setTextPosition()
{
	float positionX = getPositionX() + ( rectangle_.getGlobalBounds().width - text_.getGlobalBounds().width ) * 0.5;
    float positionY = getPositionY() + ( rectangle_.getGlobalBounds().height - text_.getGlobalBounds().height ) * 0.5;
    text_.setPosition( sf::Vector2f( positionX, positionY ) );
}
