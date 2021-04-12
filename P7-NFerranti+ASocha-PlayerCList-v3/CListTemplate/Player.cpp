//
//  Player.cpp
//  Part of Object Oriented Prin Prac C++ Player Class.
//  Created by Nicholas Ferranti and Alexander Socha on 2/3/2021.
//
#include "Player.hpp"

Player::Player() : name("Test"), color(Yellow){}

Player::Player(string name, playerColor color) : name(name), color(color){}

// Adds the column a player just captured to the scoreboard,
// will increment the counter and check if it hit 3.
bool 
Player::wonColumn(int colNum){
  	scoreboard[score++] = colNum;
    return (score == 3);
}

// Print Player Details on one line (Color, Name, Scoreboard)
// Using the colors string value from the extern char* in enums.cpp
void 
Player::print(ostream& os){
    // function will now always print (append) the player details to a file
  	ofstream outFile("output.txt", ios_base::app);

  	outFile <<"Player:    " <<name.append(10 - name.length(), ' ') <<" | " 
  	<<pColor[color] << " | Captured: ["<<scoreboard[0] <<"] ["
  	<<scoreboard[1] <<"] [" <<scoreboard[2] << "]\n";

	outFile.close();

	os <<"Player:    " <<name.append(10 - name.length(), ' ') <<" | " 
	<<pColor[color] << " | Captured: [" <<scoreboard[0] <<"] ["
	<<scoreboard[1] <<"] [" <<scoreboard[2] << "]";
}