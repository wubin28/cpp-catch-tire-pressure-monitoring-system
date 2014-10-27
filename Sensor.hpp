#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <random>
#include "Transducer.hpp"

class Sensor : public Transducer {
public:
  static const double OFFSET;
  double popNextPressurePsiValue() override;

private:
  static double samplePressure();
};

#endif /* SENSOR_HPP */
