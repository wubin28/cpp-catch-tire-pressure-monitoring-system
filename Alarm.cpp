#include "Alarm.hpp"
#include "Transducer.hpp"

void Alarm::check() {
  double psiPressureValue = transducer->popNextPressurePsiValue();

  if (psiPressureValue < LOW_PRESSURE_THRESHOLD || HIGH_PRESSURE_THRESHOLD < psiPressureValue) {
    alarmOn = true;
  }
}

bool Alarm::isAlarmOn() {
  return alarmOn;
}

Alarm::Alarm() {
  Alarm(new Sensor);
}

Alarm::Alarm(Transducer *transducer) {
  this->transducer = transducer;
  alarmOn = false;
}

const double Alarm::LOW_PRESSURE_THRESHOLD = 17;
const double Alarm::HIGH_PRESSURE_THRESHOLD = 21;