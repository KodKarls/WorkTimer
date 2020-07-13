#include "Button.hpp"

#include <SFML/Window/Mouse.hpp>

// Constructors
Button::Button( float x, float y, float width, float height,
		sf::Font font, sf::String text, unsigned int characterSize,
		sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor )
{
	m_buttonState = ButtonState::BUTTON_IDLE;
	m_clickStatus = false;

	m_shape.setPosition( sf::Vector2f( x, y ) );
	m_shape.setSize( sf::Vector2f( width, height ) );
	m_shape.setFillColor( idleColor );

	m_font = font;
	m_text.setFont( m_font );
	m_text.setString( text );
	m_text.setFillColor( textIdleColor );
	m_text.setCharacterSize( characterSize );
	m_text.setPosition(
		m_shape.getPosition().x + m_shape.getGlobalBounds().width * 0.5f - m_text.getGlobalBounds().width * 0.5f,
		m_shape.getPosition().y + m_shape.getGlobalBounds().height * 0.5f - m_text.getGlobalBounds().height * 0.6f
	);

	m_textIdleColor = textIdleColor;
	m_textHoverColor = textHoverColor;
	m_textActiveColor = textActiveColor;

	m_idleColor = idleColor;
	m_hoverColor = hoverColor;
	m_activeColor = activeColor;
}

// Destructor
Button::~Button()
{
	// Empty body
}

// Functions
void Button::update( const sf::Vector2f& mousePos )
{
	// Update the booleans for hover and pressed

	// Idle
	m_buttonState = ButtonState::BUTTON_IDLE;

	// Hover
	if( m_shape.getGlobalBounds().contains( mousePos ) )
	{
		m_buttonState = ButtonState::BUTTON_HOVER;

		// Pressed
		if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
		{
			m_buttonState = ButtonState::BUTTON_ACTIVE;
		}
	}

	switch( m_buttonState )
	{
	case ButtonState::BUTTON_IDLE:
		m_shape.setFillColor( m_idleColor );
		m_text.setFillColor( m_textIdleColor );
		break;

	case ButtonState::BUTTON_HOVER:
		m_shape.setFillColor( m_hoverColor );
		m_text.setFillColor( m_textHoverColor );
		break;

	case ButtonState::BUTTON_ACTIVE:
		m_shape.setFillColor( m_activeColor );
		m_text.setFillColor( m_textActiveColor );
		break;

	default:
		m_shape.setFillColor( sf::Color::Red );
		m_text.setFillColor( sf::Color::Blue );
		break;
	}
}

void Button::render( sf::RenderWindow& window )
{
	window.draw( m_shape );
	window.draw( m_text );
}

// Accessors
const bool Button::isPressed() const
{
	if( m_buttonState == ButtonState::BUTTON_ACTIVE )
		return true;

	return false;
}

const bool Button::isClick() const
{
	return m_clickStatus;
}

const std::string Button::getText() const
{
	return m_text.getString();
}

// Setters
void Button::changeClickStatus()
{
	m_clickStatus = !m_clickStatus;
}

void Button::setPosition( float x, float y )
{
	m_shape.setPosition( sf::Vector2f( x, y ) );
	m_text.setPosition(
		m_shape.getPosition().x + m_shape.getGlobalBounds().width * 0.5f - m_text.getGlobalBounds().width * 0.5f,
		m_shape.getPosition().y + m_shape.getGlobalBounds().height * 0.5f - m_text.getGlobalBounds().height * 0.6f
	);
}

void Button::setText( sf::String text )
{
	m_text.setString( text );
}