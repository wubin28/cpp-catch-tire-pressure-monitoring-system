#include "Alarm.hpp"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"  // https://github.com/philsquared/Catch

SCENARIO("the status of alarm after checking", "feature") {
  GIVEN("there is an alarm") {
    Alarm* alarm = NULL;
    
    WHEN("a normal pressure value is checked") {
      alarm = new Alarm(new FakeSensor(Alarm::LOW_PRESSURE_THRESHOLD));
      alarm->check();

      THEN("do not raise the alarm") {
        REQUIRE_FALSE(alarm->isAlarmOn());
      }
    }

    WHEN("a pressure value out of range is checked") {
      alarm = new Alarm(new FakeSensor(Alarm::LOW_PRESSURE_THRESHOLD - 1));
      alarm->check();

      THEN("raise the alarm") {
        REQUIRE(alarm->isAlarmOn());
      }
    }

    WHEN("a normal pressure value after the out of range one is checked") {
      alarm = new Alarm(new FakeSensor(Alarm::HIGH_PRESSURE_THRESHOLD + 1));
      alarm->check();
      alarm->setSensor(new FakeSensor(Alarm::HIGH_PRESSURE_THRESHOLD));
      alarm->check();

      THEN("stop the alarm") {
        REQUIRE_FALSE(alarm->isAlarmOn());
      }
    }

  }
}
