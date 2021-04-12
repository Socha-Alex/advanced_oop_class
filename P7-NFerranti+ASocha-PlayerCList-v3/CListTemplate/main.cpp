//
//  main.cpp
//  Part of Object Oriented Prin Prac C++ Game Class.
//  Created by Nicholas Ferranti and Alexander Socha on 2/20/2021.
//  Description: This program tests ability to add objects to the circular linked
//      list class created. This will add 4 players and test the different
//      functions written for the CList.
//
#include "tools.hpp"
#include "Player.hpp"
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

  CList<Player*> players;

  players.add(new Player("Nick", Blue));
  players.add(new Player("Alex", Green));
  players.add(new Player("Jake", Orange));
  players.add(new Player("James", Yellow));

  cout << players << "Has been added to the CList\nList size: "
           << players.count() << "\n";

  players.remove();
  players.remove();
  players.remove();
  players.remove();

  cout << "\nRemoved all players from the list.\nList size: "
          << players.count() << "\n";

  cout << "\nPrinting out an empty list:\n" << players << "\n";
  
  players.add(new Player("Nick", Blue));
  players.add(new Player("Alex", Green));
  players.add(new Player("Jake", Orange));
  players.add(new Player("James", Yellow));

  cout << "\nAdded all players back to the list.\n" << players;
  
  cout << "\nSetting the head player as the current player.\n";
  players.init();

  cout << "\nGetting the next player and printing out data.\n";
  cout << *players.next() << "\n";

  cout << "Next player:\n";
  cout << *players.next() << "\n";

  cout << "Next player:\n";
  cout << *players.next() << "\n";
  
  cout << "Next player:\n";
  cout << *players.next() << "\n";

  cout << "First Player:\n";
  cout << *players.next() << "\n";
 }