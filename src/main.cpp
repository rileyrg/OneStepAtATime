#include <Arduino.h>
#include <Stepper.h>

#define STEPSPERREVOLUTION 4096
// for your motor
// initialize the stepper library on pins 2 through 5:
Stepper myStepper(STEPSPERREVOLUTION, 2, 3, 4, 5);
int stepCount = 0;         // number of steps the motor has taken
void setup() {
  // initialize the serial port:
  // Serial.begin(9600);
}
void loop() {
  // step one step:
  myStepper.step(1);
  // Serial.print("steps:");
  // Serial.println(stepCount);
  stepCount++;
  delay(10);
}
