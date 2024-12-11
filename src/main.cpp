#include <Arduino.h>

//Libraries for LoRa
//#include <SPI.h>
//#include <LoRa.h>

//Libraries for OLED Display
//#include <Wire.h>
//#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "config.h"

void setup() {
  Serial.begin(9600);
  while(!Serial);
  delay(5000);  // Give time to switch to the serial monitor
  Serial.println(F("\nSetup ... "));

  Serial.println(F("Initialise the radio"));
  int16_t state;
  int i = 0;
  state = radio.begin();
  debug(state != RADIOLIB_ERR_NONE, F("Initialise radio failed"), state, true);

  
  Serial.println(F("Initialise the radio2"));
  // Setup the OTAA session information
    state = node.beginOTAA(joinEUI, devEUI, 0, appKey);
    debug(state != RADIOLIB_ERR_NONE, F("Initialise node failed"), state, true);
  
  
  do{
    delay(5000);  // Wait for the serial monitor to open
    Serial.println(F("Join ('login') the LoRaWAN Network"));
    state = node.activateOTAA();
    debug(state != RADIOLIB_LORAWAN_NEW_SESSION, F("Join failed"), state, false);
  } while (state != RADIOLIB_ERR_NONE && i++ < 5);
   
  Serial.println(F("Ready!\n"));
}

void loop() {
  Serial.println(F("Sending uplink"));

  // This is the place to gather the sensor inputs
  // Instead of reading any real sensor, we just generate some random numbers as example
  uint8_t value1 = radio.random(100);
  uint16_t value2 = radio.random(2000);

  // Build payload byte array
  uint8_t uplinkPayload[3];
  uplinkPayload[0] = value1;
  uplinkPayload[1] = highByte(value2);   // See notes for high/lowByte functions
  uplinkPayload[2] = lowByte(value2);
  
  // Perform an uplink
  int16_t state = node.sendReceive(uplinkPayload, sizeof(uplinkPayload));    
  debug(state < RADIOLIB_ERR_NONE, F("Error in sendReceive"), state, false);

  // Check if a downlink was received 
  // (state 0 = no downlink, state 1/2 = downlink in window Rx1/Rx2)
  if(state > 0) {
    Serial.println(F("Received a downlink"));
  } else {
    Serial.println(F("No downlink received"));
  }

  Serial.print(F("Next uplink in "));
  Serial.print(uplinkIntervalSeconds);
  Serial.println(F(" seconds\n"));
  
  // Wait until next uplink - observing legal & TTN FUP constraints
  delay(15000UL);  // delay needs milli-seconds
}
