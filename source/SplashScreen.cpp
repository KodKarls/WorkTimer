#include "../header/SplashScreen.hpp"

SplashScreen::SplashScreen() :  appName_( Utilities::appName ),
                                font_( sf::Font() ), fontSize_( 0 ),
                                text_( sf::Text() ), outputText_( "" ), letterCounter_( 0 ),
                                screenShow_( true ), running_( true ), event_( sf::Event() )
{
    setFont();
    setFontSize();
    setText();
}

SplashScreen::~SplashScreen()
{

}

void SplashScreen::setFont()
{
    if( !font_.loadFromFile( "resource/fonts/Akronim-Regular.ttf" ) )
    {
        std::cout << "Nie udalo sie wczytac czcionki...";
        Logger::getLogger().write( Logger::ERROR, "Czcionka nie została ustawiona" );
    }
}

void SplashScreen::setFontSize( int fontSize )
{
    fontSize_ = fontSize;
}

int SplashScreen::getFontSize()
{
    return fontSize_;
}

void SplashScreen::setText()
{
    text_.setFont( font_ );
    text_.setCharacterSize( getFontSize() );
    text_.setFillColor( sf::Color::Blue );
    text_.setStyle( sf::Text::Bold );
}

void SplashScreen::setTextPosition()
{
    float positionX = Utilities::width * 0.5 - text_.getGlobalBounds().width * 0.5;
    float positionY = Utilities::height * 0.5 - text_.getGlobalBounds().height;
    text_.setPosition( sf::Vector2f( positionX, positionY ) );
}

void SplashScreen::doAnimation()
{
    if( letterCounter_ < appName_.size() )
    {
        char letter = appName_.at( letterCounter_ );
        outputText_ += letter;
        letterCounter_++;
        text_.setString( outputText_ );
    }
    else
    {
        text_.setStyle( sf::Text::Underlined );
        screenShow_ = !screenShow_;
    }
    setTextPosition();
}

bool SplashScreen::checkIsShow()
{
    return screenShow_;
}

int SplashScreen::run( sf::RenderWindow &app )
{
    while( running_)
    {
        while( app.pollEvent( event_ ) )
        {
            // Zamknięcie okna
            if( event_.type == sf::Event::Closed )
            {
                app.close();
                return -1;
            }
        }
        app.clear();
        if ( checkIsShow() )
        {
            doAnimation();
            app.draw( text_ );
            Utilities::sleep( 300 );
        }
        else
        {
            doAnimation();
            app.draw( text_ );
            Utilities::sleep( 3000 );
            //app.close();
            app.clear();
            return 1;
        }
        app.display();
    }
    // Nigdy nie osiągniemy tego punkty ale zapobiegawczo
    return -1;
}
