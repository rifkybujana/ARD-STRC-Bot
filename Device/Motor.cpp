#include "Motor.h"
#include <Arduino.h>

Motor::Motor(int* PWM, int* Direction){
  _PWM = PWM;
  _Direction = Direction;
  
  pinMode(PWM[0], OUTPUT);
  pinMode(PWM[1], OUTPUT);
  pinMode(Direction[0], OUTPUT);
  pinMode(Direction[1], OUTPUT);
}

void Motor::Forward(float rSpeed, float lSpeed){
  digitalWrite(_PWM[0], rSpeed);
  digitalWrite(_PWM[1], lSpeed);
  
  digitalWrite(_Direction[0], HIGH);
  digitalWrite(_Direction[1], HIGH);
}


void Motor::Backward(float rSpeed, float lSpeed){
  digitalWrite(_PWM[0], rSpeed);
  digitalWrite(_PWM[1], lSpeed);
  
  digitalWrite(_Direction[0], LOW);
  digitalWrite(_Direction[1], LOW);
}
