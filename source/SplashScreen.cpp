#include "../header/SplashScreen.hpp"

SplashScreen::SplashScreen() :  appName_( Utilities::appName ),
                                font_( sf::Font() ), text_( sf::Text() ), fontSize_( 0 ),
                                outputText_( "" ), letterCounter_( 0 )
{
    setFontSize();
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

void SplashScreen::setTextStyle()
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

void SplashScreen::addLetter( int position )
{
    char letter = appName_.at( position );
    outputText_ += letter;
    letterCounter_++;
}

void SplashScreen::setOutputText()
{
    text_.setString( outputText_ );
    setTextPosition();
}

int SplashScreen::getLetterCounter()
{
    return letterCounter_;
}

void SplashScreen::setFinalTextStyle()
{
    text_.setStyle( sf::Text::Underlined );
    //float textWidth = text_.getGlobalBounds().width;
    //std::cout << textWidth << "\n";
}

