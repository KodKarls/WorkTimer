#ifndef SPLASH_SCREEN_HPP
#define SPLASH_SCREEN_HPP

#include "../header/Logger.hpp"
#include "../header/Utilities.hpp"
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
    void setTextPosition();
    void addLetter( int position );
    void setOutputText();
    int getLetterCounter();
    void setFinalTextStyle();

private:
    std::string appName_;
    sf::Font font_;
    sf::Text text_;
    std::string outputText_;
    int letterCounter_;
};

#endif
