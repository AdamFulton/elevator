//
// Created by tegef on 27/08/2019.
// C30 code
//

#ifndef L04_C_30_COMMS_STATE_MACHINE_PATH_FINDER_H
#define L04_C_30_COMMS_STATE_MACHINE_PATH_FINDER_H

#include "Arduino.h"
#include "DummyLibs.h"
#include "MotorSensors.h"


/**
 * this is the pathfinder class, just a container for the functions.
 */
class Pathfinder{
public:
    /// constructor for pathfinder
    /// \param buttonLib interface class for control panel
    /// \param controlLib interface class for motor and sensors.
    Pathfinder(ButtonLibDummy& buttonLib, MotorSensors& motorSensors);

    /// returns the next floor to go to.
    /// \return returns the floor number of the next destination
    int getDestination();

    /// returns the direction of travel
    /// \return either 0, 1, 2 for idle, up down, or use an enumeration.
    int getDirection();

    /// detarmines if the next floor should be stopped at.
    /// \return returns true if should stop. false otherwise.
    bool getStopNext();

    /// get the closest floor number
    int  getClosestFloor();


private:
    /*
     * theses functions are the inputs to the path finder.
     * whey are wrappers for the interface class calls.
     * this way we can call the appropriate input without
     * having any of the interface libraries yet.
     * we can also use it for simulation by having them call
     * a dummy simulation class or something.
     */
    /// get if the first floor is selected.
    bool getFirstFloorSelected();

    /// get if the Second floor is selected.
    bool getSecondFloorSelected();

    /// get if the Third floor is selected.
    bool getThirdFloorSelected();

    /// get if the fourth floor is selected.
    bool getFourthFloorSelected();

    /// get if the Fifth floor is selected.
    bool getFifthFloorSelected();

    ///
    int  getnextFloor();

    /*
     * these are references to the interface libraries.
     * it keeps the code clean by avoiding globals.
     */

    /// interface class for control panel.
    ButtonLibDummy& _buttonLib;

    /// interface class for motor and sensors.
    MotorSensors& _motorSensors;
};


#endif //L04_C_30_COMMS_STATE_MACHINE_PATH_FINDER_H
