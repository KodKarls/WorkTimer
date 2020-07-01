#ifndef GAME_HPP
#define GAME_HPP

#include "MainMenuState.hpp"

class App
{
public:
	// Constructors
	App();

 	// Destruktor
	~App();

	// Regular functions
	void endApplication();

	// Update functions
	void updateDt();
	void updateSFMLEvents();
	void update();

	// Render function
	void render();

	// Core function
	void run();

private:
	// Init functions
	void initVariables();
	void initWindow();
	void initStates();

	// Window variables
	sf::RenderWindow* window;
	sf::Event sfEvent;
	std::vector< sf::VideoMode > videoModes;
	sf::ContextSettings windowSettings;

	// Update variables
	sf::Clock dtClock;
	float dt;

	// States variables
	std::stack< State* > states;
};

#endif
