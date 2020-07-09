#include "StateMachine.hpp"
#include "MenuState.hpp"
#include "CountdownState.hpp"
#include "InfoState.hpp"
#include "Utilities.hpp"


#include <iostream>

#include <SFML/Window/Event.hpp>

// Init functions
void MenuState::initBackground()
{
	m_background.setSize( sf::Vector2f( static_cast< float >( m_window.getSize().x ), static_cast< float >( m_window.getSize().y ) ) );
	if( !m_backgroundTexture.loadFromFile( "res/images/Figaro1.png" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot load background texture\n";
		return;
	}
	m_background.setTexture( &m_backgroundTexture );
}

void MenuState::initButtons()
{
	// Prepare font
	sf::Font font;

	if( !font.loadFromFile( "res/fonts/LifeSavers-Bold.ttf" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot find font arial\n";
	}

	// Create buttons
	m_buttons[ "COUNTDOWN_STATE" ] = new Button( 120.f, 170.f, 450.f, 80.f,
		font, "Ustaw odliczanie", 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 70, 70, 70, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);

	m_buttons[ "INFO_STATE" ] = new Button( 205.f, 270.f, 300.f, 80.f,
		font, "Informacje", 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 70, 70, 70, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);

	m_buttons[ "EXIT_STATE" ] = new Button( 205.f, 470.f, 300.f, 80.f,
		font, Utitilies::setPolishSigns( "Wyjście" ), 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 100, 100, 100, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);
}

// Constructors
MenuState::MenuState( StateMachine& machine, sf::RenderWindow& window, bool replace )
	:	State{ machine, window, replace }
{
	this->initBackground();
	this->initButtons();
}

// Destruktor
MenuState::~MenuState()
{
	for( auto it = m_buttons.begin() ; it != m_buttons.end(); ++it )
		delete it->second;
}

// Regular functions
void MenuState::pause()
{
	std::cout << "MenuState Pause\n";
}

void MenuState::resume()
{
	std::cout << "MenuState Resume\n";
}

void MenuState::update()
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
	this->updateMousePositions();
	this->updateButtons();
}

void MenuState::draw()
{
	// Clear the previous drawing
	m_window.clear();
	m_window.draw( m_background );
	this->renderButtons();
	m_window.display();
}

// Button functions
void MenuState::renderButtons()
{
	for( auto &it : m_buttons )
		it.second->render( m_window );
}

void MenuState::updateButtons()
{
	// Update all the buttons in the state and handles their functionality
	for( auto &it : m_buttons )
		it.second->update( m_mousePosView );

	// Set countdown
	if( m_buttons[ "COUNTDOWN_STATE" ]->isPressed() )
		m_next = StateMachine::build< CountdownState >( m_machine, m_window, false );


	// Info
	if( m_buttons[ "INFO_STATE" ]->isPressed() )
		m_next = StateMachine::build< InfoState >( m_machine, m_window, false );

	// Quit the game
	if( m_buttons[ "EXIT_STATE" ]->isPressed() )
		m_machine.quit();
}

// Mouse function
void MenuState::updateMousePositions()
{
	m_mousePosScreen = sf::Mouse::getPosition();
	m_mousePosWindow = sf::Mouse::getPosition( m_window );
	m_mousePosView = m_window.mapPixelToCoords( sf::Mouse::getPosition( m_window ) );
}