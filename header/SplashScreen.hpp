#ifndef SPLASH_SCREEN_HPP
#define SPLASH_SCREEN_HPP

#include "../header/Logger.hpp"
#include "../header/Utilities.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include <chrono>
#include <thread>

class SplashScreen
{
public:
    SplashScreen();
    ~SplashScreen();

    void setName( std::string name );
    std::string getAppName();
    sf::Text getText();
    void setFont();
    void setTextStyle();
    void setTextPosition();
    void getLetterPosition( int position );
    void setOutputText();
    int getLetterCounter();
    void setFinalTextStyle();
    void sleep( int delay );

private:
    std::string appName_;
    sf::Font font_;
    sf::Text text_;
    std::string outputText_;
    int letterCounter_;
};

#endif
