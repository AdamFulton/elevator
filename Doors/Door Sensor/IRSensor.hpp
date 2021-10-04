#include "arduino.h"

class IRSensor {

    private:
    int pin;
    int beamBroken;


    IRSensor(int pin, int beamBroken);

    void irDetection(int beamBroken, int pin);






}