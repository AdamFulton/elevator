#include "Arduino.h"
#include "Servo.h"
class DoorServo {

private:
int pinAttach;
Servo doorServo;


public:

DoorServo(int pinAttach, Servo doorServo);

void openDoor(int writeOpen, Servo doorServo);
void closeDoor(int writeClose, Servo doorServo);




}