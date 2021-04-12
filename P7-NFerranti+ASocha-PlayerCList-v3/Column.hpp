//
//  Column.cpp
//  Column Class Header
//  Written by Alex Socha and Nick Ferranti on 2/12/2021
//
#include <iostream>
#include <fstream>
#include "Player.hpp"
#include "tools.hpp"

#pragma once

using namespace std;

class Column  {
    private:
        const int colLeng[13] = {0, 1, 3, 5, 7, 9, 11, 13, 11, 9, 7, 5, 3};
        int colNum;
        colState state = AVAILABLE;
        playerColor color;
        
        // 0 = nothing in the column, Max # is according
        // to the length above means it is captures
        int colContent[5] = {0, 0, 0, 0, 0}; 
        // White, Orange, Yellow, Green, Blue (marker order)

    public:
        Column(){colNum = 0;}
        Column(int colNum);
        ~Column() = default;

        colState getState(){return state;}

        bool startTower(Player* p);
        bool move();
        void stop(Player* p);
        void bust();
        void print(ostream& os);
};

// Uses the print function when using the << operator
inline ostream& operator <<( ostream& os, Column& c){
  c.print(os);
  return os;
};