#include <Arduino.h>
#include "screen_display.h"

ScreenDisplay screenDisplay;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  screenDisplay.oledScreen.initScreen();
}

// the loop function runs over and over again forever
void loop() {
  screenDisplay.stateMachine();
  //gazSensor.get_sensor_volt();
  //Serial.println(gazSensor.get_sensor_volt());
}