#include "header/Window.hpp"
#include <SFML/Graphics.hpp>

int main( int argc, char** argv )
{
    Window myWindow = Window();
	sf::RenderWindow window( sf::VideoMode( myWindow.getWidth(), myWindow.getHeight() ), myWindow.getName() );

    while( window.isOpen() )
    {
        sf::Event event;
        while( window.pollEvent( event ) )
        {
            if( event.type == sf::Event::Closed )
                 window.close();
        } //while
        window.display();
    } //while
	
    return 0;
}
