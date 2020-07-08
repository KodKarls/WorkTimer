#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include "State.hpp"
#include "Button.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>

class StateMachine;

class MenuState final : public State
{
public:
	// Constructors
	MenuState( StateMachine& machine, sf::RenderWindow& window, bool replace = true );

	// Regular functions
	void pause() override;
	void resume() override;

	void update() override;
	void draw() override;

	// Button functions
	void renderButtons();
	void updateButtons();

	// Mouse function
	void updateMousePositions();

private:
	// Init functions
	void initBackground();
	void initButtons();

	// Variables
	sf::Texture m_backgroundTexture;
	sf::RectangleShape m_background;

	// Buttons
	std::map< std::string, Button* > m_buttons;
};

#endif
