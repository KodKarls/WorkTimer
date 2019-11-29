#include "../header/Button.hpp"

int Button::buttonCounter = 0;

void Button::setButtonCounter( int counter )
{
    buttonCounter = counter;
}

Button::Button( sf::RenderWindow& window, std::string name )      :     width_( 350 ), height_( 100 ),
                                                                        rectangle_( sf::RectangleShape() ),
                                                                        font_( sf::Font() ), text_( sf::Text() ),
                                                                        name_( name ),
                                                                        positionX_( 0 ), positionY_( 0 )
{
    rectangle_.setSize( sf::Vector2f( width_, height_ ) );
    setButtonColor();
    setButtonPosition();
    setFont();
    setText();
    setTextPosition();
    buttonCounter++;
}

Button::Button( std::string name )                              :       width_( 350 ), height_( 100 ),
                                                                        rectangle_( sf::RectangleShape() ),
                                                                        font_( sf::Font() ), text_( sf::Text() ),
                                                                        name_( name ),
                                                                        positionX_( 0 ), positionY_( 0 )
{
    rectangle_.setSize( sf::Vector2f( width_, height_ ) );
    setButtonColor();
    setButtonPosition();
    setFont();
    setText();
    setTextPosition();
    buttonCounter++;
}

Button::Button( std::string name, int width, int height )       :       width_( width ), height_( height ),
                                                                        rectangle_( sf::RectangleShape() ),
                                                                        font_( sf::Font() ), text_( sf::Text() ),
                                                                        name_( name ),
                                                                        positionX_( 0 ), positionY_( 0 )
{
    rectangle_.setSize( sf::Vector2f( width_, height_ ) );
    setButtonColor();
    setButtonPosition();
    setFont();
    setText();
    setTextPosition();
    buttonCounter++;
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

void Button::setButtonPosition()
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

        case 3:
            positionY_ += height_ * 2 + 70;
            rectangle_.setPosition( sf::Vector2f( positionX_, positionY_ ) );
            break;

        default:
            Logger::getLogger().write( Logger::INFO, "Błędna ilość przycisków" );
            break;
    }
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

void Button::setTextPosition()
{
    float positionX = getPositionX() + ( rectangle_.getGlobalBounds().width - text_.getGlobalBounds().width ) * 0.5;
    float positionY = getPositionY() + ( rectangle_.getGlobalBounds().height - text_.getGlobalBounds().height ) * 0.5;
    text_.setPosition( sf::Vector2f( positionX, positionY ) );
}

float Button::getPositionX()
{
    return positionX_;
}

float Button::getPositionY()
{
    return positionY_;
}
