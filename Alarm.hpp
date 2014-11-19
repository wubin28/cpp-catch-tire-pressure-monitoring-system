#ifndef ALARM_HPP
#define ALARM_HPP

#include "Sensor.hpp"

class Alarm {
public:
  Alarm();
  void check();
  bool isAlarmOn();
private:
  static const double LOW_PRESSURE_THRESHOLD;
  static const double HIGH_PRESSURE_THRESHOLD;
  Sensor* sensor;
  bool alarmOn;
};

#endif /* ALARM_HPP */
