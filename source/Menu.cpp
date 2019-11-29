#include "../header/Menu.hpp"

Menu::Menu() :  event_( sf::Event() ), running_( true )
{

}

Menu::~Menu()
{

}

int Menu::run( sf::RenderWindow &app )
{
    Button topButton = Button( Utilities::topButton );
	Button middleButton = Button( Utilities::middleButton );
	Button exitButton = Button( Utilities::exitButton );

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
                    if( exitButton.getShape().getGlobalBounds().contains( mousePositionCoordinates ) )
                    {
                        app.close();
                        return -1;
                    }
                    break;
                }
                default:
                    Logger::getLogger().write( Logger::INFO, "Nie ma takiego zdarzenia!" );
                    break;
            }
        }
        app.clear();
        app.draw( topButton.getShape() );
        app.draw( topButton.getText() );
        app.draw( middleButton.getShape() );
        app.draw( middleButton.getText() );
        app.draw( exitButton.getShape() );
        app.draw( exitButton.getText() );
        app.display();
    }
    return -1;
}