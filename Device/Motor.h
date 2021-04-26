#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h> 

class Motor {
  public:
    Motor(int* PWM, int* Direction);

    void SetSpeed(float Speed);

    void Forward(float rSpeed, float lSpeed);
    void Backward(float rSpeed, float lSpeed);
    void Stop(float rSpeed, float lSpeed);

  private:
    int* _PWM;
    int* _Direction;
};

#endif
