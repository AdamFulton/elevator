//
// Created by Faulkes on 7/09/2019.
// C30 code
// this file is for all things shared throughout the code. E.G. the debug print function.
// this will also include all of the Defines like enabling doors ect ect.
//

#ifndef FSMTEST_GLOBALS_H
#define FSMTEST_GLOBALS_H


#define DOORS_ENABLED false
#define DEBUG_ENABLED true

/// prints a message to the serial interface.
/// \param message in the form of "Hello world!".
void debugPrint(char message[]);

#endif //FSMTEST_GLOBALS_H
