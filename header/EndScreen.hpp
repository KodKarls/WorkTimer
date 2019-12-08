#ifndef END_SCREEN_HPP
#define END_SCREEN_HPP

#include "Logger.hpp"
#include "EachScreen.hpp"
#include <SFML/Graphics.hpp>

class EndScreen : public EachScreen
{
public:
	EndScreen();
	virtual ~EndScreen();

	virtual int run( sf::RenderWindow &app ) override;

private:
	int getFontSize();
    void setFont();
    void setFontSize( int fontSize = 90 );
    void setText();
    void setTextPosition();

	sf::Text endText_;
    sf::Font font_;
    int fontSize_;

	sf::Event event_;
    bool running_;
};

#endif
