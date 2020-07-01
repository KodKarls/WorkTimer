#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

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

	// Window variables
	sf::RenderWindow* window;
	sf::Event sfEvent;
	std::vector< sf::VideoMode > videoModes;
	sf::ContextSettings windowSettings;

	// Update variables
	sf::Clock dtClock;
	float dt;
};

#endif
