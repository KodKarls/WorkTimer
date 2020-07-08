#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "StateMachine.hpp"

#include "SFML/Graphics/RenderWindow.hpp"

class Application
{
public:
	// Constructors
	Application();

 	// Destruktor
	~Application();

	// Core function
	void run();

private:
	// Init functions
	void initWindow();
	void initEngine();

	// State variables
	StateMachine 		m_machine;

	// Window variables
	sf::RenderWindow 	m_window;
};

#endif
