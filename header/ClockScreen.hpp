#ifndef CLOCK_SCREEN_HPP
#define CLOCK_SCREEN_HPP

#include "ClockButton.hpp"
#include "EachScreen.hpp"
#include <SFML/Graphics.hpp>

class ClockScreen : public EachScreen
{
public:
	ClockScreen();
	virtual ~ClockScreen();

	virtual int run( sf::RenderWindow &app ) override;

private:
	void loadTexture();
	void setTexture();

	sf::Texture texture_;
	sf::Sprite sprite_;

	sf::Event event_;
    bool running_;
};

#endif
