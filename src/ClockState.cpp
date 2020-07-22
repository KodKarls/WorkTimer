#include "StateMachine.hpp"
#include "ClockState.hpp"
#include "EndState.hpp"
#include "Utilities.hpp"

#include <iostream>

#include <SFML/Window/Event.hpp>

// Init functions
void ClockState::initVariables()
{
	m_countDownActive = false;
	m_minuts = Utitilies::getTime();
	m_seconds = 0;
	m_minuteDigit = 0;
	m_secondDigit = 0;
}

void ClockState::initBackground()
{
	m_background.setSize( sf::Vector2f( static_cast< float >( m_window.getSize().x ), static_cast< float >( m_window.getSize().y ) ) );

	switch( Utitilies::getTime() )
	{
	case 15:
		if( !m_backgroundTexture.loadFromFile( "res/images/Figaro15.png" ) )
		{
			// Think about error logging system
			std::cout << "Error: cannot load background texture\n";
			return;
		}
		break;

	case 30:
		if( !m_backgroundTexture.loadFromFile( "res/images/Figaro30.png" ) )
		{
			// Think about error logging system
			std::cout << "Error: cannot load background texture\n";
			return;
		}
		break;

	case 45:
		if( !m_backgroundTexture.loadFromFile( "res/images/Figaro45.png" ) )
		{
			// Think about error logging system
			std::cout << "Error: cannot load background texture\n";
			return;
		}
		break;

	default:
		std::cout << "Error: cannot load background for this option\n";
		return;
		break;
	}

	m_background.setTexture( &m_backgroundTexture );
}

void ClockState::initTexture()
{
	if( !m_texture.loadFromFile( "res/images/Digitals.png" ) )
	{
		throw( "Error: cannot load digitals texture\n" );
		return;
	}
}

void ClockState::initAnimation()
{
	// Check which time user choose
	switch( Utitilies::getTime() )
	{
	case 15:
		m_animations[ "FIRST_MINUT_DIGIT" ] = new Animation{ m_texture, 1, 0, 64, 128, 254.f, 150.f };
		m_animations[ "SECOND_MINUT_DIGIT" ] = new Animation{ m_texture, 5, 0, 64, 128, 317.f, 150.f };
		m_animations[ "FIRST_SEC_DIGIT" ] = new Animation{ m_texture, 0, 0, 64, 128, 413.f, 150.f };
		m_animations[ "SECOND_SEC_DIGIT" ] = new Animation{ m_texture, 0, 0, 64, 128, 477.f, 150.f };
		break;

	case 30:
		m_animations[ "FIRST_MINUT_DIGIT" ] = new Animation{ m_texture, 3, 0, 64, 128, 254.f, 150.f };
		m_animations[ "SECOND_MINUT_DIGIT" ] = new Animation{ m_texture, 0, 0, 64, 128, 317.f, 150.f };
		m_animations[ "FIRST_SEC_DIGIT" ] = new Animation{ m_texture, 0, 0, 64, 128, 413.f, 150.f };
		m_animations[ "SECOND_SEC_DIGIT" ] = new Animation{ m_texture, 0, 0, 64, 128, 477.f, 150.f };
		break;

	case 45:
		m_animations[ "FIRST_MINUT_DIGIT" ] = new Animation{ m_texture, 4, 0, 64, 128, 254.f, 150.f };
		m_animations[ "SECOND_MINUT_DIGIT" ] = new Animation{ m_texture, 5, 0, 64, 128, 317.f, 150.f };
		m_animations[ "FIRST_SEC_DIGIT" ] = new Animation{ m_texture, 0, 0, 64, 128, 413.f, 150.f };
		m_animations[ "SECOND_SEC_DIGIT" ] = new Animation{ m_texture, 0, 0, 64, 128, 477.f, 150.f };
		break;

	default:
		std::cout << "Error: this option is not exist!\n";
		return;
		break;
	}
}

