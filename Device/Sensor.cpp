#include "Sensor.h"
#include <Arduino.h>

Sensor::Sensor(int pin){
  _pin = pin;

  pinMode(pin, OUTPUT);
}

int Sensor::operator()(){
  return digitalRead(_pin);
}
