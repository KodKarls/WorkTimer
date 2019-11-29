#ifndef SPLASH_SCREEN_HPP
#define SPLASH_SCREEN_HPP

#include "Logger.hpp"
#include "EachScreen.hpp"
#include <SFML/Graphics.hpp>

class SplashScreen : public EachScreen
{
public:
    SplashScreen();
    virtual ~SplashScreen();

    void doAnimation();
    bool checkIsShow();

    virtual int run( sf::RenderWindow &app ) override;

private:
    int getFontSize();
    void setFont();
    void setFontSize( int fontSize = 102 );
    void setText();
    void setTextPosition();

    std::string appName_;
    sf::Font font_;
    int fontSize_;
    sf::Text text_;
    std::string outputText_;
    int letterCounter_;
    bool screenShow_;

    sf::Event event_;
    bool running_;
};

#endif
