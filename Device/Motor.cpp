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

void Motor::SetSpeed(float Speed){
  _Speed = Speed;

  digitalWrite(_PWM[0], _Speed);
  digitalWrite(_PWM[1], _Speed);
}

void Motor::Forward(){
  digitalWrite(_PWM[0], _Speed);
  digitalWrite(_PWM[1], _Speed);
  
  digitalWrite(_Direction[0], HIGH);
  digitalWrite(_Direction[1], HIGH);
}


void Motor::Backward(){
  digitalWrite(_PWM[0], _Speed);
  digitalWrite(_PWM[1], _Speed);
  
  digitalWrite(_Direction[0], LOW);
  digitalWrite(_Direction[1], LOW);
}

void Motor::Right(){
  digitalWrite(_PWM[0], _Speed);
  digitalWrite(_PWM[1], _Speed);
  
  digitalWrite(_Direction[0], HIGH);
  digitalWrite(_Direction[1], LOW);
}

void Motor::Left(){
  digitalWrite(_PWM[0], _Speed);
  digitalWrite(_PWM[1], _Speed);
  
  digitalWrite(_Direction[0], LOW);
  digitalWrite(_Direction[1], HIGH);
}

void Motor::Stop(){
  digitalWrite(_PWM[0], LOW);
  digitalWrite(_PWM[1], LOW);
}
