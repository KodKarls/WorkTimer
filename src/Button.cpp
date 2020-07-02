#include "Button.hpp"

// Constructors
Button::Button( float x, float y, float width, float height,
		sf::Font* font, sf::String text, unsigned int characterSize,
		sf::Color textIdleColor, sf::Color textHoverColor, sf::Color textActiveColor,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor )
{
	this->buttonState = ButtonState::BUTTON_IDLE;

	this->shape.setPosition( sf::Vector2f( x, y ) );
	this->shape.setSize( sf::Vector2f( width, height ) );
	this->shape.setFillColor( idleColor );

	this->font = font;
	this->text.setFont( *this->font );
	this->text.setString( text );
	this->text.setFillColor( textIdleColor );
	this->text.setCharacterSize( characterSize );
	this->text.setPosition(
		this->shape.getPosition().x + this->shape.getGlobalBounds().width * 0.5f - this->text.getGlobalBounds().width * 0.5f,
		this->shape.getPosition().y + this->shape.getGlobalBounds().height * 0.5f - this->text.getGlobalBounds().height * 0.5f
	);

	this->textIdleColor = textIdleColor;
	this->textHoverColor = textHoverColor;
	this->textActiveColor = textActiveColor;

	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;
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
	this->buttonState = ButtonState::BUTTON_IDLE;

	// Hover
	if( this->shape.getGlobalBounds().contains( mousePos ) )
	{
		this->buttonState = ButtonState::BUTTON_HOVER;

		// Pressed
		if( sf::Mouse::isButtonPressed( sf::Mouse::Left ) )
		{
			this->buttonState = ButtonState::BUTTON_ACTIVE;
		}
	}

	switch( this->buttonState )
	{
	case ButtonState::BUTTON_IDLE:
		this->shape.setFillColor( this->idleColor );
		this->text.setFillColor( this->textIdleColor );
		break;

	case ButtonState::BUTTON_HOVER:
		this->shape.setFillColor( this->hoverColor );
		this->text.setFillColor( this->textHoverColor );
		break;

	case ButtonState::BUTTON_ACTIVE:
		this->shape.setFillColor( this->activeColor );
		this->text.setFillColor( this->textActiveColor );
		break;

	default:
		this->shape.setFillColor( sf::Color::Red );
		this->text.setFillColor( sf::Color::Blue );
		break;
	}
}

void Button::render( sf::RenderTarget* target )
{
	target->draw( this->shape );
	target->draw( this->text );
}

// Accessors
const bool Button::isPressed() const
{
	if( this->buttonState == ButtonState::BUTTON_ACTIVE )
		return true;

	return false;
}