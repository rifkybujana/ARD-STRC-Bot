#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor{
  public:
    Sensor(int pin);
    int operator()();
    
  private:
    int _pin;
};

#endif
