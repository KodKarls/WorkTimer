#include "StateMachine.hpp"
#include "CountdownState.hpp"
#include "ClockState.hpp"
#include "EndState.hpp"
#include "Utilities.hpp"

#include <iostream>

#include <SFML/Window/Event.hpp>

// Init functions
void CountdownState::initBackground()
{
	m_background.setSize( sf::Vector2f( static_cast< float >( m_window.getSize().x ), static_cast< float >( m_window.getSize().y ) ) );
	if( !m_backgroundTexture.loadFromFile( "res/images/Figaro3.png" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot load Figaro3 texture\n";
		return;
	}
	m_background.setTexture( &m_backgroundTexture );
}

void CountdownState::initButtons()
{
	// Prepare font
	sf::Font font;

	if( !font.loadFromFile( "res/fonts/LifeSavers-Bold.ttf" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot find font arial\n";
		return;
	}

	// Create buttons
	m_buttons[ "FIFTEEN_MINUTES" ] = new Button( 250.f, 150.f, 250.f, 50.f,
		font, "15 minut", 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 70, 70, 70, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);

	m_buttons[ "THIRTY_MINUTES" ] = new Button( 250.f, 250.f, 250.f, 50.f,
		font, "30 minut", 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 70, 70, 70, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);

	m_buttons[ "FORTY_FIVE_MINUTES" ] = new Button( 250.f, 350.f, 250.f, 50.f,
		font, "45 minut", 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 70, 70, 70, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);

	m_buttons[ "BACK_STATE" ] = new Button( 250.f, 500.f, 250.f, 50.f,
		font, Utitilies::setPolishSigns( "Powrót" ), 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 100, 100, 100, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);
}

// Constructors
CountdownState::CountdownState( StateMachine& machine, sf::RenderWindow& window, bool replace )
	: State( machine, window, replace )
{
	this->initBackground();
	this->initButtons();
}

// Destruktor
CountdownState::~CountdownState()
{
	for( auto it = m_buttons.begin() ; it != m_buttons.end(); ++it )
		delete it->second;
}

// Regular functions
void CountdownState::pause()
{
	std::cout << "CountdownState Pause\n";
}

void CountdownState::resume()
{
	std::cout << "CountdownState Resume\n";
}

void CountdownState::update()
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

void CountdownState::draw()
{
	// Clear the previous drawing
	m_window.clear();
	m_window.draw( m_background );
	this->renderButtons();
	m_window.display();
}

// Button functions
void CountdownState::renderButtons()
{
	for( auto &it : m_buttons )
		it.second->render( m_window );
}

void CountdownState::updateButtons()
{
	// Update all the buttons in the state and handles their functionality
	for( auto &it : m_buttons )
		it.second->update( m_mousePosView );


	// Set 15 minut
	if( m_buttons[ "FIFTEEN_MINUTES"]->isPressed() )
	{
		Utitilies::setTime( std::stoi( m_buttons[ "FIFTEEN_MINUTES" ]->getText().substr( 0, 2 ) ) );
		m_next = StateMachine::build< ClockState >( m_machine, m_window, false );
		sf::Mouse::setPosition( sf::Vector2i( 390, 280 ), m_window );
	}

	// Set 30 minut
	if( m_buttons[ "THIRTY_MINUTES" ]->isPressed() )
	{
		Utitilies::setTime( std::stoi( m_buttons[ "THIRTY_MINUTES" ]->getText().substr( 0, 2 ) ) );
		m_next = StateMachine::build< ClockState >( m_machine, m_window, false );
		sf::Mouse::setPosition( sf::Vector2i( 390, 280 ), m_window );
	}

	// Set 45 minut
	if( m_buttons[ "FORTY_FIVE_MINUTES" ]->isPressed() )
	{
		Utitilies::setTime( std::stoi( m_buttons[ "FORTY_FIVE_MINUTES" ]->getText().substr( 0, 2 ) ) );
		m_next = StateMachine::build< ClockState >( m_machine, m_window, false );
		sf::Mouse::setPosition( sf::Vector2i( 390, 280 ), m_window );
	}

	// Back to menu
	if( m_buttons[ "BACK_STATE" ]->isPressed() )
	{
		m_machine.lastState();
		sf::Mouse::setPosition( sf::Vector2i( 350, 130 ), m_window );
	}
}

// Mouse function
void CountdownState::updateMousePositions()
{
	m_mousePosScreen = sf::Mouse::getPosition();
	m_mousePosWindow = sf::Mouse::getPosition( m_window );
	m_mousePosView = m_window.mapPixelToCoords( sf::Mouse::getPosition( m_window ) );
}
