#include "IRSensor.hpp"
#include "Arduino.h"
class IRSensor {


IRSensor:: IRSensor(int pin, int beamBroken) {

    this-> pin = pin;
    this-> beamBroken = beamBroken;
}
void irDetection(int pin, int beamBroken) {

    beamBroken = digitalRead(pin);
     if (beamBroken == HIGH) {
         digitalWrite(HIGH);
     } else {
          digitalWrite (LOW);
     }
}
    
}