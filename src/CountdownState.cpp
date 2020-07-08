// #include "CountdownState.hpp"

// // Init functions
// void CountdownState::initVariables()
// {
// 	// Empty body
// }

// void CountdownState::initBackground()
// {
// 	this->background.setSize( sf::Vector2f( static_cast< float >( this->window->getSize().x ), static_cast< float >( this->window->getSize().y ) ) );
// 	if( !this->backgroundTexture.loadFromFile( "res/images/Figaro3.png" ) )
// 	{
// 		// Think about error logging system
// 		std::cout << "Error: cannot load Figaro3 texture\n";
// 		return;
// 	}
// 	this->background.setTexture( &this->backgroundTexture );
// }

// void CountdownState::initFonts()
// {
// 	if( !this->font.loadFromFile( "res/fonts/LifeSavers-Bold.ttf" ) )
// 	{
// 		// Think about error logging system
// 		std::cout << "Error: cannot find font arial\n";
// 	}
// }

// void CountdownState::initButtons()
// {
// 	this->buttons[ "FIFTEEN_MINUTES" ] = new Button( 250.f, 150.f, 250.f, 50.f,
// 		&this->font, "15 minut", 52,
// 		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
// 		sf::Color( 70, 70, 70, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
// 	);

// 	this->buttons[ "THIRTY_MINUTES" ] = new Button( 250.f, 250.f, 250.f, 50.f,
// 		&this->font, "30 minut", 52,
// 		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
// 		sf::Color( 70, 70, 70, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
// 	);

// 	this->buttons[ "FORTY_FIVE_MINUTES" ] = new Button( 250.f, 350.f, 250.f, 50.f,
// 		&this->font, "45 minut", 52,
// 		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
// 		sf::Color( 70, 70, 70, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
// 	);

// 	this->buttons[ "BACK_STATE" ] = new Button( 250.f, 500.f, 250.f, 50.f,
// 		&this->font, Utitilies::setPolishSigns( "Powrót" ), 52,
// 		sf::Color( 51, 204, 0, 230 ), sf::Color( 0, 51, 102, 230 ), sf::Color( 20, 30, 20, 50 ),
// 		sf::Color( 100, 100, 100, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
// 	);
// }

// // Constructors
// CountdownState::CountdownState( sf::RenderWindow* window, std::stack< State* >* states )
// 	: State( window, states )
// {
// 	this->initVariables();
// 	this->initBackground();
// 	this->initFonts();
// 	this->initButtons();
// }

// // Destruktor
// CountdownState::~CountdownState()
// {
// 	auto it = this->buttons.begin();
// 	for( ; it != this->buttons.end(); ++it )
// 		delete it->second;
// }

// // Update functions
// void CountdownState::update( const float& dt )
// {
// 	this->updateMousePositions();
// 	this->updateInput( dt );
// 	this->updateButtons();
// }

// void CountdownState::updateInput( const float& dt )
// {
// 	// Update player input
// }

// void CountdownState::updateButtons()
// {
// 	// Update all the buttons in the state and handles their functionality
// 	for( auto &it : this->buttons )
// 	{
// 		it.second->update( this->mousePosView );
// 	}

// 	// Set fifteen minutes


// 	// Set thirty minutes


// 	// Set forty-five minutes


// 	// Back to the menu
// 	if( this->buttons[ "BACK_STATE" ]->isPressed() )
// 		this->endState();
// }

// // Render functions
// void CountdownState::render( sf::RenderTarget* target )
// {
// 	if( !target )
// 		target = this->window;

// 	target->draw( this->background );
// 	this->renderButtons( target );
// }

// void CountdownState::renderButtons( sf::RenderTarget* target )
// {
// 	for( auto &it : this->buttons )
// 		it.second->render( target );
// }
