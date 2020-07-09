#ifndef COUNTDOWN_STATE_HPP
#define COUNTDOWN_STATE_HPP

#include "State.hpp"
#include "Button.hpp"

#include <SFML/Graphics/Texture.hpp>

class StateMachine;

class CountdownState final : public State
{
public:
	// Constructors
	CountdownState( StateMachine& machine, sf::RenderWindow& window, bool replace = true );

	// Destruktor
	~CountdownState();

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
	sf::Texture 						m_backgroundTexture;
	sf::RectangleShape 					m_background;

	// Buttons
	std::map< std::string, Button* > 	m_buttons;
};

#endif
