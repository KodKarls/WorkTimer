#ifndef INFOSTATE_HPP
#define INFOSTATE_HPP

#include "Button.hpp"
#include "State.hpp"

#include <SFML/Graphics/Texture.hpp>

class StateMachine;

class InfoState final : public State
{
public:
 	// Constructors
 	InfoState(StateMachine& machine, sf::RenderWindow& window, bool replace = true);

  	// Destruktor
 	~InfoState();

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
