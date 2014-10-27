#ifndef FAKESENSOR_HPP
#define FAKESENSOR_HPP

#include "Transducer.hpp"

class FakeSensor : public Transducer {
public:
  void fakeNextPressurePsiValue(double nextPressure);
};

#endif /* FAKESENSOR_HPP */