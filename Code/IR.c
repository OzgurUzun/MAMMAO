#include "headers/IR.h"
#include "headers/MOTOR.h"
#include "headers/PINS.h"
void ir_setup()
{
  pinMode(irL, INPUT);
  pinMode(irR, INPUT);
}

void line_tracking()
{
  ultrasonic_sensors_check(results, ultrasonic_sensors_pins[], num_ultrasonic_sensors, num_ultrasonic_samples);
  if (isClose(results[0], results[1], results[2]))
  {
    stop();
  }
  else if (!isClose(results[0], results[1], results[2]) && digitalRead(irL) == HIGH)
  {
    left();
  }
  else if (!isClose(results[0], results[1], results[2]) && digitalRead(irR) == HIGH)
  {
    right();
  }
  else
  {
    forward();
  }
}

bool isClose(float a, float b, float c)
{
  if (a > 10 && b > 10 && c > 10)
  {
    return false;
  }
  else
    return true;
}