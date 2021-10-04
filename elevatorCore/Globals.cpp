//
// Created by Faulkes on 7/09/2019.
// C30 code
//

#include "Globals.h"
#include <Arduino.h>

void debugPrint(char message[]){
    if(DEBUG_ENABLED){
        Serial.println(message);
    }
}
