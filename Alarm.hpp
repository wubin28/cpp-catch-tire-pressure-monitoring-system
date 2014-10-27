#ifndef ALARM_HPP
#define ALARM_HPP

#include "Sensor.hpp"
#include "Transducer.hpp"

class Alarm {
public:
  Alarm();
  Alarm(Transducer *transducer);
  void check();
  bool isAlarmOn();
  static const double LOW_PRESSURE_THRESHOLD;
private:
  static const double LowPressureThreshold;
  static const double HighPressureThreshold;
  Sensor* sensor;
  bool alarmOn;
};

#endif /* ALARM_HPP */
