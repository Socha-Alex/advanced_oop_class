//
//  Dice.hpp
//  Part of Object Oriented Prin Prac C++ Dice Class.
//  Created by Nicholas Ferranti and Alexander Socha on 1/21/2021.
#include <iostream>
#include <fstream>
#include <time.h>
#include "tools.hpp"

#pragma once

using namespace std;

class Dice {
  private:
    int nDice;
    int* dArray;

  public:
    Dice(int nDice = 4);
    ~Dice(){delete dArray;}

    const int* roll(); // Gives an array random nDice int's
    void print(ostream& os);
};

// Operator override to allow you to print out dice values
inline ostream& operator <<( ostream& os, Dice& d){
  	d.print(os);
  	return os;
};