#ifndef END_STATE_HPP
#define END_STATE_HPP

#include "State.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>

class StateMachine;

class EndState final : public State
{
public:
	// Constructors
	EndState( StateMachine& machine, sf::RenderWindow& window, bool replace = true );

 	// Destruktor
	~EndState();

	// Regular functions
	void pause() override;
	void resume() override;

	void update() override;
	void draw() override;

private:
	// Init functions
	void initBackground();
	void initFont();
	void initText();

	// Animation function
	void doAnimation();

	// Background variables
	sf::Texture 						m_backgroundTexture;
	sf::RectangleShape 					m_background;

	// Animation variables
	sf::Font							m_font;
	sf::Text							m_text;

	sf::Clock							m_clock;
};

#endif
