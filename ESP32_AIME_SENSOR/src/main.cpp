#include <Arduino.h>
#include <SoftwareSerial.h>

// Define the SoftwareSerial pins
const int rxPin = 16;  // RX pin to Arduino (connect to TX of RN2483)
const int txPin = 17;  // TX pin from Arduino (connect to RX of RN2483)

// Create a SoftwareSerial object
SoftwareSerial loraSerial(rxPin, txPin);

#define RESET_PIN 5  // Define the pin connected to the reset pin of the RN2483

void loraSendCommand(String command) {
  while (loraSerial.available()) {
    loraSerial.read();
  }
  // Send the command to the RN2483 module
  loraSerial.println(command);
  // Wait for a response
  String response = "";
  unsigned long timeout = millis() + 5000;  // 5 seconds timeout
  while (millis() < timeout) {
    if (loraSerial.available()) {
      char c = loraSerial.read();
      response += c;
      // Check if response ends with "\r\n"
      if (response.endsWith("\r\n")) {
        break;
      }
    }
  }
  // Print the response to the Serial Monitor
  Serial.println("Response: " + response);
}

void setup() {
  Serial.begin(9600);
  // Initialize software serial for RN2483 communication
  loraSerial.begin(57600);  // Default baud rate of the RN2483 is 57600
  Serial.println("LoRa RN2483 Communication Setup");

  // Set the reset pin as output
  pinMode(RESET_PIN, OUTPUT);
  
  // Reset the RN2483 module
  Serial.println("Resetting RN2483 module");
  digitalWrite(RESET_PIN, LOW);  // Pull the reset pin low
  delay(100);                    // Wait for 100ms
  digitalWrite(RESET_PIN, HIGH); // Release the reset pin
  delay(1000);                   // Wait for the module to reset
  digitalWrite(RESET_PIN, LOW);  // Pull the reset pin low
  delay(100);                    // Wait for 100ms
  digitalWrite(RESET_PIN, HIGH); // Release the reset pin
  delay(1000);                   // Wait for the module to reset
  // Initialization commands to configure the RN2483
  //Serial.println("Sending: sys reset");
  //loraSendCommand("sys reset");
  //delay(100);
  Serial.println("Sending: sys get ver");
  loraSendCommand("sys get ver");
  delay(1000);

  Serial.println("Sending: radio set wdt 0");
  loraSendCommand("radio set wdt 0");
  delay(1000);
  
  Serial.println("Sending: mac pause");
  loraSendCommand("mac pause");
  delay(1000);
  
  Serial.println("Sending: radio set sync FF");
  loraSendCommand("radio set sync FF");
  delay(1000);
}

void loop() {
  // Send the message "FFFFFFFF"
  String messageToSend = "FFFFFFFF";
  Serial.println("Sending Hex Message: " + messageToSend);
  
  // Send the hex string
  loraSendCommand("radio tx " + messageToSend);
  
  // Wait for a while before sending the next packet
  delay(20000);  // Send data every 20 seconds
}