void ClockState::initFonts()
{
	// Colon font
	if( !m_colonFont.loadFromFile( "res/fonts/DS-DIGIT.ttf" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot find font DS-DIGIT\n";
		return;
	}

	// End countdown font
	if( !m_countdownFinalFont.loadFromFile( "res/fonts/LifeSavers-Bold.ttf" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot find font LifeSavers Bold\n";
		return;
	}
}

void ClockState::initTexts()
{
	// Colon text
	m_colon.setFont( m_colonFont );
	m_colon.setString( ":" );
	m_colon.setFillColor( sf::Color( 204, 0, 0, 230 ) );
	m_colon.setCharacterSize( 64 );
	m_colon.setPosition( sf::Vector2f( 390.f, 165.f ) );

	// Countdown text
	m_countdownFinalText.setFont( m_countdownFinalFont );
	m_countdownFinalText.setString( "" );
	m_countdownFinalText.setFillColor( sf::Color( 204, 0, 0, 230 ) );
	m_countdownFinalText.setCharacterSize( 52 );
	m_countdownFinalText.setPosition( sf::Vector2f( 200.f, 350.f ) );
}

void ClockState::initButtons()
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
	m_buttons[ "START_COUNTING_DOWN" ] = new Button( 200.f, 350.f, 400.f, 50.f,
		font, "Zacznij odliczanie", 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 100, 100, 100, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);

	m_buttons[ "BACK_STATE" ] = new Button( 275.f, 500.f, 250.f, 50.f,
		font, Utitilies::setPolishSigns( "Powrót" ), 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 100, 100, 100, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);
}

// Constructors
ClockState::ClockState( StateMachine& machine, sf::RenderWindow& window, bool replace )
	: State{ machine, window, replace }
{
	this->initVariables();
	this->initBackground();
	this->initTexture();
	this->initAnimation();
	this->initFonts();
	this->initTexts();
	this->initButtons();
}

// Destruktor
ClockState::~ClockState()
{
	for( auto it = m_buttons.begin() ; it != m_buttons.end() ; ++it )
		delete it->second;

	for( auto it = m_animations.begin() ; it != m_animations.end() ; ++it )
		delete it->second;
}

// Button functions
void ClockState::renderButtons()
{
	for( auto &it : m_buttons )
		it.second->render( m_window );
}

void ClockState::updateButtons()
{
	// Update all the buttons in the state and handles their functionality
	for( auto &it : m_buttons )
		it.second->update( m_mousePosView );

	if( m_buttons[ "START_COUNTING_DOWN" ]->isPressed() )
	{
		this->changeCountdownStatus();
		m_buttons[ "START_COUNTING_DOWN" ]->changeClickStatus();

		if( m_buttons[ "START_COUNTING_DOWN" ]->isClick() )
		{
			m_buttons[ "START_COUNTING_DOWN" ]->setText( "Zatrzymaj" );
			m_buttons[ "START_COUNTING_DOWN" ]->setPosition( 200.f, 350.f );
		}
		else
		{
			m_buttons[ "START_COUNTING_DOWN" ]->setText( Utitilies::setPolishSigns( "Wznów" ) );
			m_buttons[ "START_COUNTING_DOWN" ]->setPosition( 200.f, 350.f );
		}

		sf::Mouse::setPosition( sf::Vector2i( 400, 290 ), m_window );
	}

	if( m_buttons[ "BACK_STATE" ]->isPressed() )
	{
		m_machine.lastState();
		sf::Mouse::setPosition( sf::Vector2i( 380, 110 ), m_window );
	}
}

// Mouse function
void ClockState::updateMousePositions()
{
	m_mousePosScreen = sf::Mouse::getPosition();
	m_mousePosWindow = sf::Mouse::getPosition( m_window );
	m_mousePosView = m_window.mapPixelToCoords( sf::Mouse::getPosition( m_window ) );
}

// Timer getters functions
const int ClockState::getMinuts()
{
	return m_minuts;
}

const int ClockState::getSeconds()
{
	return m_seconds;
}

const int ClockState::getDigitOfMinut()
{
	return m_minuteDigit;
}

const int ClockState::getDigitOfSecond()
{
	return m_secondDigit;
}

// Timer setters functions
void ClockState::setDigitOfMinut( const int& minuteDigit )
{
	m_minuteDigit = minuteDigit;
}

void ClockState::setDigitOfSecond( const int& secondDigit )
{
	m_secondDigit = secondDigit;
}

// Regular functions ( private )
void ClockState::changeCountdownStatus()
{
	m_countDownActive = !m_countDownActive;
}

const bool& ClockState::getCountdownStatus()
{
	return m_countDownActive;
}

void ClockState::renderSprite()
{
	for( auto &it : m_animations )
		it.second->render( m_window );
}

// Regular functions ( public )
void ClockState::pause()
{
	std::cout << "ClockState Pause\n";
}

void ClockState::resume()
{
	std::cout << "ClockState Resume\n";
}

void ClockState::update()
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
	this->countTimeDown();
}

void ClockState::draw()
{
	// Clear the previous drawing
	m_window.clear();
	m_window.draw( m_background );
	m_window.draw( m_colon );
	m_window.draw( m_countdownFinalText );
	this->renderButtons();
	this->renderSprite();
	m_window.display();
}

void ClockState::hideCountdownFinalText()
{
	m_countdownFinalText.setString( "" );
	m_countdownFinalText.setPosition( sf::Vector2f( 0.f, 0.f ) );
}

