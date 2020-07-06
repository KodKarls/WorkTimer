#ifndef MAINMENUSTATE_HPP
#define MAINMENUSTATE_HPP

#include "Button.hpp"

class MainMenuState : public State
{
public:
	// Constructors
	MainMenuState( sf::RenderWindow* window, std::stack< State* >* states );

	// Destructor
	~MainMenuState();

	// Update functions
	void update( const float& dt ) override;
	void updateInput( const float& dt ) override;
	void updateButtons();

	// Render functions
	void render( sf::RenderTarget* target = nullptr ) override;
	void renderButtons( sf::RenderTarget* target = nullptr );

private:
	// Init functions
	void initVariables();
	void initBackground();
	void initFonts();
	void initButtons();

	// Variables
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	sf::Font font;

	// Buttons
	std::map< std::string, Button* > buttons;
};

#endif
