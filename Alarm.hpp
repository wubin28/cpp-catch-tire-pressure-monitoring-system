#ifndef ALARM_HPP
#define ALARM_HPP

#include "Sensor.hpp"

class Alarm {
public:
  Alarm();
  Alarm(Sensor* sensor);
  void check();
  bool isAlarmOn();
  static const double LOW_PRESSURE_THRESHOLD;
  static const double HIGH_PRESSURE_THRESHOLD;
private:
  Sensor* sensor;
  bool alarmOn;
};

#endif /* ALARM_HPP */
