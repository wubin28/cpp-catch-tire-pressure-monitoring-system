#include "hiker.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"  // https://github.com/philsquared/Catch

TEST_CASE( "Life the universe and everything", "[hhgttg]" )
{
    // a simple example to start you off
    REQUIRE( answer() == 42 );
}

// TODO: a normal pressure value should not raise the alarm
// TODO: a pressure value out of range should raise the alarm
// TODO: a normal pressure value after the out of range one should keep the alarm on
// TODO-new-feature: a normal pressure value after the out of range one should stop the alarm
