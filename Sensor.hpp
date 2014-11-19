#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <random>

class Sensor {
public:
  Sensor();
  static const double OFFSET;
  double popNextPressurePsiValue();

private:
  static double samplePressure();
};

class FakeSensor : public Sensor {
public:
  FakeSensor(double fakePressureValue);
private:
  double fakePressureValue;
};

#endif /* SENSOR_HPP */
