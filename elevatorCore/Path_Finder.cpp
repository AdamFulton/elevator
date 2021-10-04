//
// Created by tegef on 27/08/2019.
// C30 code
//

#include "Path_Finder.h"


Pathfinder::Pathfinder(ButtonLibDummy& buttonLib, MotorSensors& motorSensors)
        : _buttonLib(buttonLib), _motorSensors(motorSensors) {
};


int Pathfinder::getDestination() {
    return 2;
};//TODO replace with actual lib

int Pathfinder::getDirection() {
    return 1;
}; //TODO replace with actual lib

bool Pathfinder::getStopNext() {
    return true;
}; //TODO replace with actual lib


bool Pathfinder::getFirstFloorSelected() {};
bool Pathfinder::getSecondFloorSelected() {};
bool Pathfinder::getThirdFloorSelected() {};
bool Pathfinder::getFourthFloorSelected() {};
bool Pathfinder::getFifthFloorSelected() {};





