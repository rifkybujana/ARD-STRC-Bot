#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

#define STOP 0
#define CLOCKWISE 1
#define COUNTERCLOCKWISE 2

class Motor {
  public:
    Motor(int* pin);
    
    void Forward();
    void Right();
    void Left();
    void Backward();
    void Stop();
  private:
    int* _pin;

    void SetMotorLeft(int dir);
    void SetMotorRight(int dir);
};

#endif
