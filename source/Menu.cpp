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
	Button bottomButton = Button( Utilities::bottomButton );

    while( running_ )
    {
        while( app.pollEvent( event_ ) )
        {
            if( event_.type == sf::Event::Closed )
            {
                return -1;
            }
        }
        app.clear();
        app.draw( topButton.getShape() );
        app.draw( topButton.getText() );
        app.draw( middleButton.getShape() );
        app.draw( middleButton.getText() );
        app.draw( bottomButton.getShape() );
        app.draw( bottomButton.getText() );
        app.display();
    }
    return -1;
}
