#include "SplashState.hpp"
#include "StateMachine.hpp"
#include "MenuState.hpp"
#include "Utilities.hpp"

#include <iostream>

#include <SFML/Window/Event.hpp>

// Init functions
void SplashState::initBackground()
{
	m_background.setSize( sf::Vector2f( static_cast< float >( m_window.getSize().x ), static_cast< float >( m_window.getSize().y ) ) );
	if( !m_backgroundTexture.loadFromFile( "res/images/Figaro0.png" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot load background texture\n";
		return;
	}
	m_background.setTexture( &m_backgroundTexture );
}

void SplashState::initFont()
{
	if( !m_font.loadFromFile( "res/fonts/Akronim-Regular.ttf" ) )
    {
        // Think about error logging system
		std::cout << "Error: cannot find font Akronim-Regular\n";
		return;
    }
}

void SplashState::initText()
{
	m_text.setFont( m_font );
    m_text.setCharacterSize( 102 );
    m_text.setFillColor( sf::Color::Blue );
    m_text.setStyle( sf::Text::Bold );
}

SplashState::SplashState( StateMachine& machine, sf::RenderWindow& window, bool replace )
	: State{ machine, window, replace }, m_letters{ "" }, m_letterCounter{ 0 }
{
	this->initBackground();
	this->initFont();
	this->initText();
}

SplashState::~SplashState()
{
	// Empty body
}

// Regular functions
void SplashState::pause()
{
	std::cout << "MenuState Pause\n";
}

void SplashState::resume()
{
	std::cout << "MenuState Resume\n";
}

void SplashState::update()
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

void SplashState::draw()
{
	// Clear the previous drawing
	m_window.clear();
	m_window.draw( m_background );
	m_window.draw( m_text );
	m_window.display();
}

// Animation function
void SplashState::doAnimation()
{
	if( m_clock.getElapsedTime().asMilliseconds() > 230.f )
	{
		if( m_letterCounter < Utitilies::APP_NAME.getSize() )
		{
			m_letters += Utitilies::APP_NAME.substring( m_letterCounter, 1 );
			++m_letterCounter;
			this->displayLetters();
			m_clock.restart();
		}
		else if( m_clock.getElapsedTime().asMilliseconds() > 1500.f )
		{
			m_next = StateMachine::build< MenuState >( m_machine, m_window, true );
			m_clock.restart();
		}
	}
}

void SplashState::displayLetters()
{
	m_text.setString( m_letters );
	m_text.setPosition( sf::Vector2f(
		m_window.getSize().x * 0.5 - m_text.getLocalBounds().width * 0.5,
		m_window.getSize().y * 0.5 - m_text.getLocalBounds().height
	));
}
