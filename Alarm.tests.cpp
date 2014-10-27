#include "Alarm.hpp"
#include "FakeSensor.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"  // https://github.com/philsquared/Catch

SCENARIO( "the status of alarm after the transducer probing pressure values", "[Intention]" )
{
  GIVEN("there is a sensor") {
    FakeSensor *fakeSensor = new FakeSensor;
    Alarm *alarm = new Alarm(fakeSensor);
    
    WHEN("the sensor probes a pressure value out of range") {
      fakeSensor->fakeNextPressurePsiValue(Alarm::LOW_PRESSURE_THRESHOLD - 1);
      alarm->check();

      THEN("the alarm will be on") {
        REQUIRE( alarm->isAlarmOn() );
      }
    }

    WHEN("the sensor probes a normal pressure value") {
      fakeSensor->fakeNextPressurePsiValue(Alarm::LOW_PRESSURE_THRESHOLD);
      alarm->check();

      THEN("the alarm will be off") {
        REQUIRE_FALSE( alarm->isAlarmOn() );
      }
    }

    WHEN("the sensor probes a normal pressure value after the one out of range") {
      fakeSensor->fakeNextPressurePsiValue(Alarm::LOW_PRESSURE_THRESHOLD - 1);
      fakeSensor->fakeNextPressurePsiValueAgain(Alarm::LOW_PRESSURE_THRESHOLD);
      alarm->check();
      alarm->check();

      THEN("the alarm will be off") {
        REQUIRE_FALSE( alarm->isAlarmOn() );
      }
    }
  }
}

