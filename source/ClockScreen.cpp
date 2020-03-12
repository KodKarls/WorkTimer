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
    ClockBlock minClockBlock1 = ClockBlock( 10, 60, 60, 50 );
    ClockBlock minClockBlock2 = ClockBlock( 10, 60, 130, 50 );
    ClockBlock minClockBlock3 = ClockBlock( 10, 60, 60, 140 );
    ClockBlock minClockBlock4 = ClockBlock( 10, 60, 130, 140 );

    ClockBlock minClockBlock5 = ClockBlock( 60, 10, 70, 30 );
    ClockBlock minClockBlock6 = ClockBlock( 60, 10, 70, 120 );
    minClockBlock6.setColor( 0, 0, 0, 0 );
    ClockBlock minClockBlock7 = ClockBlock( 60, 10, 70, 210 );

    ClockBlock minClockBlock8 = ClockBlock( 10, 60, 170, 50 );
    ClockBlock minClockBlock9 = ClockBlock( 10, 60, 240, 50 );
    ClockBlock minClockBlock10 = ClockBlock( 10, 60, 170, 140 );
    ClockBlock minClockBlock11 = ClockBlock( 10, 60, 240, 140 );

    ClockBlock minClockBlock12 = ClockBlock( 60, 10, 180, 30 );
    ClockBlock minClockBlock13 = ClockBlock( 60, 10, 180, 120 );
    minClockBlock13.setColor( 0, 0, 0, 0 );
    ClockBlock minClockBlock14 = ClockBlock( 60, 10, 180, 210 );

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
    ClockBlock secClockBlock1 = ClockBlock( 10, 60, 340, 50 );
    ClockBlock secClockBlock2 = ClockBlock( 10, 60, 410, 50 );
    ClockBlock secClockBlock3 = ClockBlock( 10, 60, 340, 140 );
    ClockBlock secClockBlock4 = ClockBlock( 10, 60, 410, 140 );

    ClockBlock secClockBlock5 = ClockBlock( 60, 10, 350, 30 );
    ClockBlock secClockBlock6 = ClockBlock( 60, 10, 350, 120 );
    secClockBlock6.setColor( 0, 0, 0, 0 );
    ClockBlock secClockBlock7 = ClockBlock( 60, 10, 350, 210 );

    ClockBlock secClockBlock8 = ClockBlock( 10, 60, 450, 50 );
    ClockBlock secClockBlock9 = ClockBlock( 10, 60, 520, 50 );
    ClockBlock secClockBlock10 = ClockBlock( 10, 60, 450, 140 );
    ClockBlock secClockBlock11 = ClockBlock( 10, 60, 520, 140 );

    ClockBlock secClockBlock12 = ClockBlock( 60, 10, 460, 30 );
    ClockBlock secClockBlock13 = ClockBlock( 60, 10, 460, 120 );
    secClockBlock13.setColor( 0, 0, 0, 0 );
    ClockBlock secClockBlock14 = ClockBlock( 60, 10, 460, 210 );

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
    clockColonText_.setPosition( sf::Vector2f( 290, 80 ) );
}

void ClockScreen::changeChoiceButtonText( ChooseButton& chooseButton )
{
    chooseButton.getText().setString(Utilities::START_BUTTON);
    chooseButton.setTextPosition();
}

