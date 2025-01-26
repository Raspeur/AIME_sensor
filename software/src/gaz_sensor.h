#ifndef MY_GAZ_SENSOR_H
#define MY_GAZ_SENSOR_H

#include <Arduino.h> 


class GazSensor {
private:
    int pin_sensor = 13;
public:
    GazSensor();
    float get_sensor_volt();

private:
    float get_sensor_value();
};

#endif