cmake_minimum_required (VERSION 2.6)
project (Elevator)
set(CMAKE_CXX_STANDARD 14)


add_executable(Elevator elevatorCore/elevatorCore.ino elevatorCore/FSM.cpp elevatorCore/Path_Finder.cpp elevatorCore/Control_Logic.cpp elevatorCore/Globals.cpp elevatorCore/MotorSensors.cpp elevatorCore/MainMotor.cpp)