void ClockState::showCountdownFinalText()
{
	m_countdownFinalText.setString( "Koniec odliczania" );
	m_countdownFinalText.setPosition( sf::Vector2f( 200.f, 350.f ) );
}

// Counting time functions
void ClockState::countTimeDown()
{
	if( this->getCountdownStatus() )
	{
		if( m_clock.getElapsedTime().asSeconds() > 1.0f )
		{
			if( this->getMinuts() != 0 && this->getSeconds() == 0 )
			{
				--m_minuts;
				m_seconds = 59;

				this->countMinutesDown();

				m_clock.restart();
			}
			else if( this->getSeconds() != 0 )
			{
				--m_seconds;

				this->countSecondsDown();

				m_clock.restart();
			}
			else if( this->getMinuts() == 0 && this->getSeconds() == 0 )
			{
				if( m_clock.getElapsedTime().asSeconds() > 14.0f)
				{
					m_clock.restart();

					this->changeCountdownStatus();

					m_buttons[ "START_COUNTING_DOWN" ]->changeClickStatus();
					m_buttons[ "START_COUNTING_DOWN" ]->setText( "Zacznij odliczanie" );
					m_buttons[ "START_COUNTING_DOWN" ]->setPosition( 200.f, 350.f );

					this->hideCountdownFinalText();

					this->resetClock();
				}
				else
				{
					m_buttons[ "START_COUNTING_DOWN" ]->setPosition( 200.f, 650.f );

					if( m_clockSound.getSoundStatus() == sf::SoundSource::Stopped )
					{
						m_clockSound.play();
						m_clockSound.changeSoundStatus( sf::SoundSource::Playing );
					}

					if( m_endAnimationClock.getElapsedTime().asSeconds() > 1.0f && m_endAnimationClock.getElapsedTime().asSeconds() < 2.0f  )
					{
						this->showCountdownFinalText();
					}
					else if( m_endAnimationClock.getElapsedTime().asSeconds() >= 2.0f )
					{
						this->hideCountdownFinalText();
						m_endAnimationClock.restart();
					}
				}
			}
    	}
	}
}

void ClockState::countMinutesDown()
{
	this->setDigitOfMinut( m_minuts / 10 );
	m_animations[ "FIRST_MINUT_DIGIT" ]->setFrame( this->getDigitOfMinut() );

	this->setDigitOfMinut( m_minuts % 10 );
	m_animations[ "SECOND_MINUT_DIGIT" ]->setFrame( this->getDigitOfMinut() );

	m_animations[ "FIRST_SEC_DIGIT" ]->setFrame( 5 );
	m_animations[ "SECOND_SEC_DIGIT" ]->setFrame( 9 );

	for( auto &it : m_animations )
		it.second->play();
}

void ClockState::countSecondsDown()
{
	this->setDigitOfSecond( m_seconds / 10 );
	m_animations[ "FIRST_SEC_DIGIT" ]->setFrame( this->getDigitOfSecond() );

	this->setDigitOfSecond( m_seconds % 10 );
	m_animations[ "SECOND_SEC_DIGIT" ]->setFrame( this->getDigitOfSecond() );

	for( auto &it : m_animations )
		it.second->play();
}

void ClockState::resetClock()
{
	switch( Utitilies::getTime() )
	{
	case 15:
		m_animations[ "FIRST_MINUT_DIGIT" ]->reset();
		m_animations[ "SECOND_MINUT_DIGIT" ]->reset();
		m_animations[ "FIRST_SEC_DIGIT" ]->reset();
		m_animations[ "SECOND_SEC_DIGIT" ]->reset();
		break;

	case 30:
		m_animations[ "FIRST_MINUT_DIGIT" ]->reset();
		m_animations[ "SECOND_MINUT_DIGIT" ]->reset();
		m_animations[ "FIRST_SEC_DIGIT" ]->reset();
		m_animations[ "SECOND_SEC_DIGIT" ]->reset();
		break;

	case 45:
		m_animations[ "FIRST_MINUT_DIGIT" ]->reset();
		m_animations[ "SECOND_MINUT_DIGIT" ]->reset();
		m_animations[ "FIRST_SEC_DIGIT" ]->reset();
		m_animations[ "SECOND_SEC_DIGIT" ]->reset();
		break;

	default:
		std::cout << "Error: this option is not exist!\n";
		return;
		break;
	}
	this->resetTime();
	this->stopAudio();
}

void ClockState::resetTime()
{
	m_minuts = Utitilies::getTime();
	m_seconds = 0;
	m_minuteDigit = 0;
	m_secondDigit = 0;
}

void ClockState::stopAudio()
{
	m_clockSound.stop();
	m_clockSound.changeSoundStatus( sf::SoundSource::Stopped );
}
