#ifndef CLOCK_SCREEN_HPP
#define CLOCK_SCREEN_HPP

#include "ClockBlock.hpp"
#include "ClockButton.hpp"
#include "ChooseButton.hpp"
#include "EachScreen.hpp"
#include <SFML/Graphics.hpp>

class ClockScreen : public EachScreen
{
public:
	ClockScreen();
	virtual ~ClockScreen();

	virtual int run( sf::RenderWindow &app ) override;

private:
	void prepareMinutClockBlocks();
	void prepareSecondClockBlocks();
	void setColonText();

	std::vector< ClockBlock > minutClockBlocks;
	std::vector< ClockBlock > secondClockBlocks;
	sf::Text clockColonText_;
	sf::Font font_;
	sf::Event event_;
    bool running_;
};

#endif
