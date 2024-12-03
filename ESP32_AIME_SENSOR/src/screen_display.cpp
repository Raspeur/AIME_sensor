#include "screen_display.h"

void ScreenDisplay::stateMachine() {
    int sensor_has_been_touched = ScreenDisplay::aChangeHasBeenDone();
    gaz_sensor_voltage = gazSensor.get_sensor_volt();
    if (sensor_has_been_touched == 1) {
        screen_number = (screen_number + 1) % 2;
        oledScreen.oled.clearDisplay();  // Effaçage de l'intégralité du buffer
    }

    if (screen_number == 1) {
        // We display LoRa communication
        ScreenDisplay::screenOne();
    } else {
        // We display gaz sensor data
        ScreenDisplay::screenTwo();
    }
}

void ScreenDisplay::screenOne() {
    Serial.println("Displaying LoRa Communication screen");
    oledScreen.oled.clearDisplay(); 
    oledScreen.DisplayText(0, 0, "LoRa Communication", 1);
}

void ScreenDisplay::screenTwo() {
    Serial.println("Displaying Sensor Data screen");                                 
    oledScreen.DisplayText(0, 0, "Sensor Data", 1);
    oledScreen.DisplayText(0, 20, "Gaz Sensor: ", 1);
    oledScreen.DisplayText(0, 30, "            ", 1);
    oledScreen.DisplayText(0, 30, gaz_sensor_voltage, 1);
}

int ScreenDisplay::aChangeHasBeenDone() {
    int current_touch = touchSensor.get_sensor_value();
    Serial.print("Le bouton est à ");
    Serial.println(current_touch);
    int change_detected = (current_touch == 1 && last_touch == 0);
    last_touch = current_touch;
    return change_detected;
}