//
// Created by Faulkes on 2/09/2019.
// C30 code
//

#include "Control_Logic.h"

ControlLogic::ControlLogic(ButtonLibDummy& buttonLib, MotorSensors& motorSensorsLib):
    _pathfinder(buttonLib, motorSensorsLib),
    _fsm(buttonLib, motorSensorsLib, _pathfinder){
};

void ControlLogic::setup() {};

void ControlLogic::loop() {
    _fsm.loop();
};

