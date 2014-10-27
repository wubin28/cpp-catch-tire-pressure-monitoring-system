#include "FakeSensor.hpp"

void FakeSensor::fakeNextPressurePsiValue(double nextPressure){
  this->nextPressure = nextPressure;
}

void FakeSensor::fakeNextPressurePsiValueAgain(double nextPressure){
  this->nextPressureAgain = nextPressure;
}

double FakeSensor::popNextPressurePsiValue() {
  methodCallCounter += 1;
  return methodCallCounter > 1 ? this->nextPressureAgain : this->nextPressure;
}
