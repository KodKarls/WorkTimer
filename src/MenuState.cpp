#include "StateMachine.hpp"
#include "MenuState.hpp"
#include "Utilities.hpp"

#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

// Init functions
void MenuState::initBackground()
{
	this->m_background.setSize( sf::Vector2f( static_cast< float >( m_window.getSize().x ), static_cast< float >( m_window.getSize().y ) ) );
	if( !this->m_backgroundTexture.loadFromFile( "res/images/Figaro1.png" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot load background texture\n";
		return;
	}
	this->m_background.setTexture( &this->m_backgroundTexture );
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
	this->m_buttons[ "COUNTDOWN_STATE" ] = new Button( 120.f, 170.f, 450.f, 80.f,
		font, "Ustaw odliczanie", 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 70, 70, 70, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);

	this->m_buttons[ "INFO_STATE" ] = new Button( 205.f, 270.f, 300.f, 80.f,
		font, "Informacje", 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 70, 70, 70, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);

	this->m_buttons[ "EXIT_STATE" ] = new Button( 205.f, 470.f, 300.f, 80.f,
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
	this->updateMousePositions();
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
	for( auto &it : this->m_buttons )
		it.second->render( m_window );
}

void MenuState::updateButtons()
{
	// Update all the buttons in the state and handles their functionality
	for( auto &it : this->m_buttons )
	{
		it.second->update( this->mousePosView );
	}

	// Set countdown


	// Info


	// Quit the game
	if( this->m_buttons[ "EXIT_STATE" ]->isPressed() )
		this->m_machine.quit();
}

// Mouse function
void MenuState::updateMousePositions()
{
	this->mousePosScreen = sf::Mouse::getPosition();
	this->mousePosWindow = sf::Mouse::getPosition( this->m_window );
	this->mousePosView = this->m_window.mapPixelToCoords( sf::Mouse::getPosition( this->m_window ) );
}