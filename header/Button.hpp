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
	const bool isClick() const;
	const std::string getText() const;

	// Setters
	void changeClickStatus();
	void setPosition( float x, float y );
	void setText( sf::String text );

private:
	// Variables
	sf::RectangleShape 	m_shape;
	sf::Font 			m_font;
	sf::Text 			m_text;

	// Text colors
	sf::Color 			m_textIdleColor;
	sf::Color 			m_textHoverColor;
	sf::Color 			m_textActiveColor;

	// Button colors
	sf::Color 			m_idleColor;
	sf::Color 			m_hoverColor;
	sf::Color 			m_activeColor;

	// Button state
	ButtonState 		m_buttonState;

	bool				m_clickStatus;
};

#endif