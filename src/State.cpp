#include "State.hpp"

// Constructors
State::State( StateMachine& machine, sf::RenderWindow& window, const bool replace )
	:	m_machine{ machine },
		m_window{ window },
		m_replacing{ replace }
{
	// Empty body
}

// Regular functions
std::unique_ptr< State > State::next()
{
	return std::move( m_next );
}

bool State::isReplacing() const
{
	return m_replacing;
}
