//
//  Player.hpp
//  Part of Object Oriented Prin Prac C++ Player Class.
//  Created by Nicholas Ferranti and Alexander Socha on 2/3/2021.
//
#include <iostream>
#include <fstream>
#include "enums.hpp"

#pragma once

using namespace std;

class Player {
  private:
    string name;
    playerColor color;
    int score = 0;
    int scoreboard[3] = {0,0,0};

  public:
    Player();
    Player(string pName, playerColor color);
    ~Player() = default;
    playerColor getColor(){return color;}
    bool wonColumn(int colNum); // Checks if the player has 3 columns
    void print(ostream& os); // Print Player Details
};

// Uses the print function when using the << operator
inline ostream& operator <<( ostream& os, Player& p){
  p.print(os);
  return os;
};