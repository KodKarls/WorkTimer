#include "Animation.hpp"

// Constructors
Animation::Animation( 	sf::Texture& texture, int startFrameX, int startFrameY,
						int width, int height, float posX, float posY )
	: 	m_texture{ texture }, m_posX{ posX }, m_posY{ posY },
		m_startFrameX{ startFrameX }, m_startFrameY{ startFrameY },
		m_currentFrameX{ startFrameX }, m_currentFrameY{ startFrameY },
		m_width{ width }, m_height{ height }
{
	m_startRectSourceSprite = sf::IntRect{ startFrameX * width, startFrameY * height, width, height };
	m_currentRectSourceSprite = m_startRectSourceSprite;
	m_sprite = sf::Sprite{ m_texture, m_startRectSourceSprite };
	m_sprite.setPosition( sf::Vector2f( m_posX, m_posY ) );
}

// Destruktor
Animation::~Animation()
{
	// Empty body
}

// Render function
void Animation::render( sf::RenderWindow& window )
{
	window.draw( m_sprite );
}

// Regular functions
void Animation::setFrame( int frameX )
{
	m_currentRectSourceSprite.left = frameX * m_width;
}

void Animation::play()
{
	m_sprite.setTextureRect( m_currentRectSourceSprite );
}

void Animation::reset()
{
	m_currentRectSourceSprite = m_startRectSourceSprite;
	m_sprite = sf::Sprite{ m_texture, m_currentRectSourceSprite };
	m_sprite.setPosition( sf::Vector2f( m_posX, m_posY ) );
}
