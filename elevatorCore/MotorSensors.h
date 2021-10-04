//
// Created by Faulkes on 8/09/2019.
//

#ifndef ELEVATOR_MOTORSENSORS_H
#define ELEVATOR_MOTORSENSORS_H

#include <stdio.h>
#include "HX711.h"
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>
#include "Globals.h"


/*
 * README
 *
 * accelerometer() returns a float of the current acceleration of the carriage
 *
 * loadCell() returns a float of the current weight of the carriage
 *
 * levelAbove() returns an int of the level currently above the elevator
 *
 * levelBelow() returns an int of the level currently below the elevator
 *
 */


class MotorSensors{
public:
    MotorSensors();

    void setup();

    void loop();

    void startMovement(bool direction);
    bool movementStopped();

private:

    float accelerometer();

    float loadCell();

    int levelAbove();
    
    int levelBelow();


    //Beam breaker sensors

    int BBS1;
    int BBS2;
    int BBS3;
    int BBS4;
    int emgTop;

//Variables to test where sensor is within shaft
    int inBBS1;
    int inBBS2;
    int inBBS3;
    int inBBS4;

//Pins for the load sensor and create an object for the load cell
    int LOADCELL_DOUT_PIN;
    int LOADCELL_SCK_PIN;
    HX711 scale;

//weight of the elevator
    double carriageWeight;

//Accelerometer object
    Adafruit_MMA8451 mma;

};

#endif //ELEVATOR_MOTORSENSORS_H
