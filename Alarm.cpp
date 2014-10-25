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
	sensor = new Sensor;
	alarmOn = false;
}

const double Alarm::LowPressureThreshold = 17;
const double Alarm::HighPressureThreshold = 21;
