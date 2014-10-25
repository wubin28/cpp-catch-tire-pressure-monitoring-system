#ifndef ALARM_HPP
#define ALARM_HPP

#include "Sensor.hpp"

class Alarm {
public:
	Alarm();
	void check();
	bool isAlarmOn();
private:
	static const double LowPressureThreshold;
	static const double HighPressureThreshold;
	Sensor* sensor;
	bool alarmOn;
};

#endif /* ALARM_HPP */
