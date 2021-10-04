#include "DoorServo.hpp"
#include "Arduino.h"
#include "Servo.h"


DoorServo::DoorServo(int pinAttach, Servo doorServo) {

    this->pinAttach = pinAttach;
    this-> doorServo = doorServo;
    doorServo.attach(pinAttach);
}

DoorServo::openDoor(int writeOpen, Servo doorServo)  {

    doorServo.write(writeOpen);
}

DoorServo:: closeDoor(int writeClose, Servo DoorServo) {

    doorServo.write(writeClose);
}
