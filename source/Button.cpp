#include "../header/Button.hpp"

Button::Button()    :   width_( 350 ), height_( 100 ),
                        rectangle_( sf::RectangleShape() ),
                        font_( sf::Font() ), text_( sf::Text() )
{

}

Button::~Button()
{

}

sf::RectangleShape& Button::getShape()
{
    return rectangle_;
}

sf::Text& Button::getText()
{
    return text_;
}

void Button::setButtonColor()
{
    color_.setColor( 45, 58, 95, 230 );
    rectangle_.setFillColor( sf::Color( color_.red_, color_.green_, color_.blue_, color_.alpha_ ) );
}

void Button::setFont()
{
    if( !font_.loadFromFile( "resource/fonts/LifeSavers-Bold.ttf" ) )
    {
        Logger::getLogger().write( Logger::ERROR, "Czcionka nie została ustawiona" );
    }
}

void Button::setText()
{
    text_.setFont( font_ );
    text_.setCharacterSize( 38 );
    text_.setStyle( sf::Text::Bold );
    text_.setFillColor( sf::Color::Green );
    text_.setString( Utilities::setPolishLetters( name_ ) );
}

float Button::getPositionX()
{
    return positionX_;
}

float Button::getPositionY()
{
    return positionY_;
}
