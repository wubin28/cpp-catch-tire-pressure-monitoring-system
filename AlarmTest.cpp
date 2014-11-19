#include "Alarm.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"  // https://github.com/philsquared/Catch

TEST_CASE("a normal pressure value should not raise the alarm", "feature") {
  // Arrange
  Alarm* alarm = new Alarm(new FakeSensor(Alarm::LOW_PRESSURE_THRESHOLD));

  // Act
  alarm->check();

  // Assert
  REQUIRE( alarm->isAlarmOn() == false );
}

TEST_CASE("a pressure value out of range should raise the alarm") {
  // Arrange
  Alarm* alarm = new Alarm(new FakeSensor(Alarm::LOW_PRESSURE_THRESHOLD - 1));

  // Act
  alarm->check();

  // Assert
  REQUIRE( alarm->isAlarmOn() == true );
}

// TODO: a normal pressure value after the out of range one should keep the alarm on
// TODO-new-feature: a normal pressure value after the out of range one should stop the alarm
