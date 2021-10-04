/*
 * Created by Jonah Skinner 09/09/2019
 */

#ifndef MainMotor_H
#define MainMotor_H
#include <Servo.h>

/*
 * README
 *
 * Motor control based on the position of the servo.
 *
 * FSM needs to give serial input on which floor to goto.
 *
 * Then the lift will move to each level the FSM tells it to goto.
 */

class MainMotor {
  Servo servo;

  public:
    MainMotor();
    //how do you create a method which the FSM can use to input their serial?

    void setup();

    void loop();

   private:
     int pos;
     int levelHeight;

};
#endif
