//
//  Dice.cpp
//  Part of Object Oriented Prin Prac C++ Dice Class.
//  Created by Nicholas Ferranti and Alexander Socha on 1/21/2021.
#include "Dice.hpp"

Dice::Dice(int nDice) : nDice(nDice), dArray( new int[nDice]){}

// Gives a random int from 1-6 to an array with nDice slots
const 
int* Dice::roll(){
  for(int k=0; k < nDice; k++){
    dArray[k] = rand() % 6 + 1;
  }
  return dArray;
}

void 
Dice::print(ostream& os){
  // function will now always print (append) the dice values to a file
  ofstream outFile("output.txt", ios_base::app);

  string diceString = ""; // used to create a simple one line output for the dice

  for(int k=0; k < nDice; k++){
    diceString = diceString + "[" + to_string(dArray[k]) + "] "; // Simple one line print
  }

  os << diceString << "\n";
  outFile << diceString << "\n";
  outFile.close();
}