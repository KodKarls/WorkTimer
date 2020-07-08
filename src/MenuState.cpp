#include "StateMachine.hpp"
#include "MenuState.hpp"
#include "Utilities.hpp"

#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

// Init functions
void MenuState::initBackground( sf::RenderWindow& window )
{
	this->m_background.setSize( sf::Vector2f( static_cast< float >( window.getSize().x ), static_cast< float >( window.getSize().y ) ) );
	if( !this->m_backgroundTexture.loadFromFile( "res/images/Figaro1.png" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot load background texture\n";
		return;
	}
	this->m_background.setTexture( &this->m_backgroundTexture );
}

// void MenuState::initButtons()
// {
// 	sf::Font* font = nullptr;

// 	if( !font->loadFromFile( "res/fonts/LifeSavers-Bold.ttf" ) )
// 	{
// 		// Think about error logging system
// 		std::cout << "Error: cannot find font arial\n";
// 	}

// 	this->buttons[ "COUNTDOWN_STATE" ] = new Button( 250.f, 170.f, 250.f, 50.f,
// 		font, "Ustaw odliczanie", 52,
// 		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
// 		sf::Color( 70, 70, 70, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
// 	);

// 	this->buttons[ "INFO_STATE" ] = new Button( 250.f, 270.f, 250.f, 50.f,
// 		font, "Informacje", 52,
// 		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
// 		sf::Color( 70, 70, 70, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
// 	);

// 	this->buttons[ "EXIT_STATE" ] = new Button( 250.f, 470.f, 250.f, 50.f,
// 		font, Utitilies::setPolishSigns( "Wyjście" ), 52,
// 		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
// 		sf::Color( 100, 100, 100, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
// 	);
// }

// Constructors
MenuState::MenuState( StateMachine& machine, sf::RenderWindow& window, bool replace )
	:	State{ machine, window, replace }
{
	this->initBackground( window );
	//this->initButtons();
}

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
}

void MenuState::draw()
{
	// Clear the previous deawing
	m_window.clear();
	m_window.draw( m_background );
	m_window.display();
}
