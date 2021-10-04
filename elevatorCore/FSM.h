//
// Created by tegef on 27/08/2019.
// C30 code
//

#ifndef L04_C_30_COMMS_STATE_MACHINE_FSM_H
#define L04_C_30_COMMS_STATE_MACHINE_FSM_H

#include "Arduino.h"
#include "Path_Finder.h"
#include "DummyLibs.h"
#include "MotorSensors.h"


enum states {S0, Sidle, Smoving, Semergency, SdoorOpen, SdoorClose, Sdelay};

/// this is the finite state machine class
/// it handles the state machine, state transitions.
class Fsm{
public:
    /// This is the contructor
    /// \param buttonLib C10 interface class.
    /// \param motorSensors C20 interface class.
    Fsm(ButtonLibDummy& buttonLib, MotorSensors& motorSensors, Pathfinder& pathfinder);

    /// this is the main loop function for the state machine
    /// every time this is called there should be a state transition.
    void loop();
private:



    /// this holds the current state
    states _state;

    /*
     * theses functions are the inputs to the path finder.
     * whey are wrappers for the interface class calls.
     * this way we can call the appropriate input without
     * having any of the interface libraries yet.
     * we can also use it for simulation by having them call
     * a dummy simulation class or something.
     */

    /// \returns true if there is an emergency flag somewhere.
    bool getEmergency();

    /// \returns true if doors open is selected
    bool getDoorsOpenSelected();

    /// \returns true if doors close is selected.
    bool getDoorsCloseSelected();

    /// \returns true if stopped and aligned with floor.
    bool getStoppedAtFloor();

    /// \returns true if stopped at floor 1 or floor 5 when no stop command was given,
    /// use with get closest floor to determine what one.
    bool getStoppedAtEnds();

    /// \returns true if doors are fully open
    bool getDoorsAreOpen();

    /// \returns true if doors are fully closed.
    bool getDoorsAreClosed();

    /// start or restart the delay
    void startDelay(unsigned long delay);

    /// check if delay is finished
    /// \return true if delay finished, false otherwise.
    bool isDelayFinished();


    /*
     * theses are output functions
     */

    /// call to start elevator movement in a direction.
    /// \param direction 0 for down, 1 for up
    void startMovement(unsigned short direction);

    /// call to stop elevator at next floor.
    void stopNextFloor();

    /// call to open the elevator doors. include a check for if the elevator is moving.
    void openDoors();

    ///call to close elevator doors. include a check for if the elevator is moving.
    void closeDoors();

    /// call to move elevator back to ground floor (start position). used for startup?
    void resetToGround();

    /// call to instantly stop elevator and lock breaks (if avaliable).
    void emergencyStop();


    /*
     * these are references to the interface libraries.
     * it keeps the code clean by avoiding globals.
     */

    /// reference to pathfinder class
    Pathfinder& _pathFinder;

    /// reference to interface class for control panel.
    ButtonLibDummy& _buttonLibDummy;

    /// reference to interface class for motor and sensors.
    MotorSensors& _motorSensors;

    ///delay end time in miliseconds
    unsigned long _delay;

};

#endif //L04_C_30_COMMS_STATE_MACHINE_FSM_H
