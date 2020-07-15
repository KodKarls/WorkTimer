#ifndef SPLASH_STATE_HPP
#define SPLASH_STATE_HPP

#include "State.hpp"
#include "Button.hpp"

#include <SFML/Graphics/Texture.hpp>

class StateMachine;

class SplashState final : public State
{
public:
	// Constructors
	SplashState( StateMachine& machine, sf::RenderWindow& window, bool replace = true );

 	// Destruktor
	~SplashState();

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
	void displayLetters();

	// Background variables
	sf::Texture 						m_backgroundTexture;
	sf::RectangleShape 					m_background;

	// Animation variables
	sf::Font							m_font;
	sf::Text							m_text;
	sf::String							m_letters;
	unsigned short						m_letterCounter;

	sf::Clock							m_clock;
};

#endif
