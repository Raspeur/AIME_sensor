#include "touch_sensor.h"


TouchSensor::TouchSensor() {
    pinMode(pin_sensor, INPUT);
}

int TouchSensor::get_sensor_value() {
    return digitalRead(pin_sensor);
}
