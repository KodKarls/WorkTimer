#define BOOST_TEST_MODULE Window
#include <boost/test/unit_test.hpp>
#include "../source/Window.cpp"

BOOST_FIXTURE_TEST_SUITE( WindowClass, Window )
BOOST_AUTO_TEST_CASE( testWidth )
{
    Window window;
    BOOST_CHECK( window.getWidth() == 600 );
}
BOOST_AUTO_TEST_CASE( testHeight )
{
    Window window;
    BOOST_CHECK( window.getHeight() == 600 );
}
BOOST_AUTO_TEST_CASE( testName )
{
    Window window;
    BOOST_CHECK( window.getName() == "Work Timer" );
}
BOOST_AUTO_TEST_SUITE_END()
