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

// TODO-intention: the alarm will be on if the pressure value is out of range
// TODO-intention: the alarm will be off if the pressure value is normal
// TODO-intention: the alarm will still be on if a normal pressure value comes after an out of range one

// TODO-new-feature: the alarm will be off if a normal pressure value comes after an out of range one
