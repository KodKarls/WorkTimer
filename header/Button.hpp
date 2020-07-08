#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

enum class ButtonState : short unsigned
{
	BUTTON_IDLE = 0,
	BUTTON_HOVER,
	BUTTON_ACTIVE
};

class Button
{
public:
	// Constructors
	Button( float x, float y, float width, float height,
		sf::Font font, sf::String text, unsigned int characterSize,
		sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor );

	// Destructor
	~Button();

	// Functions
	void update( const sf::Vector2f& mousePos );
	void render( sf::RenderWindow& window );

	// Accessors
	const bool isPressed() const;

private:
	// Variables
	sf::RectangleShape 	shape;
	sf::Font 			font;
	sf::Text 			text;

	// Text colors
	sf::Color 			textIdleColor;
	sf::Color 			textHoverColor;
	sf::Color 			textActiveColor;

	// Button colors
	sf::Color 			idleColor;
	sf::Color 			hoverColor;
	sf::Color 			activeColor;

	// Button state
	ButtonState 		buttonState;
};

#endif