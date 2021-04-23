#include "Motor.h"
#include "Sensor.h"
#include "Connection.h"

#include <Servo.h>

Servo servo;
int pos = 0;

Connection connection;

struct Sensors
{
  Sensor front;
  Sensor right;
  Sensor left;
} sensor = { Sensor(D8), Sensor(D7), Sensor(D6) };

int PWM[2] = { 5, 4 };
int Direction[2] = { 0, 2 };
Motor motor(PWM, Direction);

int currentRoom = 0;

void setup() {
  servo.attach(D5);
}

void loop() {

}
