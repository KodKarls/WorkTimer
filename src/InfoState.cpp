#include "StateMachine.hpp"
#include "InfoState.hpp"
#include "EndState.hpp"
#include "Utilities.hpp"

#include <iostream>

#include <SFML/Window/Event.hpp>

// Init functions
void InfoState::initBackground()
{
	m_background.setSize( sf::Vector2f( static_cast< float >( m_window.getSize().x ), static_cast< float >( m_window.getSize().y ) ) );
	if( !m_backgroundTexture.loadFromFile( "res/images/Figaro2.png" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot load Figaro2 texture\n";
		return;
	}
	m_background.setTexture( &m_backgroundTexture );
}

void InfoState::initFont()
{
	if( !m_font.loadFromFile( "res/fonts/Akronim-Regular.ttf" ) )
    {
        // Think about error logging system
		std::cout << "Error: cannot find font Akronim-Regular\n";
		return;
    }
}

void InfoState::initText()
{
	m_text.setFont( m_font );
    m_text.setCharacterSize( 18 );
    m_text.setFillColor( sf::Color::Blue );
    m_text.setStyle( sf::Text::Bold );
	m_text.setString("authors : Carolinii & Paulinii");
	m_text.setPosition( sf::Vector2f( 40.f, 570.f ) );
}

void InfoState::initButtons()
{
	// Prepare font
	sf::Font font;

	if( !font.loadFromFile( "res/fonts/LifeSavers-Bold.ttf" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot find font LifeSavers Bold\n";
		return;
	}

	// Create buttons
	m_buttons[ "BACK_STATE" ] = new Button( 380.f, 500.f, 250.f, 50.f,
		font, Utitilies::setPolishSigns( "Powrót" ), 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 100, 100, 100, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);
}

// Constructors
InfoState::InfoState( StateMachine& machine, sf::RenderWindow& window, bool replace )
	: State{ machine, window, replace }
{
	this->initFont();
	this->initText();
	this->initBackground();
	this->initButtons();
}

// Destruktor
InfoState::~InfoState()
{
	for( auto it = m_buttons.begin() ; it != m_buttons.end(); ++it )
		delete it->second;
}

// Regular functions
void InfoState::pause()
{
	std::cout << "InfoState Pause\n";
}

void InfoState::resume()
{
	std::cout << "InfoState Resume\n";
}

void InfoState::update()
{
	// SFML events
	for( auto event = sf::Event{} ; m_window.pollEvent( event ); )
	{
		switch( event.type )
		{
		case sf::Event::Closed:
			m_next = StateMachine::build< EndState >( m_machine, m_window, true );
			break;

		default:
			break;
		}
	}

	// Our events
	this->updateMousePositions();
	this->updateButtons();
}

void InfoState::draw()
{
	// Clear the previous drawing
	m_window.clear();
	m_window.draw( m_background );
	m_window.draw( m_text );
	this->renderButtons();
	m_window.display();
}

// Button functions
void InfoState::renderButtons()
{
	for( auto &it : m_buttons )
		it.second->render( m_window );
}

void InfoState::updateButtons()
{
	// Update all the buttons in the state and handles their functionality
	for( auto &it : m_buttons )
		it.second->update( m_mousePosView );

	if( m_buttons[ "BACK_STATE" ]->isPressed() )
	{
		sf::Mouse::setPosition( sf::Vector2i( 350, 130 ), m_window );
		m_machine.lastState();
	}
}

// Mouse function
void InfoState::updateMousePositions()
{
	m_mousePosScreen = sf::Mouse::getPosition();
	m_mousePosWindow = sf::Mouse::getPosition( m_window );
	m_mousePosView = m_window.mapPixelToCoords( sf::Mouse::getPosition( m_window ) );
}
