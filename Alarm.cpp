#include "Alarm.hpp"
#include "Transducer.hpp"

void Alarm::check() {
  double psiPressureValue = sensor->popNextPressurePsiValue();

  if (psiPressureValue < LOW_PRESSURE_THRESHOLD || HIGH_PRESSURE_THRESHOLD < psiPressureValue) {
    alarmOn = true;
  }
}

bool Alarm::isAlarmOn() {
  return alarmOn;
}

Alarm::Alarm() {
  // TODO-smell: Depending on a concrete Sensor instance violates the DIP and OCP
  sensor = new Sensor;
  alarmOn = false;
}

Alarm::Alarm(Transducer *transducer) {
}

const double Alarm::LOW_PRESSURE_THRESHOLD = 17;
const double Alarm::HIGH_PRESSURE_THRESHOLD = 21;