#ifndef MY_TOUCH_SENSOR_H
#define MY_TOUCH_SENSOR_H

#include <Arduino.h> 


class TouchSensor {
private:
    int pin_sensor = 37 ;
public:
    TouchSensor();
    int get_sensor_value();
};

#endif