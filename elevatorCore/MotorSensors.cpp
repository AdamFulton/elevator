//
// Created by Faulkes on 8/09/2019.
//

#include "Sensors.h"


Sensors::Sensors(): mma()  {
    //Beam breaker sensors

    BBS1 = 26;
    BBS2 = 27;
    BBS3 = 28;
    BBS4 = 29;
    emgTop = 30;

//Variables to test where sensor is within shaft
    inBBS1 = 0;
    inBBS2 = 0;
    inBBS3 = 0;
    inBBS4 = 0;

//Pins for the load sensor and create an object for the load cell
    LOADCELL_DOUT_PIN = 2;
    LOADCELL_SCK_PIN = 3;
}

void Sensors::setup() {
    Serial.begin(9600);
    //Load Cell Setup
    scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
    scale.set_scale(1); // THIS WILL NEED TO BE CHANGED TO CONVERT THE UNITS INTO KG.
    scale.tare(carriageWeight);
    //Accelerometer Setup
    if(!mma.begin()){
        Serial.println("Accelerometer couldn't start");
        while(1);
    }
    mma.setRange(MMA8451_RANGE_2_G);
    //Assigns beam breakers to pins
    pinMode(BBS1,INPUT);
    pinMode(BBS2,INPUT);
    pinMode(BBS3,INPUT);
    pinMode(BBS4,INPUT);
    pinMode(emgTop,INPUT);
}

void Sensors::loop() {
    //emergency stop
    if(digitalRead(emgTop)==HIGH){
        //put in code to stop motor
    }
    loadCell();
}

void Sensors::startMovement(bool direction) {
    //This is an example of a control method. look in Sensor.ino for example
}

bool Sensors::movementStopped() {
    //this is an example of a control method. look in Sensor.ino for example
}

float Sensors::accelerometer() {
        mma.read();
        sensors_event_t event;
        mma.getEvent(&event);
        return event.acceleration.y;
        //put code for emergency stop
}

float Sensors::loadCell() {
    return(scale.get_units());
}

//Returns the level above the elevator
//returns -1 if there isn't enough information on where the elevator is headed
int Sensors::levelAbove() {
    if(digitalRead(BBS1)==HIGH){
        inBBS1 = 1;
        return 2;
    } else if(digitalRead(BBS2)==HIGH){
        inBBS1 = 0;
        inBBS2 = 1;
        return 3;
    } else if(digitalRead(BBS3)==HIGH){
        inBBS2 = 0;
        inBBS3 = 1;
        return 4;
    } else if(digitalRead(BBS4)==HIGH){
        inBBS3 = 0;
        inBBS4 = 1;
        return 5;
    }
    if(inBBS1 == 1){
        return 3;
    } else if (inBBS2 == 1){
        return 4;
    } else if (inBBS3 == 1){
        return 5;
    }
    return -1;
}

//Returns the level below the elevator
//returns -1 if there isn't enough information on where the elevator is headed
int Sensors::levelBelow() {
    if(digitalRead(BBS4)==HIGH){
        inBBS4 = 1;
        return 4;
    } else if(digitalRead(BBS3)==HIGH){
        inBBS4 = 0;
        inBBS3 = 1;
        return 3;
    } else if(digitalRead(BBS2)==HIGH){
        inBBS3 = 0;
        inBBS2 = 1;
        return 2;
    } else if(digitalRead(BBS1)==HIGH){
        inBBS2 = 0;
        inBBS1 = 1;
        return 1;
    }
    if(inBBS2 == 1){
        return 1;
    } else if (inBBS3 == 1){
        return 2;
    } else if (inBBS4 == 1){
        return 3;
    }
    return -1;
}