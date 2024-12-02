#include "gaz_sensor.h"


void GazSensor::setup() {
    pinMode(pin_sensor, INPUT);
}

float GazSensor::get_sensor_value() {
    return analogRead(pin_sensor);
}

float GazSensor::get_sensor_volt() {

    return GazSensor::get_sensor_value()/1024*5.0;
}
