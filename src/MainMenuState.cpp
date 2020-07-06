#include "MainMenuState.hpp"

// Init functions
void MainMenuState::initVariables()
{
	// Empty body
}

void MainMenuState::initBackground()
{
	this->background.setSize( sf::Vector2f( static_cast< float >( this->window->getSize().x ), static_cast< float >( this->window->getSize().y ) ) );
	if( !this->backgroundTexture.loadFromFile( "res/images/Figaro1.png" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot load background texture\n";
		return;
	}
	this->background.setTexture( &this->backgroundTexture );
}

void MainMenuState::initFonts()
{
	if( !this->font.loadFromFile( "res/fonts/LifeSavers-Bold.ttf" ) )
	{
		// Think about error logging system
		std::cout << "Error: cannot find font arial\n";
	}
}

void MainMenuState::initButtons()
{
	this->buttons[ "CLOCK_STATE" ] = new Button( 250.f, 170.f, 250.f, 50.f,
		&this->font, "Ustaw odliczanie", 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 70, 70, 70, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);

	this->buttons[ "INFO_STATE" ] = new Button( 250.f, 270.f, 250.f, 50.f,
		&this->font, "Informacje", 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 70, 70, 70, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);


	this->buttons[ "EXIT_STATE" ] = new Button( 250.f, 470.f, 250.f, 50.f,
		&this->font, Utitilies::setPolishSigns( "Wyjście" ), 52,
		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
		sf::Color( 100, 100, 100, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
	);
}

// Constructors
MainMenuState::MainMenuState( sf::RenderWindow* window, std::stack< State* >* states )
	: State( window, states )
{
	this->initVariables();
	this->initBackground();
	this->initFonts();
	this->initButtons();
}

// Destructor
MainMenuState::~MainMenuState()
{
	auto it = this->buttons.begin();
	for( ; it != this->buttons.end(); ++it )
		delete it->second;
}

// Update functions
void MainMenuState::update( const float& dt )
{
	this->updateMousePositions();
	this->updateInput( dt );
	this->updateButtons();
}

void MainMenuState::updateInput( const float& dt )
{
	// Update player input
}

void MainMenuState::updateButtons()
{
	// Update all the buttons in the state and handles their functionality
	for( auto &it : this->buttons )
	{
		it.second->update( this->mousePosView );
	}

	// Set countdown


	// Info
	if( this->buttons[ "INFO_STATE" ]->isPressed() )
		this->states->push( new InfoState{ this->window, this->states } );

	// Quit the game
	if( this->buttons[ "EXIT_STATE" ]->isPressed() )
		this->endState();
}

// Render functions
void MainMenuState::render( sf::RenderTarget* target )
{
	if( !target )
		target = this->window;

	target->draw( this->background );
	this->renderButtons( target );
}

void MainMenuState::renderButtons( sf::RenderTarget* target )
{
	for( auto &it : this->buttons )
		it.second->render( target );
}