#ifndef STATE_HPP
#define STATE_HPP

#include <memory>

#include <SFML/Window/Mouse.hpp>

class StateMachine;

namespace sf
{
	class RenderWindow;
}

class State
{
public:
	// Constructors
	State( StateMachine& machine, sf::RenderWindow& window, bool replace = true );
	State( const State& ) = delete;

	// Destructor
	virtual ~State() = default;

	// Overload operators
	State& operator=( const State& ) = delete;

	// State functions
	virtual void pause() = 0;
	virtual void resume() = 0;

	// Update functions
	virtual void update() = 0;
	virtual void draw() = 0;

	// Regular functions
	std::unique_ptr< State > next();
	bool isReplacing() const;

protected:
	// State variables
	StateMachine& 				m_machine;
	sf::RenderWindow& 			m_window;

	// Regular variables
	bool 						m_replacing;
	std::unique_ptr< State > 	m_next;

	// Mouse variables
	sf::Vector2i 				m_mousePosScreen;
	sf::Vector2i 				m_mousePosWindow;
	sf::Vector2f 				m_mousePosView;
};

#endif
