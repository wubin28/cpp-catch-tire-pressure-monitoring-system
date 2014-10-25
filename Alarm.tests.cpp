#include "Alarm.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"  // https://github.com/philsquared/Catch

TEST_CASE( "Characterization test for method Alarm.isAlarmOn()", "[Characterization]" )
{
    // Arrange
    Alarm alarm;

    // Act
    alarm.check();

    // Assert
    REQUIRE( alarm.isAlarmOn() );
}
