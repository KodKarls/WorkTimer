#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Animation
{
public:
	// Constructors
	Animation( 	sf::Texture& texture, int startFrameX, int startFrameY,
				int width, int height, float posX, float posY );

 	// Destruktor
	~Animation();

	// Render function
	void render( sf::RenderWindow& window );

	// Regular functions
	void setFrame( int frameX );
	void play();
	void reset();

private:
	// Sprite sheet
	sf::Texture& 						m_texture;
	sf::Sprite							m_sprite;
	float								m_posX;
	float								m_posY;

	sf::IntRect							m_startRectSourceSprite;
	int 								m_startFrameX;
	int 								m_startFrameY;

	sf::IntRect							m_currentRectSourceSprite;
	int 								m_currentFrameX;
	int 								m_currentFrameY;

	int 								m_width;
	int 								m_height;
};

#endif
