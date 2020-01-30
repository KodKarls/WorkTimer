#include "../header/Menu.hpp"

Menu::Menu() :  event_( sf::Event() ), running_( true )
{

}

Menu::~Menu()
{

}

int Menu::run( sf::RenderWindow &app )
{
    MenuButton countdownButton = MenuButton( Utilities::COUNTDOWN_BUTTON );
    MenuButton infoButton = MenuButton( Utilities::INFO_BUTTON );
    MenuButton exitButton = MenuButton( Utilities::EXIT_BUTTON );

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
                        return 4;
                    }
                    else if( infoButton.getShape().getGlobalBounds().contains( mousePositionCoordinates ) )
                    {
                        return 2;
                    }
                    else if( countdownButton.getShape().getGlobalBounds().contains( mousePositionCoordinates ) )
                    {
                        return 3;
                    }
                    break;
                }
                default:
                {
                    Logger::getLogger().write( Logger::INFO, "Nie ma takiego zdarzenia!" );
                    break;
                }
            }
        }
        app.clear();
        app.draw( countdownButton.getShape() );
        app.draw( countdownButton.getText() );
        app.draw( infoButton.getShape() );
        app.draw( infoButton.getText() );
        app.draw( exitButton.getShape() );
        app.draw( exitButton.getText() );
        app.display();
    }
    return -1;
}
