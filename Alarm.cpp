#include "Alarm.hpp"

void Alarm::check() {
	double psiPressureValue = sensor->popNextPressurePsiValue();

	if (psiPressureValue < LowPressureThreshold || HighPressureThreshold < psiPressureValue) {
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

const double Alarm::LowPressureThreshold = 17;
const double Alarm::HighPressureThreshold = 21;
