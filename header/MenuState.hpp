#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include "State.hpp"
//#include "Button.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

class StateMachine;

namespace sf
{
	class RenderWindow;
}

class MenuState final : public State
{
public:
	// Constructors
	MenuState( StateMachine& machine, sf::RenderWindow& window, bool replace = true );

	void pause() override;
	void resume() override;

	void update() override;
	void draw() override;

private:
	// Init functions
	void initBackground( sf::RenderWindow& window );
	//void initButtons();

	// Variables
	sf::Texture m_backgroundTexture;
	sf::RectangleShape m_background;

	// Buttons
	//std::map< std::string, Button* > buttons;
};

#endif
