#include "../header/SplashScreen.hpp"

SplashScreen::SplashScreen() :  appName_( Utilities::appName ),
                                font_( sf::Font() ), text_( sf::Text() ),
                                outputText_( "" ), letterCounter_( 0 )
{

}

SplashScreen::~SplashScreen()
{

}

std::string SplashScreen::getAppName()
{
    return appName_;
}

sf::Text SplashScreen::getText()
{
    return text_;
}

void SplashScreen::setFont()
{
    if( !font_.loadFromFile( "resource/fonts/YeonSung/YeonSung-Regular.ttf" ) )
    {
        std::cout << "Nie udalo sie wczytac czcionki...";
        Logger::getLogger().write( Utilities::getTimeStr(), Logger::ERROR, "Czcionka nie została ustawiona" );
    }
}

void SplashScreen::setTextStyle()
{
    text_.setFont( font_ );
    text_.setCharacterSize( 76 );
    text_.setFillColor( sf::Color::Blue );
    text_.setStyle( sf::Text::Bold );
}

void SplashScreen::setTextPosition()
{
    text_.setPosition( sf::Vector2f( 132, 224 ) );
}

void SplashScreen::addLetter( int position )
{
    char letter = appName_.at( position );
    outputText_ += letter;
    letterCounter_++;
}

void SplashScreen::setOutputText()
{
    text_.setString( outputText_ );
}

int SplashScreen::getLetterCounter()
{
    return letterCounter_;
}

void SplashScreen::setFinalTextStyle()
{
    text_.setStyle( sf::Text::Underlined );
}

void SplashScreen::sleep( int delay )
{
    std::this_thread::sleep_for( std::chrono::milliseconds( delay ) );
}
