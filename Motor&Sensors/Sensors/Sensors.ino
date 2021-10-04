
/*
 * Sensor Interpreter
 * By Thomas Cowan
 * Edited by Jonah Skinner
 * 
 * README 
 * 
 * accelerometer() returns a float of the current acceleration of the carriage
 * 
 * loadCell() returns a float of the current weight of the carriage
 * 
 * closestLevels() returns a pointer that points to 2 values, *(p+0) is the closest level above, *(p+1) is the closest level below
 * 
 * levelHeadingTo(int ascending) returns an int to indicate the floor the elevator is currently heading to
 * 
 */
#include <stdio.h>
#include "HX711.h"
#include <Adafruit_MMA8451.h>
#include <Adafruit_Sensor.h>
//Beam breaker sensors

const int BBS1 = 26;
const int BBS2 = 27;
const int BBS3 = 28;
const int BBS4 = 29;
const int emgTop = 30;

//Variables to test where sensor is within shaft
int inBBS1 = 0;
int inBBS2 = 0;
int inBBS3 = 0;
int inBBS4 = 0;

//Pins for the load sensor and create an object for the load cell
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;
HX711 scale;

//weight of the elevator
double carriageWeight;

//Accelerometer object
Adafruit_MMA8451 mma = Adafruit_MMA8451();

void setup() {
  Serial.begin(9600);
  //Load Cell Setup
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(1); // THIS WILL NEED TO BE CHANGED TO CONVERT THE UNITS INTO KG.
  scale.tare(carriageWeight);  
  //Accelerometer Setup
  if(!mma.begin()){
    Serial.println("Accelerometer couldn't start");
    while(1);
  }
  mma.setRange(MMA8451_RANGE_2_G);
  //Assigns beam breakers to pins
  pinMode(BBS1,INPUT);
  pinMode(BBS2,INPUT);
  pinMode(BBS3,INPUT);
  pinMode(BBS4,INPUT);
  pinMode(emgTop,INPUT); 
}

void loop() {
  //emergency stop
  if(digitalRead(emgTop)==HIGH){
    //put in code to stop motor
  }
  loadCell();
}

float accelerometer(){
  mma.read();
  sensors_event_t event; 
  mma.getEvent(&event);
  return event.acceleration.y;
    //put code for emergency stop
}

float loadCell(){
  return(scale.get_units());
}
/* Returns a pointer to an int array containing the nearest floor above and below. Can access data by using following code

  int p = closestLevels();
  levelAbove = *(p+0);
  levelbelow = *(p+1); 

*/

int * closestLevels(){
  int* p = (int*) malloc(2*sizeof(int));
  p[0] = levelHeadingTo(1);
  p[1] = levelHeadingTo(0);
  return p;
}

// param: "ascending" determines whether the elevator is ascending(1) or descending(0); can be 0, 1;
int levelHeadingTo(int ascending){
  if(ascending == 1){
    if(digitalRead(BBS1)==HIGH){
      inBBS1 = 1;
      return 2;
    } else if(digitalRead(BBS2)==HIGH){
      inBBS1 = 0;
      inBBS2 = 1;
      return 3;
    } else if(digitalRead(BBS3)==HIGH){
      inBBS2 = 0;
      inBBS3 = 1;
      return 4;
    } else if(digitalRead(BBS4)==HIGH){
      inBBS3 = 0;
      inBBS4 = 1;
      return 5;
    } 
    if(inBBS1 == 1){
      return 3;
    } else if (inBBS2 == 1){
      return 4;
    } else if (inBBS3 == 1){
      return 5;
    } 
    return 5;
  }else if (ascending == 0){
    if(digitalRead(BBS4)==HIGH){
      inBBS4 = 1;
      return 4;
    } else if(digitalRead(BBS3)==HIGH){
      inBBS4 = 0;
      inBBS3 = 1;
      return 3;
    } else if(digitalRead(BBS2)==HIGH){
      inBBS3 = 0;
      inBBS2 = 1;
      return 2;
    } else if(digitalRead(BBS1)==HIGH){
      inBBS2 = 0;
      inBBS1 = 1;
      return 1;
    } 
    if(inBBS2 == 1){
      return 1;
    } else if (inBBS3 == 1){
      return 2;
    } else if (inBBS4 == 1){
      return 3;
    } 
    return 1;
  } else Serial.println("Incorrect parameter; can be 1 (ascending) or 0 (descending)");
}
