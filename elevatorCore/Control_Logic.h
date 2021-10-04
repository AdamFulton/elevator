//
// Created by Faulkes on 2/09/2019.
// C30 code
//

#ifndef ELEVATOR_CONTROL_LOGIC_H
#define ELEVATOR_CONTROL_LOGIC_H

#include "DummyLibs.h"
#include "FSM.h"
#include "Path_Finder.h"
#include "MotorSensors.h"

class ControlLogic{
public:
    /// Constructor for the ControlLogic mmodule.
    /// \param buttonLib interface class for control panel
    /// \param motorSensorsLib interface class for motor and sensors.
    ControlLogic(ButtonLibDummy& buttonLib, MotorSensors& motorSensorsLib);

    /// this gets run in the arduino setup function
    /// add any code that needs to be run once here.
    void setup();

    /// this gets run in the arduino loop function
    /// add any code that needs to be looped here.
    void loop();

private:
    /// this contains the pathfinder class
    Pathfinder _pathfinder;

    /// this contains the Finite state machine class.
    Fsm _fsm;
};

#endif //ELEVATOR_CONTROL_LOGIC_H
