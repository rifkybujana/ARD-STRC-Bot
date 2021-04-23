#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h> 

class Motor {
  public:
    Motor(int* PWM, int* Direction);

    void SetSpeed(float Speed);

    void Forward();
    void Backward();
    void Right();
    void Left();
    void Stop();

  private:
    int* _PWM;
    int* _Direction;

    float _Speed = 450;
};

#endif
