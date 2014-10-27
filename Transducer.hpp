#ifndef TRANSDUCER_HPP
#define TRANSDUCER_HPP

class Transducer {
public:
  double virtual popNextPressurePsiValue() = 0;
};

#endif /* TRANSDUCER_HPP */