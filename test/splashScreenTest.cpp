#define BOOST_TEST_MODULE SplashScreen
#include <boost/test/unit_test.hpp>
#include "../source/SplashScreen.cpp"

BOOST_FIXTURE_TEST_SUITE( SplashScreenParameters, SplashScreen )
BOOST_AUTO_TEST_CASE( testWidth )
{
    BOOST_CHECK( Utilities::width == 600 );
}
BOOST_AUTO_TEST_CASE( testHeight )
{
    BOOST_CHECK( Utilities::height == 600 );
}
BOOST_AUTO_TEST_CASE( testAppName )
{
    SplashScreen splashScreen;
    BOOST_CHECK( splashScreen.getAppName() == "Czasomierz" );
}
BOOST_AUTO_TEST_SUITE_END()

BOOST_FIXTURE_TEST_SUITE( SplashScreenText, SplashScreen )
// BOOST_AUTO_TEST_CASE( testCharacterSize )
// {
//     SplashScreen splashScreen;
//     BOOST_CHECK( Utilities::width == 600 );
// }
// BOOST_AUTO_TEST_CASE( testHeight )
// {
//     BOOST_CHECK( Utilities::height == 600 );
// }
// BOOST_AUTO_TEST_CASE( testAppName )
// {
//     SplashScreen splashScreen;
//     BOOST_CHECK( splashScreen.getAppName() == "Czasomierz" );
// }
BOOST_AUTO_TEST_SUITE_END()
