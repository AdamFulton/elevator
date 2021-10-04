//
// Created by tegef on 27/08/2019.
// C30 code
//

#include "FSM.h"
#include "Globals.h"


Fsm::Fsm(ButtonLibDummy& buttonLibDummy, MotorSensors& motorSensors, Pathfinder& pathfinder)
        : _buttonLibDummy(buttonLibDummy), _motorSensors(motorSensors), _pathFinder(pathfinder){
    _state = S0;
};

void Fsm::loop(){

    debugPrint("-LOOP-");

    if(getEmergency()){
        emergencyStop();
        _state = Semergency;
    }

    switch (_state) {
        case S0 :
            debugPrint("-state S0-");
            _state = Sidle;
            break;

        case Sidle :
            debugPrint("-state idle-");
            if(_pathFinder.getDirection() != 0){
                if(DOORS_ENABLED){
                    openDoors();
                    _state = SdoorOpen;
                }else{
                    startDelay(1000);
                    _state = Sdelay;
                }
            }
            break;

        case Smoving :
            debugPrint("-state moving-");
            if(_pathFinder.getStopNext()){
                stopNextFloor();
            }
            if(getStoppedAtFloor()){
                //let controlPanel know we've stopped.
                _state = Sidle;
            }
            break;

        case SdoorOpen :
            debugPrint("-state doorOpen-");
            if(getDoorsAreOpen()){
                startDelay(1000);
                _state = Sdelay;
            }
            break;

        case SdoorClose :
            debugPrint("-state doorClose-");
            if(getDoorsAreClosed()){
                if(_pathFinder.getDirection() == 1){ //up
                    startMovement(1);
                }else if(_pathFinder.getDirection() == 2){ //down
                    startMovement(0);
                }

                _state = Smoving;
            }
            break;

        case Sdelay :
            debugPrint("-state delay-");
            if(isDelayFinished()){
                if(DOORS_ENABLED) {
                    closeDoors();
                    _state = SdoorClose;
                }else{
                    if(_pathFinder.getDirection() == 1){ //up
                        startMovement(1);
                    }else if(_pathFinder.getDirection() == 2){ //down
                        startMovement(0);
                    }
                    _state = Smoving;
                }
            }
            break;

        case Semergency :
            debugPrint("-state emergency-");
            break;

    }

    //any pass through information here

};

void Fsm::startDelay(unsigned long delay) {
    //_delay = millis() + delay;
};

bool Fsm::isDelayFinished() {
    //return millis() >= _delay;
    return true;
};


// theses are input functions

bool Fsm::getEmergency() {
    return false;
};

bool Fsm::getDoorsOpenSelected() {};

bool Fsm::getDoorsCloseSelected() {};

bool Fsm::getStoppedAtFloor() {
    return true;
  }; //TODO

bool Fsm::getStoppedAtEnds() {};

bool Fsm::getDoorsAreOpen() {};

bool Fsm::getDoorsAreClosed() {};

//theses are output functions

void Fsm::startMovement(unsigned short direction) {}; //TODO

void Fsm::stopNextFloor() {};

void Fsm::openDoors() {};

void Fsm::closeDoors() {};

void Fsm::resetToGround() {};

void Fsm::emergencyStop() {
    debugPrint("---!!EMERGENCY STOP!!---");
}; //TODO
