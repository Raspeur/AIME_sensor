#ifndef MY_SCREEN_DISPLAY_H
#define MY_SCREEN_DISPLAY_H

#include <Arduino.h> 
#include "gaz_sensor.h"
#include "oled_screen.h"
#include "touch_sensor.h"


class ScreenDisplay {
private:
    int screen_number = 0;  
    int last_touch = 0; 
    GazSensor gazSensor;
    TouchSensor touchSensor;
    int gaz_sensor_voltage = 0;
public:
    OledScreen oledScreen;
    void stateMachine();
    void screenOne();
    void screenTwo();
    int aChangeHasBeenDone();
};

#endif