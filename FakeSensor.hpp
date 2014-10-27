#ifndef FAKESENSOR_HPP
#define FAKESENSOR_HPP

#include "Transducer.hpp"

class FakeSensor : public Transducer {
public:
  void fakeNextPressurePsiValue(double nextPressure);
  void fakeNextPressurePsiValueAgain(double nextPressure);
  double popNextPressurePsiValue() override;
private:
  double nextPressure = 0.0;
  double nextPressureAgain = 0.0;
  int methodCallCounter = 0;
};

#endif /* FAKESENSOR_HPP */