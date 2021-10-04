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
#include <Servo.h>
 
Servo servo;
 
int pos = 0;  // Stores the position (angle) of the servo. Range is [0, 360].
int levelHeight = 72; //assuming total rotation to be the top of any floor 360/5=72.
void setup() { 
  Serial.begin(9600);
  servo.attach(9);  // Attaches the servo on pin 9 to the servo object.
}
 
void loop() {
  if (Serial.available()) {  // Returns true if there is serial input.
    int floor = Serial.read(); // reads the input value enterd in Serial monitor
    switch(floor) {
      case 1: //moves the lift to floor position_1
         if(pos >levelHeight){ 
            while(pos >levelHeight){
              pos -=1;
              servo.write(pos);
            }
          }
          else{
              servo.write(pos);
            }
      break;
      //moves the lift to floor position_2
      case 2: 
         if(pos >levelHeight*2){
            while(pos >levelHeight*2){
              pos -=1;
              servo.write(pos);
            }
          }
          else{
            while(pos<levelHeight*2 ){
              pos +=1;
              servo.write(pos);
            }
          }
      break;
      //moves the lift to floor position_3
      case 3: 
         if(pos >levelHeight*3){
            while(pos >levelHeight*3){
              pos -=1;
              servo.write(pos);
            }
          }
          else{
            while(pos<levelHeight*3){
              pos +=1;
              servo.write(pos);
            }
          }
      break;
      //moves the lift to floor position_4
      case 4: 
         if(pos >levelHeight*4){
            while(pos >levelHeight*4){
              pos -=1;
              servo.write(pos);
            }
          }
          else{
            while(pos<levelHeight*4){
              pos +=1;
              servo.write(pos);
            }
          }
      break;
      //moves the lift to floor position_5
      case 5: 
         if(pos >levelHeight*5){
              servo.write(360);
         } else {
            while(pos<levelHeight*5){
              pos +=1;
              servo.write(pos);
           }
         }
      break;
    }
  }
  delay(50);
}
