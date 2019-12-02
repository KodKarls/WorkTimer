#include "../header/ClockScreen.hpp"

ClockScreen::ClockScreen()	:	event_( sf::Event() ), running_( true ),
								texture_( sf::Texture() ), sprite_( sf::Sprite() )
{
	loadTexture();
	setTexture();
}

ClockScreen::~ClockScreen()
{

}

void ClockScreen::loadTexture()
{
	if( !texture_.loadFromFile("resource/image/clock.jpg") )
    {
        Logger::getLogger().write( Logger::ERROR, "Nie udało się załadować tekstury" );
    }
}

void ClockScreen::setTexture()
{
	sprite_.setTexture( texture_ );
	sprite_.setPosition( sf::Vector2f( 187.5, 75 ) );
}

int ClockScreen::run( sf::RenderWindow &app )
{
	Button backButton = Button( Utilities::backButton, 250, 100 );

    while( running_ )
    {
        while( app.pollEvent( event_ ) )
        {
            switch( event_.type )
            {
                case sf::Event::Closed:
                {
                    app.close();
                    return -1;
                    break;
                }
                case sf::Event::MouseButtonPressed:
                {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition( app );
                    sf::Vector2f mousePositionCoordinates( mousePosition.x, mousePosition.y );
                    if( backButton.getShape().getGlobalBounds().contains( mousePositionCoordinates ) )
                    {
                        backButton.setButtonCounter( 0 );
                        return 1;
                    }
                }
                default:
                {
                    Logger::getLogger().write( Logger::INFO, "Nie ma takiego zdarzenia!" );
                    break;
                }
            }
        }
        app.clear();
        app.draw( backButton.getShape() );
        app.draw( backButton.getText() );
		app.draw( sprite_ );
        app.display();
    }
    return -1;
}
