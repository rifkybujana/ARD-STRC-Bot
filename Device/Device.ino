#include "Motor.h"
#include "Sensor.h"
#include "Connection.h"
#include "Timer.h"
#include <Servo.h>

// Setup Servo
Servo servo;

// Current Servo Rotation Position
int pos = 0;

// Setup Connection to the server
Connection connection;

struct Sensors
{
  Sensor front;
  Sensor right;
  Sensor rRight;
  Sensor left;
  Sensor lLeft;
} sensor = { Sensor(D8), Sensor(D7), Sensor(D6), Sensor(D5), Sensor(D4) };

// Setup Motor Pin
int PWM[2] = { 5, 4 };
int Direction[2] = { 0, 2 };

// Setup Motor
Motor motor(PWM, Direction);

int lastRoom = 0;
int currentRoom = 0;

// Setup Event Timer
Timer timer;

void OpenMouth();
void CloseMouth();

void UpdateRoom();

void setup() 
{
  servo.attach(D5);
  motor.Stop();

  // Get Room every half second
  timer.every(500, UpdateRoom);
}

void loop() 
{
  if (currentRoom != lastRoom) 
  {

    float rSpeed = 450;
    float lSpeed = 450;

    switch (currentRoom) 
    {
      case 1:

        switch (lastRoom)
        {
          case 1:
            break;

          case 2:
            break;

          case 3:
            break;

          default:
          
            // if the robot slightly tilted to left
            if (sensor.rRight() == 0 && sensor.right() == 1) 
            {
              lSpeed--;
            }
    
            // if the robot slightly tilted to right
            if (sensor.lLeft() == 0 && sensor.left() == 1) 
            {
              rSpeed--;
            }
    
            // if the robot detect a turn to left
            if (sensor.lLeft() == 0 && sensor.left() == 0) 
            {
              lSpeed = LOW;
              rSpeed = 450;
            }
    
            if (sensor.rRight() == 1 
                && sensor.right() == 1 
                && sensor.lLeft == 1 
                && sensor.left() == 1 
                && sensor.front() == 0)
            {
              lSpeed = 450;
              rSpeed = 450;
            }
    
            if (sensor.rRight() == 1 
                && sensor.right() == 1 
                && sensor.lLeft == 1 
                && sensor.left() == 1 
                && sensor.front() == 1)
            {
              lSpeed = LOW;
              rSpeed = LOW;
    
              lastRoom = currentRoom;
    
              OpenMouth();
    
              delay(1000);
    
              CloseMouth();
            }
    
            motor.Forward(rSpeed, lSpeed);
            break;
        }
       
        break;

      case 2:

        switch (lastRoom)
        {
          case 1:
            break;

          case 2:
            break;

          case 3:
            break;

          default:
            break;
        }
      
        break;

      case 3:
      
        switch (lastRoom)
        {
          case 1:
            break;

          case 2:
            break;

          case 3:
            break;

          default:
            break;
        }
        
        break;

      default:
      
        switch (lastRoom)
        {
          case 1:
            break;

          case 2:
            break;

          case 3:
            break;

          default:
            break;
        }
        
        break;
    }

  }
  else
  {
    timer.update();
  }
}

void UpdateRoom() 
{
  currentRoom = connection.Get();
}

void OpenMouth() 
{
  for (pos = 0; pos < 180; pos++) 
  {
    servo.write(pos);
  }
}

void CloseMouth() 
{
  for (pos = 180; pos > 0; pos--) 
  {
    servo.write(pos);
  }
}
