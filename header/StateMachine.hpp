#ifndef STATE_MACHINE_HPP
#define STATE_MACHINE_HPP

#include "State.hpp"

#include <memory>
#include <stack>

namespace sf
{
	class RenderWindow;
}

class StateMachine
{
public:
	// Constructors
	StateMachine();

	// Core function
	void run( std::unique_ptr< State > state );

	// Update functions
	void update();
	void draw();

	// Regular function
	void nextState();
	void lastState();

	bool running() const;
	void quit();

	template< typename T >
	static std::unique_ptr< T > build( StateMachine& machine, sf::RenderWindow& window, bool replace = true );

private:
	// Stack of states
	std::stack< std::unique_ptr< State > > m_states;

	bool m_resume;
	bool m_running;
};

template< typename T >
std::unique_ptr< T > StateMachine::build( StateMachine& machine, sf::RenderWindow& window, bool replace )
{
	return std::make_unique< T >( machine, window, replace );
}

#endif
