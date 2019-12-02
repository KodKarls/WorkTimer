#include "header/Logger.hpp"
#include "header/screens.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int main( int argc, char** argv )
{
    Logger& logger = Logger::getLogger();
    std::vector< EachScreen* > screens;
    int screen = 0;

    sf::RenderWindow window( sf::VideoMode( Utilities::width, Utilities::height ), Utilities::appName );
    logger.write( Logger::INFO, "Aplikacja została uruchomiona" );

    SplashScreen splashScreen = SplashScreen();
    Menu menu = Menu();
    InfoScreen infoScreen = InfoScreen();
    ClockScreen clockScreen = ClockScreen();
    screens.push_back( &splashScreen );
    screens.push_back( &menu );
    screens.push_back( &infoScreen );
    screens.push_back( &clockScreen );

    while( screen >= 0 )
    {
        screen = screens[ screen ]->run( window );
    }

    return EXIT_SUCCESS;
}
