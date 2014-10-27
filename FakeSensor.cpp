#include "FakeSensor.hpp"

void FakeSensor::fakeNextPressurePsiValue(double nextPressure){
  this->nextPressure = nextPressure;
}

double FakeSensor::popNextPressurePsiValue() {
  return this->nextPressure;
}
