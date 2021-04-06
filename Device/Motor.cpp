#include "Motor.h"
#include <Arduino.h>

Motor::Motor(int* pin){
  _pin = pin;
  
  for (int i = 0; i < 4; i++){
    pinMode(pin[i], OUTPUT);
  }
}

void Motor::SetMotorLeft(int dir){
  switch(dir){
    case STOP:
      // stop
      digitalWrite(_pin[0], LOW);
      digitalWrite(_pin[1], LOW);

    case CLOCKWISE:
      // clockwise
      digitalWrite(_pin[0], HIGH);
      digitalWrite(_pin[1], LOW);

    case COUNTERCLOCKWISE:
      // counterclockwise
      digitalWrite(_pin[0], LOW);
      digitalWrite(_pin[1], HIGH);
  }
}

void Motor::SetMotorRight(int dir){
  switch(dir){
    case STOP:
      // stop
      digitalWrite(_pin[2], LOW);
      digitalWrite(_pin[3], LOW);

    case CLOCKWISE:
      // clockwise
      digitalWrite(_pin[2], HIGH);
      digitalWrite(_pin[3], LOW);

    case COUNTERCLOCKWISE:
      // counterclockwise
      digitalWrite(_pin[2], LOW);
      digitalWrite(_pin[3], HIGH);
  }
}

void Motor::Forward(){
  SetMotorLeft(CLOCKWISE);
  SetMotorRight(CLOCKWISE);
}

void Motor::Right(){
  SetMotorLeft(CLOCKWISE);
  SetMotorRight(COUNTERCLOCKWISE);
}

void Motor::Left(){
  SetMotorLeft(COUNTERCLOCKWISE);
  SetMotorRight(CLOCKWISE);
}

void Motor::Backward(){
  SetMotorLeft(COUNTERCLOCKWISE);
  SetMotorRight(COUNTERCLOCKWISE);
}

void Motor::Stop(){
  SetMotorLeft(STOP);
  SetMotorRight(STOP);
}
