//
//  Game.hpp
//  Game Header File
//  Written by Alex Socha and Nick Ferranti on 2/20/2021
//

#include <iostream>
#include <fstream>
#include "Dice.hpp"
#include "enums.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "tools.hpp"
#include "CList.hpp"

#pragma once

using namespace std;

class Game  {
    private:
        Dice *rDice = new Dice();
        Board b;
        
    public:
        Game();
        ~Game(){delete rDice;}

        Player getNewPlayer(CList<Player*> clist);

        void oneTurn(Player* pp);
        // Temporary functions to test the game
        // Dice class object
        int* rollDice();
        // Column class functions
        void startTurn(Player* p){b.startTurn(p);}
        bool move(int colNum){return b.move(colNum);}
        void stop(){b.stop();}
        void bust(int colNum){b.bust(colNum);}

        void printBoard(){cout << b;}
        // Player class functions
        //Player getPlayer(){return players;}
        //void printPlayers(){cout << players;};
};