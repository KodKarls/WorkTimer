// #include "InfoState.hpp"

// void InfoState::initVariables()
// {
//  	// Empty body
// }

// void InfoState::initBackground()
// {
// 	this->background.setSize( sf::Vector2f( static_cast< float >( this->window->getSize().x ), static_cast< float >( this->window->getSize().y ) ) );
// 	if( !this->backgroundTexture.loadFromFile( "res/images/Figaro2.png" ) )
// 	{
// 		// Think about error logging system
// 		std::cout << "Error: cannot load background texture\n";
// 		return;
// 	}
// 	this->background.setTexture( &this->backgroundTexture );
// }

// void InfoState::initFonts()
// {
// 	if( !this->font.loadFromFile( "res/fonts/LifeSavers-Bold.ttf" ) )
// 	{
// 		// Think about error logging system
// 		std::cout << "Error: cannot find font LifeSaversBold\n";
// 	}
// }

// void InfoState::initButtons()
// {
// 	this->buttons[ "BACK_STATE" ] = new Button( 370.f, 470.f, 250.f, 50.f,
// 		&this->font, Utitilies::setPolishSigns( "Powrót" ), 52,
// 		sf::Color( 0, 51, 102, 230 ), sf::Color( 51, 204, 0, 230 ), sf::Color( 20, 30, 20, 50 ),
// 		sf::Color( 100, 100, 100, 0 ), sf::Color( 150, 150, 150, 0 ), sf::Color( 20, 30, 20, 0 )
// 	);
// }

// // Constructors
// InfoState::InfoState( sf::RenderWindow* window, std::stack< State* >* states )
// 	: State( window, states )
// {
// 	this->initVariables();
// 	this->initBackground();
// 	this->initFonts();
// 	this->initButtons();
// }

// // Destructor
// InfoState::~InfoState()
// {
// 	auto it = this->buttons.begin();
// 	for( ; it != this->buttons.end(); ++it )
// 		delete it->second;
// }

// // Update functions
// void InfoState::update( const float& dt )
// {
// 	this->updateMousePositions();
// 	this->updateInput( dt );
// 	this->updateButtons();
// }

// void InfoState::updateInput( const float& dt )
// {
// 	// Update player input
// }

// void InfoState::updateButtons()
// {
// 	// Update all the buttons in the state and handles their functionality
// 	for( auto &it : this->buttons )
// 	{
// 		it.second->update( this->mousePosView );
// 	}

// 	// Back the menu
// 	if( this->buttons[ "BACK_STATE" ]->isPressed() )
// 		this->endState();
// }

// // Render functions
// void InfoState::render( sf::RenderTarget* target )
// {
// 	if( !target )
// 		target = this->window;

// 	target->draw( this->background );
// 	this->renderButtons( target );
// }

// void InfoState::renderButtons( sf::RenderTarget* target )
// {
// 	for( auto &it : this->buttons )
// 		it.second->render( target );
// }