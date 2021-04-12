//Board Class Header
//Written by Alex Socha and Nick Ferranti

#include <iostream>
#include <fstream>
#include "enums.hpp"
#include "Player.hpp"
#include "Column.hpp"
#include "tools.hpp"

#pragma once

using namespace std;

class Board  {
    private:
        int nTowers=0;
        int towerCol[3] = {0,0,0};
        Column *backBone[13];
        Player* currPlayer;

    public:
        Board();
        ~Board(){delete [] *backBone;}

        void startTurn(Player* p);
        bool move(int colNum);
        void stop();
        void bust(int colNum);

        void print(ostream& os);

        int getNumTowers(){return nTowers;}
};

// Uses the print function when using the << operator
inline ostream& operator <<( ostream& os, Board& b){
  b.print(os);
  return os;
};