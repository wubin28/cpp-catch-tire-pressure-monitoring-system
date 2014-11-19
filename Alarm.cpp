#include "Alarm.hpp"

void Alarm::check() {
  alarmOn = false;
  double psiPressureValue = sensor->popNextPressurePsiValue();

  if (psiPressureValue < LOW_PRESSURE_THRESHOLD || HIGH_PRESSURE_THRESHOLD < psiPressureValue) {
    alarmOn = true;
  }
}

bool Alarm::isAlarmOn() {
  return alarmOn;
}

Alarm::Alarm() {
  Alarm(new Sensor());
}

Alarm::Alarm(Sensor* sensor) : sensor(sensor), alarmOn(false) {
}

void Alarm::setSensor(Sensor* sensor) {
  this->sensor = sensor;
}

const double Alarm::LOW_PRESSURE_THRESHOLD = 17;
const double Alarm::HIGH_PRESSURE_THRESHOLD = 21;
