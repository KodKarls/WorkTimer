#ifndef INFO_SCREEN_HPP
#define INFO_SCREEN_HPP

#include "Button.hpp"
#include "EachScreen.hpp"
#include <SFML/Graphics.hpp>

class InfoScreen : public EachScreen
{
public:
	InfoScreen();
	virtual ~InfoScreen();

    virtual int run( sf::RenderWindow &app ) override;

private:
	int getFontSize();
    void setFont();
    void setFontSize( int fontSize = 40 );
    void setText();
    void setTextPosition();

	sf::Text infoText_;
    sf::Text authorsText_;
    sf::Font font_;
    int fontSize_;

	sf::Event event_;
    bool running_;
};

#endif
