#ifndef SPLASH_SCREEN_HPP
#define SPLASH_SCREEN_HPP

#include "../header/Logger.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class SplashScreen
{
public:
    SplashScreen();
    ~SplashScreen();

    std::string getAppName();
    sf::Text getText();
    void setFont();
    void setTextStyle();
    void addLetter( int position );
    void setOutputText();
    int getLetterCounter();
    void setFinalTextStyle();

private:
    void setFontSize( int fontSize = 76 );
    int getFontSize();
    void setTextPosition();

    std::string appName_;
    sf::Font font_;
    sf::Text text_;
    int fontSize_;
    std::string outputText_;
    int letterCounter_;
};

#endif
