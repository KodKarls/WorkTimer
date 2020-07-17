#include "EndState.hpp"
#include "StateMachine.hpp"

#include <iostream>

#include <SFML/Window/Event.hpp>

// Init functions
void EndState::initBackground()
{
	m_background.setSize( sf::Vector2f( static_cast< float >( m_window.getSize().x ), static_cast< float >( m_window.getSize().y ) ) );
	if( !m_backgroundTexture.loadFromFile( "res/images/FigaroEnd2.png" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot load figaro end 2 texture\n";
		return;
	}
	m_background.setTexture( &m_backgroundTexture );
}

void EndState::initFont()
{
	if( !m_font.loadFromFile( "res/fonts/Akronim-Regular.ttf" ) )
    {
        // Think about error logging system
		std::cout << "Error: cannot find font Akronim-Regular\n";
		return;
    }
}

void EndState::initText()
{
	m_text.setFont( m_font );
    m_text.setCharacterSize( 72 );
    m_text.setFillColor( sf::Color::Red );
    m_text.setStyle( sf::Text::Bold );
	m_text.setString( "Do zobaczania" );
	m_text.setPosition( sf::Vector2f(
		m_window.getSize().x * 0.65 - m_text.getLocalBounds().width * 0.5,
		m_window.getSize().y * 0.15 - m_text.getLocalBounds().height
	));
}

// Constructors
EndState::EndState( StateMachine& machine, sf::RenderWindow& window, bool replace )
	: State{ machine, window, replace }
{
	this->initBackground();
	this->initFont();
	this->initText();
}

// Destruktor
EndState::~EndState()
{
	// Empty body
}

// Regular functions
void EndState::pause()
{
	std::cout << "MenuState Pause\n";
}

void EndState::resume()
{
	std::cout << "MenuState Resume\n";
}

void EndState::update()
{
	// SFML events
	for( auto event = sf::Event{} ; m_window.pollEvent( event ); )
	{
		switch( event.type )
		{
		case sf::Event::Closed:
			m_machine.quit();
			break;

		default:
			break;
		}
	}

	// Our events
	this->doAnimation();
}

void EndState::draw()
{
	// Clear the previous drawing
	m_window.clear();
	m_window.draw( m_background );
	m_window.draw( m_text );
	m_window.display();
}

// Animation function
void EndState::doAnimation()
{
	if( m_clock.getElapsedTime().asMilliseconds() > 1500.f )
	{
		m_machine.quit();
		m_clock.restart();
	}
}
