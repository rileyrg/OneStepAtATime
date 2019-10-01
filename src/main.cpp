#include <Arduino.h>
#include <Stepper.h>

#define LEDPIN 13

// for your motor
// initialize the stepper library on pins 2 through 5:
#define STEPSPERREVOLUTION 4096
Stepper myStepper(STEPSPERREVOLUTION, 2, 3, 4, 5);

int stepCount = 0;         // number of steps the motor has taken

void setup() {
  // initialize the serial port:
  // Serial.begin(9600);
 pinMode(LEDPIN, OUTPUT);

  // initialize timer1 
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  // TCNT1 = 34286;            // preload timer 65536-16MHz/256/2Hz
  TCNT1 = 14286;            // preload timer 65536-16MHz/256/2Hz
  TCCR1B |= (1 << CS12);    // 256 prescaler 
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  interrupts();             // enable all interrupts}
}

ISR(TIMER1_OVF_vect)        // interrupt service routine that wraps a user defined function supplied by attachInterrupt
{
  // TCNT1 = 34286;                // preload timer
  TCNT1 = 14286;            // preload timer
  digitalWrite(LEDPIN, digitalRead(LEDPIN) ^ 1);
}

void loop() {
  // step one step:
  myStepper.step(1);
  // Serial.print("steps:");
  // Serial.println(stepCount);
  stepCount++;
  delay(100);
}
