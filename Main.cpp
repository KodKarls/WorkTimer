#include "header/Logger.hpp"
#include "header/screens.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

int main( int argc, char** argv )
{
    Logger& logger = Logger::getLogger();
    // Zmienne aplikacji
    std::vector< EachScreen* > screens;
    int screen = 0;

    // Tworzenie okna
    sf::RenderWindow window( sf::VideoMode( Utilities::width, Utilities::height ), Utilities::appName );
    logger.write( Logger::INFO, "Aplikacja została uruchomiona" );

    // Przygotowanie ekranów
    SplashScreen splashScreen = SplashScreen();
    Menu menu = Menu();
    screens.push_back( &splashScreen );
    screens.push_back( &menu );

    // Główna pętla
    while( screen >= 0 )
    {
        screen = screens[ screen ]->run( window );
    }

    return EXIT_SUCCESS;
}
