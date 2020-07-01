#include "App.hpp"

// Init functions
void App::initVariables()
{
	this->window = nullptr;
	this->dt = 0.f;
}

void App::initWindow()
{
	// Create a SFML window using basic options from a config.ini file.
	std::ifstream configFile( "config/config.ini" );

	// Set default values
	std::string title = "None";
	sf::VideoMode windowBounds = sf::VideoMode::getDesktopMode();
	unsigned framerateLimit = 120;
	bool verticalSyncEnabled = false;

	if( !configFile.is_open() )
	{
		// Think about error logging system
		std::cout << "Error: cannot find file config.ini\n";
		return;
	}

	// Read window settings from file
	std::getline( configFile, title );
	configFile >> windowBounds.width >> windowBounds.height;
	configFile >> framerateLimit;
	configFile >> verticalSyncEnabled;

	configFile.close();

	// Set window settings
	this->window = new sf::RenderWindow( sf::VideoMode( windowBounds ), title );
	this->window->setFramerateLimit( framerateLimit );
	this->window->setVerticalSyncEnabled( verticalSyncEnabled );
}

App::App()
{
	this->initVariables();
	this->initWindow();
}

App::~App()
{
	// Empty body
}

// Regular functions
void App::endApplication()
{
	// Run ending state
	std::cout << "Ending application\n";
}

// Update functions
void App::updateDt()
{
	this->dt = this->dtClock.restart().asSeconds();
}

void App::updateSFMLEvents()
{
	while( this->window->pollEvent( this->sfEvent ) )
	{
		if( this->sfEvent.type == sf::Event::Closed )
			this->window->close();
	}
}

void App::update()
{
	this->updateSFMLEvents();

	// Prepare states
	// ...
}

// Render function
void App::render()
{
	this->window->clear();

	// Render all things
	// ..

	this->window->display();
}

// Core function
void App::run()
{
	while( this->window->isOpen() )
	{
		this->updateDt();
		this->update();
		this->render();
	}
}