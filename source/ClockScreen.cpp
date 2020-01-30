#include "../header/ClockScreen.hpp"

ClockScreen::ClockScreen()	:	clockColonText_( sf::Text() ), font_( sf::Font() ),
                                event_( sf::Event() ), running_( true )
{
    // Empty body
}

ClockScreen::~ClockScreen()
{
    // Empty body
}

void ClockScreen::prepareMinutClockBlocks()
{
    ClockBlock minClockBlock1 = ClockBlock( 10, 60, 60, 70 );
    ClockBlock minClockBlock2 = ClockBlock( 10, 60, 130, 70 );
    ClockBlock minClockBlock3 = ClockBlock( 10, 60, 60, 160 );
    ClockBlock minClockBlock4 = ClockBlock( 10, 60, 130, 160 );

    ClockBlock minClockBlock5 = ClockBlock( 60, 10, 70, 50 );
    ClockBlock minClockBlock6 = ClockBlock( 60, 10, 70, 140 );
    ClockBlock minClockBlock7 = ClockBlock( 60, 10, 70, 230 );

    ClockBlock minClockBlock8 = ClockBlock( 10, 60, 170, 70 );
    ClockBlock minClockBlock9 = ClockBlock( 10, 60, 240, 70 );
    ClockBlock minClockBlock10 = ClockBlock( 10, 60, 170, 160 );
    ClockBlock minClockBlock11 = ClockBlock( 10, 60, 240, 160 );

    ClockBlock minClockBlock12 = ClockBlock( 60, 10, 180, 50 );
    ClockBlock minClockBlock13 = ClockBlock( 60, 10, 180, 140 );
    ClockBlock minClockBlock14 = ClockBlock( 60, 10, 180, 230 );

    minutClockBlocks.push_back( minClockBlock1 );
    minutClockBlocks.push_back( minClockBlock2 );
    minutClockBlocks.push_back( minClockBlock3 );
    minutClockBlocks.push_back( minClockBlock4 );
    minutClockBlocks.push_back( minClockBlock5 );
    minutClockBlocks.push_back( minClockBlock6 );
    minutClockBlocks.push_back( minClockBlock7 );
    minutClockBlocks.push_back( minClockBlock8 );
    minutClockBlocks.push_back( minClockBlock9 );
    minutClockBlocks.push_back( minClockBlock10 );
    minutClockBlocks.push_back( minClockBlock11 );
    minutClockBlocks.push_back( minClockBlock12 );
    minutClockBlocks.push_back( minClockBlock13 );
    minutClockBlocks.push_back( minClockBlock14 );
}

void ClockScreen::prepareSecondClockBlocks()
{
    ClockBlock secClockBlock1 = ClockBlock( 10, 60, 340, 70 );
    ClockBlock secClockBlock2 = ClockBlock( 10, 60, 410, 70 );
    ClockBlock secClockBlock3 = ClockBlock( 10, 60, 340, 160 );
    ClockBlock secClockBlock4 = ClockBlock( 10, 60, 410, 160 );

    ClockBlock secClockBlock5 = ClockBlock( 60, 10, 350, 50 );
    ClockBlock secClockBlock6 = ClockBlock( 60, 10, 350, 140 );
    ClockBlock secClockBlock7 = ClockBlock( 60, 10, 350, 230 );

    ClockBlock secClockBlock8 = ClockBlock( 10, 60, 450, 70 );
    ClockBlock secClockBlock9 = ClockBlock( 10, 60, 520, 70 );
    ClockBlock secClockBlock10 = ClockBlock( 10, 60, 450, 160 );
    ClockBlock secClockBlock11 = ClockBlock( 10, 60, 520, 160 );

    ClockBlock secClockBlock12 = ClockBlock( 60, 10, 460, 50 );
    ClockBlock secClockBlock13 = ClockBlock( 60, 10, 460, 140 );
    ClockBlock secClockBlock14 = ClockBlock( 60, 10, 460, 230 );

    secondClockBlocks.push_back( secClockBlock1 );
    secondClockBlocks.push_back( secClockBlock2 );
    secondClockBlocks.push_back( secClockBlock3 );
    secondClockBlocks.push_back( secClockBlock4 );
    secondClockBlocks.push_back( secClockBlock5 );
    secondClockBlocks.push_back( secClockBlock6 );
    secondClockBlocks.push_back( secClockBlock7 );
    secondClockBlocks.push_back( secClockBlock8 );
    secondClockBlocks.push_back( secClockBlock9 );
    secondClockBlocks.push_back( secClockBlock10 );
    secondClockBlocks.push_back( secClockBlock11 );
    secondClockBlocks.push_back( secClockBlock12 );
    secondClockBlocks.push_back( secClockBlock13 );
    secondClockBlocks.push_back( secClockBlock14 );
}

void ClockScreen::setColonText()
{
    if( !font_.loadFromFile( "resource/fonts/LifeSavers-Bold.ttf" ) )
    {
        Logger::getLogger().write( Logger::ERROR, "Czcionka nie została ustawiona" );
    }

    clockColonText_.setFont( font_ );
    clockColonText_.setCharacterSize( 64 );
    clockColonText_.setStyle( sf::Text::Bold );
    clockColonText_.setFillColor( sf::Color( 60, 179, 113, 230 ) );
    clockColonText_.setString( ":" );
    clockColonText_.setPosition( sf::Vector2f( 290, 100 ) );
}

int ClockScreen::run( sf::RenderWindow &app )
{
    ClockButton backButton = ClockButton( Utilities::BACK_BUTTON, 250, 100 );
    prepareMinutClockBlocks();
    setColonText();
    prepareSecondClockBlocks();

    while( running_ )
    {
        while( app.pollEvent( event_ ) )
        {
            switch( event_.type )
            {
                case sf::Event::Closed:
                {
                    app.close();
                    return -1;
                    break;
                }
                case sf::Event::MouseButtonPressed:
                {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition( app );
                    sf::Vector2f mousePositionCoordinates( mousePosition.x, mousePosition.y );
                    if( backButton.getShape().getGlobalBounds().contains( mousePositionCoordinates ) )
                    {
                        return 1;
                    }
                }
                default:
                {
                    Logger::getLogger().write( Logger::INFO, "Nie ma takiego zdarzenia!" );
                    break;
                }
            }
        }
        app.clear();
        app.draw( backButton.getShape() );
        app.draw( backButton.getText() );
        for( int i = 0 ; i < Utilities::MINUT_CLOCK_BLOCK_SIZE ; i++ )
        {
            app.draw( minutClockBlocks[ i ].getShape() );
        }
        for( int i = 0 ; i < Utilities::SECOND_CLOCK_BLOCK_SIZE ; i++ )
        {
            app.draw( secondClockBlocks[ i ].getShape() );
        }
        app.draw( clockColonText_ );
        app.display();
    }
    return -1;
}
