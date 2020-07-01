#include "State.hpp"

State::State( sf::RenderWindow* window, std::stack< State* >* states )
{
	this->window = window;
	this->states = states;
	this->quit = false;
}

State::~State()
{
	// Empty body
}

// Update functions
void State::updateMousePositions()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition( *this->window );
	this->mousePosView = this->window->mapPixelToCoords( sf::Mouse::getPosition( *this->window ) );
}

// Regular functions
const bool& State::getQuit() const
{
	return this->quit;
}

void State::endState()
{
	this->quit = true;
}