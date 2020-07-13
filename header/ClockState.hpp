#ifndef CLOCK_STATE_HPP
#define CLOCK_STATE_HPP

#include "Button.hpp"
#include "State.hpp"
#include "Animation.hpp"
#include "AudioSound.hpp"

class StateMachine;

class ClockState final : public State
{
public:
	// Constructors
	ClockState( StateMachine& machine, sf::RenderWindow& window, bool replace = true );

 	// Destruktor
	~ClockState();

	// Regular functions
	void pause() override;
	void resume() override;

	void update() override;
	void draw() override;

private:
	// Init functions
	void initVariables();
	void initBackground();
	void initTexture();
	void initAnimation();
	void initTexts();
	void initButtons();

	// Button functions
	void renderButtons();
	void updateButtons();

	// Mouse function
	void updateMousePositions();

	// Timer getters functions
	const int getMinuts();
	const int getSeconds();

	const int getDigitOfMinut();
	const int getDigitOfSecond();

	// Timer setters functions
	void setDigitOfMinut( const int& minuteDigit );
	void setDigitOfSecond( const int& secondDigit );

	// Regular functions
	void changeCountdownStatus();
	const bool& getCountdownStatus();

	// Animation functions
	void renderSprite();
	void countTime();
	void resetTime();
	void stopAudio();
	void resetClock();

 	// Background
	sf::RectangleShape 						m_background;
	sf::Texture 							m_backgroundTexture;

	// Texture
	sf::Texture								m_texture;

	// Animation
	std::map< std::string, Animation* >		m_pCountdownAnimation;
	sf::Clock								m_clock;
	bool 									m_countDownActive;

	// Timer
	int										m_minuts;
	int										m_seconds;

	int										m_minuteDigit;
	int										m_secondDigit;

	// Audio sound
	AudioSound								m_clockSound;

	// Texts
	sf::Font								m_colonFont;
	sf::Text								m_colon;

	sf::Font								m_endCountdownFont;
	sf::Text								m_endCountdownText;

	sf::Clock								m_endAnimationClock;

	// Buttons
	std::map< std::string, Button* > 		m_buttons;
};

#endif
