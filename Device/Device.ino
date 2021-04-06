#include "Motor.h"
#include "Sensor.h"

struct Sensors
{
  Sensor front;
  Sensor right;
  Sensor left;
} sensors = { Sensor(11), Sensor(12), Sensor(13) };

int motorPin[4] = { 2, 3, 4, 5 };
Motor motor(motorPin);

void setup() {

}

void loop() {
  
}
