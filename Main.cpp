#include "header/Logger.hpp"
#include "header/Utilities.hpp"
#include "header/Window.hpp"
#include <SFML/Graphics.hpp>

int main( int argc, char** argv )
{
    Logger& logger = Logger::getLogger();
    Window myWindow = Window();
	sf::RenderWindow window( sf::VideoMode( myWindow.getWidth(), myWindow.getHeight() ), myWindow.getName() );

    logger.write( Utilities::getTimeStr(), Logger::INFO, "Aplikacja została uruchomiona" );
    while( window.isOpen() )
    {
        sf::Event event;
        while( window.pollEvent( event ) )
        {
            if( event.type == sf::Event::Closed )
            {
                window.close();
                logger.write( Utilities::getTimeStr(), Logger::INFO, "Aplikacja została pomyślnie zamknięta" );
            }
        }
        window.display();
    }
	
    return 0;
}
