#include <Arduino.h>
#include "gaz_sensor.h"

GazSensor gazSensor;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  gazSensor.setup();
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  gazSensor.get_sensor_volt();
  Serial.println(gazSensor.get_sensor_volt());
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}