//
//  main.cpp
//  Part of Object Oriented Prin Prac C++ Game Class.
//  Created by Nicholas Ferranti and Alexander Socha on 2/20/2021.
//  Description: This program tests ability to add objects to the circular linked
//      list class created. This will add 4 players and test the different
//      functions written for the CList.
//
#include "tools.hpp"
#include "CList.hpp"

void unitCList();

int main() {
	srand((unsigned)time(NULL));

  	banner();

  	
  	unitCList();

	bye();
	
	return 0;
}


// Test Plan function using the Circular linked list to add/remove players
void unitCList(){

  CList players;

  players.add(Player("Nick", Blue));
  players.add(Player("Alex", Green));
  players.add(Player("Jake", Orange));
  players.add(Player("James", Yellow));

  cout << players << "Has been added to the CList\nList size: "
           << players.count() << "\n";

  players.remove();
  players.remove();
  players.remove();
  players.remove();

  cout << "\nRemoved all players from the list.\nList size: "
          << players.count() << "\n";

  cout << "\nPrinting out an empty list:\n" << players << "\n";
  
  players.add(Player("Nick", Blue));
  players.add(Player("Alex", Green));
  players.add(Player("Jake", Orange));
  players.add(Player("James", Yellow));

  cout << "\nAdded all players back to the list.\n" << players;

  cout << "\nSetting the head player as the current player.\n";
  players.init();

  cout << "\nGetting the next player and printing out data.\n";
  players.next();
  
  cout << "Next player:\n";
  players.next();

  cout << "Next player:\n";
  players.next();
  
  cout << "Next player:\n";
  players.next();

  cout << "First Player:\n";
  players.next();
 }