int ClockScreen::run( sf::RenderWindow &app )
{
    prepareMinutClockBlocks();
    setColonText();
    prepareSecondClockBlocks();

    ChooseButton choiceButton = ChooseButton( Utilities::CHOICE_BUTTON, 470, 60 );
    choiceButton.changeButtonPosition( 60, 250 );
    ChooseButton fiveMinutButton = ChooseButton( Utilities::FIVE_MINUT, 225, 60 );
    fiveMinutButton.changeButtonPosition( 60, 330 );
    ChooseButton fifteenMinutButton = ChooseButton( Utilities::FIFTEEN_MINUT, 225, 60 );
    fifteenMinutButton.changeButtonPosition( 305, 330 );
    ChooseButton thirtyMinutButton = ChooseButton( Utilities::THIRTY_MINUT, 225, 60 );
    thirtyMinutButton.changeButtonPosition( 60, 410 );
    ChooseButton fourtyFiveMinutButton = ChooseButton( Utilities::FOURTY_FIVE_MINUT, 225, 60 );
    fourtyFiveMinutButton.changeButtonPosition( 305, 410 );

    ClockButton backButton = ClockButton( Utilities::BACK_BUTTON, 200, 60 );

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
                    if( fiveMinutButton.getShape().getGlobalBounds().contains( mousePositionCoordinates ) )
                    {
                        for( int i = 0; i < Utilities::MINUT_CLOCK_BLOCK_SIZE; ++i )
                        {
                            minutClockBlocks[ i ].setColor();
                            secondClockBlocks[ i ].setColor();
                        }
                        minutClockBlocks[ 5 ].setColor( 0, 0, 0, 0 );
                        secondClockBlocks[ 5 ].setColor( 0, 0, 0, 0 );
                        secondClockBlocks[ 12 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 8 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 9 ].setColor( 0, 0, 0, 0 );
                        changeChoiceButtonText( choiceButton );
                    }
                    else if( fifteenMinutButton.getShape().getGlobalBounds().contains( mousePositionCoordinates ) )
                    {
                        for( int i = 0; i < Utilities::MINUT_CLOCK_BLOCK_SIZE; ++i )
                        {
                            minutClockBlocks[ i ].setColor();
                            secondClockBlocks[ i ].setColor();
                        }
                        secondClockBlocks[ 5 ].setColor( 0, 0, 0, 0 );
                        secondClockBlocks[ 12 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 0 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 2 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 4 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 5 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 6 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 8 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 9 ].setColor( 0, 0, 0, 0 );
                        changeChoiceButtonText( choiceButton );
                    }
                    else if( thirtyMinutButton.getShape().getGlobalBounds().contains( mousePositionCoordinates ) )
                    {
                        for( int i = 0; i < Utilities::MINUT_CLOCK_BLOCK_SIZE; ++i )
                        {
                            minutClockBlocks[ i ].setColor();
                            secondClockBlocks[ i ].setColor();
                        }
                        minutClockBlocks[ 12 ].setColor( 0, 0, 0, 0 );
                        secondClockBlocks[ 5 ].setColor( 0, 0, 0, 0 );
                        secondClockBlocks[ 12 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 0 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 2 ].setColor( 0, 0, 0, 0 );
                        changeChoiceButtonText( choiceButton );
                    }
                    else if( fourtyFiveMinutButton.getShape().getGlobalBounds().contains( mousePositionCoordinates ) )
                    {
                        for( int i = 0; i < Utilities::MINUT_CLOCK_BLOCK_SIZE; ++i )
                        {
                            minutClockBlocks[ i ].setColor();
                            secondClockBlocks[ i ].setColor();
                        }
                        secondClockBlocks[ 5 ].setColor( 0, 0, 0, 0 );
                        secondClockBlocks[ 12 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 2 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 4 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 6 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 8 ].setColor( 0, 0, 0, 0 );
                        minutClockBlocks[ 9 ].setColor( 0, 0, 0, 0 );
                        changeChoiceButtonText( choiceButton );
                    }
                    else if( backButton.getShape().getGlobalBounds().contains( mousePositionCoordinates ) )
                    {
                        return 1;
                    }
                    else
                    {
                        Logger::getLogger().write( Logger::INFO, "Nie ma takiego zdarzenia!" );
                    }
                }
            }
        }
        app.clear();
        for( int i = 0 ; i < Utilities::MINUT_CLOCK_BLOCK_SIZE ; i++ )
        {
            app.draw( minutClockBlocks[ i ].getShape() );
        }
        app.draw( clockColonText_ );
        for( int i = 0 ; i < Utilities::SECOND_CLOCK_BLOCK_SIZE ; i++ )
        {
            app.draw( secondClockBlocks[ i ].getShape() );
        }
        app.draw( choiceButton.getShape() );
        app.draw( choiceButton.getText() );
        app.draw( fiveMinutButton.getShape() );
        app.draw( fiveMinutButton.getText() );
        app.draw( fifteenMinutButton.getShape() );
        app.draw( fifteenMinutButton.getText() );
        app.draw( thirtyMinutButton.getShape() );
        app.draw( thirtyMinutButton.getText() );
        app.draw( fourtyFiveMinutButton.getShape() );
        app.draw( fourtyFiveMinutButton.getText() );
        app.draw( backButton.getShape() );
        app.draw( backButton.getText() );
        app.display();
    }
    return -1;
}
