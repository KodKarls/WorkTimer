#include <SFML/Graphics.hpp>

int main( int argc, char** argv )
{
	sf::RenderWindow okno(sf::VideoMode(520, 320), "WorkTimer");

    while( okno.isOpen() )
    {
        sf::Event event;
        while( okno.pollEvent( event ) )
        {
            if( event.type == sf::Event::Closed )
                 okno.close();
        } //while
        okno.display();
    } //while
	
    return 0;
}
