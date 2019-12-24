#ifndef MENU_HPP
#define MENU_HPP

#include "EachScreen.hpp"
#include "MenuButton.hpp"

class Menu : public EachScreen
{
public:
	Menu();
	virtual ~Menu();

	virtual int run( sf::RenderWindow &app ) override;

private:
	sf::Event event_;
    bool running_;
};

#endif
