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

TEST_CASE("a normal pressure value after the out of range one should stop the alarm") {
  // Arrange, Act
  Alarm* alarm = new Alarm(new FakeSensor(Alarm::HIGH_PRESSURE_THRESHOLD + 1));
  alarm->check();
  alarm->setSensor(new FakeSensor(Alarm::HIGH_PRESSURE_THRESHOLD));
  alarm->check();

  // Assert
  REQUIRE( alarm->isAlarmOn() == false );
}

