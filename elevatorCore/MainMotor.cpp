/*
 * Motor Control Code
 * By Rushan Baral
 * Edited by Jonah Skinner
 *
 * Motor control based on the position of the servo.
 *
 * FSM needs to give serial input on which floor to goto.
 *
 * Then the lift will move to each level the FSM tells it to goto.
 */
#include "MainMotor.h"

/*
 * pos Stores the position (angle) of the servo. Range is [0, 360].
 * levelHeight is assuming total rotation to be the top of any floor 360/5=72.
 */
MainMotor::MainMotor() {
    pos = 0;
    baseHeight=0;
    maxHeight=360;
    levelHeight = 72;
    floor = 1;
}
// ATTACH the servo on pin 9 to the servo object IN THE MASTER .INO FILE
void MainMotor::setup() {
    //Serial.begin(9600);
    //servo.attach(9);
}

/*
 * Takes Input Serial value from FSM
 *
 * case i: moves the lift to floor position_i
 * Floor is determined on rotation of the motor
 *
 * Returns delay(50) if there is no serial input and between stops.
 */
void MainMotor::loop() {
    if (true) {
        //int floor = Serial.read();
        switch(floor) {
            case 1:
                if (pos > levelHeight){
                    while (pos > levelHeight){
                        pos -= 1;
                        servo.write(pos);
                    }
                } else {
                    servo.write(baseHeight);
                }
                break;
            case 2:
                if (pos > levelHeight * 2){
                    while (pos > levelHeight * 2){
                        pos -=1;
                        servo.write(pos);
                    }
                } else {
                    while (pos < levelHeight * 2 ){
                        pos += 1;
                        servo.write(pos);
                    }
                }
                break;
            case 3:
                if (pos > levelHeight * 3){
                    while (pos > levelHeight * 3){
                        pos -= 1;
                        servo.write(pos);
                    }
                } else {
                    while (pos < levelHeight * 3){
                        pos += 1;
                        servo.write(pos);
                    }
                }
                break;
            case 4:
                if(pos > levelHeight * 4){
                    while(pos > levelHeight * 4){
                        pos -= 1;
                        servo.write(pos);
                    }
                } else {
                    while (pos < levelHeight * 4){
                        pos += 1;
                        servo.write(pos);
                    }
                }
                break;
            case 5:
                if(pos > levelHeight * 5){
                    servo.write(maxHeight);
                } else {
                    while (pos < levelHeight * 5){
                        pos += 1;
                        servo.write(pos);
                    }
                }
                break;
        }
    }
    delay(50);
}


void MainMotor::setFloor(int floorNumber) {
    floor = floorNumber
}