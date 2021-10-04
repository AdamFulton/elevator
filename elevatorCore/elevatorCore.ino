/*
 * This is the main file for the Arduino MEGA.
 * Open this is the Arduino IDE.
 */

//#include <Arduino.h>
#include "DummyLibs.h"
#include "Control_Logic.h"
#include "MotorSensors.h"
#include "MainMotor.h"



ButtonLibDummy buttonLibDummy;
MotorSensors motorSensors;
ControlLogic controlLogic = ControlLogic(buttonLibDummy, motorSensors);
MainMotor mainMotor;

void setup (){
    Serial.begin(9600);
    motorSensors.setup();
    mainMotor.setup();
    //any first time startup code here.
}

void loop () {
    //call your modules here.
    motorSensors.loop();
    controlLogic.loop();
    mainMotor.loop();
}