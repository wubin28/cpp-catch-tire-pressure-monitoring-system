#include "Alarm.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"  // https://github.com/philsquared/Catch

// TODO-working-on: a normal pressure value should not raise the alarm
TEST_CASE( "a normal pressure value should not raise the alarm", "feature" )
{
  // Arrange
  Alarm* alarm = new Alarm(new FakeSensor(Alarm.LOW_PRESSURE_THRESHOLD));

  // Act
  alarm->check();

  // Assert
  REQUIRE( alarm->isAlarmOn() == false );
}

// TODO: a pressure value out of range should raise the alarm
// TODO: a normal pressure value after the out of range one should keep the alarm on
// TODO-new-feature: a normal pressure value after the out of range one should stop the alarm
