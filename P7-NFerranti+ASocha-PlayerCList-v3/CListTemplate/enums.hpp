//
//  Enums.hpp
//  Part of Object Oriented Prin Prac C++ Player Class.
//  Created by Nicholas Ferranti and Alexander Socha on 2/3/2021.
//
#pragma once
// Enum for the players colors
enum playerColor {White, Orange, Yellow, Green, Blue};
//enum markerColor {While, Orange, Yellow, Green, Blue};
//Enum of Column State
enum colState {AVAILABLE, PENDING, CAPTURED};

// External string array for the colors values
extern const char* pColor[];
extern const char* mColor[];
extern const char* states[];