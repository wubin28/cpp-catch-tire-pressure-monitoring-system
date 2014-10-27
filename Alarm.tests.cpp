#include "Alarm.hpp"
#include "FakeSensor.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"  // https://github.com/philsquared/Catch

TEST_CASE( "the alarm will be on if the pressure value is out of range", "[Intention]" )
{
  // Arrange
  FakeSensor *fakeSensor = new FakeSensor;
  fakeSensor->fakeNextPressurePsiValue(Alarm::LOW_PRESSURE_THRESHOLD - 1);
  Alarm *alarm = new Alarm(fakeSensor);

  // Act
  alarm->check();

  // Assert
  REQUIRE( alarm->isAlarmOn() );
}

TEST_CASE( "the alarm will be off if the pressure value is normal", "[Intention]" )
{
  // Arrange
  FakeSensor *fakeSensor = new FakeSensor;
  fakeSensor->fakeNextPressurePsiValue(Alarm::LOW_PRESSURE_THRESHOLD);
  Alarm *alarm = new Alarm(fakeSensor);

  // Act
  alarm->check();

  // Assert
  REQUIRE_FALSE( alarm->isAlarmOn() );
}

TEST_CASE( "the alarm will be off if a normal pressure value comes after an out of range one", "[NewFeature]" )
{
  // Arrange
  FakeSensor *fakeSensor = new FakeSensor;
  fakeSensor->fakeNextPressurePsiValue(Alarm::LOW_PRESSURE_THRESHOLD - 1);
  fakeSensor->fakeNextPressurePsiValueAgain(Alarm::LOW_PRESSURE_THRESHOLD);
  Alarm *alarm = new Alarm(fakeSensor);

  // Act
  alarm->check();
  alarm->check();

  // Assert
  REQUIRE_FALSE( alarm->isAlarmOn() );
}

