#include "header/Logger.hpp"
#include "header/Utilities.hpp"
#include "header/Window.hpp"
#include "header/SplashScreen.hpp"
#include <SFML/Graphics.hpp>

int main( int argc, char** argv )
{
    Logger& logger = Logger::getLogger();
    Window myWindow = Window();
	sf::RenderWindow window( sf::VideoMode( myWindow.getWidth(), myWindow.getHeight() ), myWindow.getName() );
    logger.write( Utilities::getTimeStr(), Logger::INFO, "Aplikacja została uruchomiona" );

    SplashScreen splashScreen = SplashScreen();
    splashScreen.setName( myWindow.getName() );
    splashScreen.setFont();
    splashScreen.setTextStyle();
    splashScreen.setTextPosition();

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
        window.clear();
        if ( splashScreen.getLetterCounter() < splashScreen.getAppName().size() )
        {
            splashScreen.getLetterPosition( splashScreen.getLetterCounter() );
            splashScreen.setOutputText();
            window.draw( splashScreen.getText() );
        }
        else
        {
            splashScreen.setFinalTextStyle();
            window.draw( splashScreen.getText() );
        }
        window.display();
        splashScreen.sleep( 300 );
    }
	
    return EXIT_SUCCESS;
}
