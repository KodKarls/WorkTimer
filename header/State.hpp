#ifndef STATE_HPP
#define STATE_HPP

#include "Utilities.hpp"

class State
{
public:
	// Constructors
	State( sf::RenderWindow* window, std::stack< State* >* states );

	// Destructor
	virtual ~State();

	// Update functions
	virtual void update( const float& dt ) = 0;
	virtual void updateInput( const float& dt ) = 0;
	virtual void updateMousePositions();

	// Render functions
	virtual void render( sf::RenderTarget* target = nullptr ) = 0;

	// Regular functions
	const bool& getQuit() const;
	void endState();

protected:
	// State variables
	std::stack< State* >* states;
	sf::RenderWindow* window;
	bool quit;

	// Mouse variables
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	// Resource variables
	std::map< std::string, sf::Texture > textures;
};

#endif
