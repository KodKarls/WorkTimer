#include "../header/InfoScreen.hpp"

InfoScreen::InfoScreen()    : 		infoText_( sf::Text() ), authorsText_( sf::Text() ),
                                    font_( sf::Font() ), fontSize_( 0 ),
								    event_( sf::Event() ), running_( true )
{
    // Empty body
}

InfoScreen::~InfoScreen()
{

}

void InfoScreen::setFont()
{
	if( !font_.loadFromFile( "resource/fonts/Caveat-Regular.ttf" ) )
    {
        Logger::getLogger().write( Logger::ERROR, "Nie udało się załadować czcionki" );
    }
}

void InfoScreen::setFontSize( int fontSize )
{
	fontSize_ = fontSize;
}

void InfoScreen::setText()
{
	infoText_.setFont( font_ );
	authorsText_.setFont( font_ );
    infoText_.setCharacterSize( getFontSize() );
    authorsText_.setCharacterSize( 22 );
    infoText_.setFillColor( sf::Color::Yellow );
    authorsText_.setFillColor( sf::Color::Yellow );
    infoText_.setStyle( sf::Text::Italic );
    authorsText_.setStyle( sf::Text::Bold );
	infoText_.setString( Utilities::setPolishLetters( Utilities::INFO_TEXT ) );
    authorsText_.setString( Utilities::setPolishLetters( Utilities::AUTHORS_TEXT ) );
}

void InfoScreen::setTextPosition()
{
	float positionX = Utilities::WIDTH * 0.5 - infoText_.getGlobalBounds().width * 0.5;
    float positionY = Utilities::HEIGHT * 0.33 - infoText_.getGlobalBounds().height;
    infoText_.setPosition( sf::Vector2f( positionX, positionY ) );

    positionX = Utilities::WIDTH - authorsText_.getGlobalBounds().width - 30;
    positionY = Utilities::HEIGHT - 50;
    authorsText_.setPosition( sf::Vector2f( positionX, positionY ) );
}

int InfoScreen::getFontSize()
{
	return fontSize_;
}

int InfoScreen::run( sf::RenderWindow &app )
{
    setFont();
    setFontSize();
    setText();
	setTextPosition();

    InfoButton backButton = InfoButton( Utilities::BACK_BUTTON, 250, 100 );

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
                        return 1;
                    }
                    else
                    {
                        Logger::getLogger().write( Logger::INFO, "Nie ma takiego zdarzenia!" );
                    }
                    break;
                }
            }
        }
        app.clear();
		app.draw( infoText_ );
        app.draw( authorsText_ );
        app.draw( backButton.getShape() );
        app.draw( backButton.getText() );
        app.display();
    }
    return -1;
}
