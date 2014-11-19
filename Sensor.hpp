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
};

#endif /* SENSOR_HPP */
