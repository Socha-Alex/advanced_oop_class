//
//  Game.cpp
//  Game Class File
//  Written by Alex Socha and Nick Ferranti on 2/20/2021
//
#include "Game.hpp"

// Temporary Game Constructor to add 2 players and 2 columns for testing
Game::Game(){
    /*
    string tmpName = "John";
    playerColor tmpColor = Blue;
    Player p(tmpName, tmpColor);
    
    players.add(&p);

    cout << setw(49) << setfill('-') << " " << endl;*/

    // Print out rolled dice
    cout << "\n\nTesting dice roll:\n";
    rDice->roll();
    cout <<"\n" <<*rDice;
    cout << setw(49) << setfill('-') << " " << endl;
}

// Creates a new player for the game (will need keyboard inputs)
Player
Game::getNewPlayer(CList<Player*> clist){
    string pName;
    char newColor;

    cout <<"Enter New Player Name: \n";
    cin >> pName;

    // Array of strings for the players to pick their color
    string strColors[4] = {"Orange: O", "Yellow: Y", "Green: G", "Blue: B"};

    // Removes colors strings that a player already has.
    for(int k = 0; k<clist.count(); k++){
        if(clist.getData()->getColor() == Orange){
            strColors[0] = "";
        }else if(clist.getData()->getColor() == Yellow){
            strColors[1] = "";
        }else if(clist.getData()->getColor() == Green){
            strColors[2] = "";
        }else if(clist.getData()->getColor() == Blue){
            strColors[3] = "";
        }
        clist.next();
    }
    
    // Prints out only the strings that haven't been removed
    cout <<"\n";
    for(int k=0; k<4; k++){
        if(strColors[k] != ""){
            cout <<strColors[k] <<"\n";
        }
    }
    playerColor colorChoosen;
    while(true){
    	cout << "\nPick a Color (type the character):\n";
    	cin >> newColor;

        switch(newColor){
            case 'O':
                colorChoosen = Orange;
                break;
            case 'Y':
                colorChoosen = Yellow;
                break;
            case 'G':
                colorChoosen = Green;
                break;
            case 'B':
                colorChoosen = Blue;
                break;
            default:
                // Error validation, Makes sure the right values are entered
                cerr << "Invalid Color!\nPlease use the given char after the"
                        <<" color to pick a color.\n";
                continue;
        }
        break;
    }
    return Player(pName, colorChoosen);
}

// One turn for a player
void
Game::oneTurn(Player* pp){
	startTurn(pp);
	int ans=0;
	while(ans!=2){
		cout << "\nChoose an option:\n1.\tRoll\n2.\tStop\n3.\tResign Turn\n";
		cin >> ans;
		switch(ans){
			case 1:
				int* rolledCols;
				int moveOtherCol;
				rolledCols = rollDice();
				// Picked column has to move!
				if(!move(rolledCols[0])){
					bust(rolledCols[0]);
					ans=2;
				}
				// Other column you have a choice to move
				if(b.getNumTowers() < 3){
					if(!move(rolledCols[1])){bust(rolledCols[1]); ans=2;}
				}else if(ans != 2){
                    cout << "\nDo you want to move in the other column? Column: " 
						  << rolledCols[1] << "\n1.\tYes\n2.\tNo\n";
				    cin >> moveOtherCol;
				    if(moveOtherCol == 1)
					   if(!move(rolledCols[1])){bust(rolledCols[1]); ans=2;}
                }
                if(ans == 2){
                	stop();
                	cout << *pp << " \nTurn has ended\n";
                }
				delete [] rolledCols; // use the new operator to create the array
				break;
			case 2:
				stop();
                cout << *pp << " \nTurn has ended\n";
				break;
			case 3:
				cout << "Not coded yet\n";
				break;
			default:
				cout << "Incorrect input please use 1-3.";
				continue;
		}
		cout << b;
	}
}

// Temporary function to roll and print out the dice
int *
Game::rollDice(){
	int diceSlots[4] = {0, 1, 2, 3};
	int firstPair, secondPair;
    const int* dArray = rDice->roll();
    cout <<"\nDice: " << *rDice;
    cout <<"Slot: " <<"[0] [1] [2] [3]\n";
	cout << "Pick 2 slot numbers for the pair of dice\n";
    cin >> firstPair;
	cin >> secondPair;
	cout << "You Picked the Dice: " << dArray[firstPair] 
			<< " " << dArray[secondPair] << "\n";

	int sumPicked = dArray[firstPair] + dArray[secondPair];

	diceSlots[firstPair] = -1;
	diceSlots[secondPair] = -1;

	int sumOther = 0;

	for(int k=0;k<4;k++){
		if(diceSlots[k] != -1){
			sumOther = sumOther + dArray[k]; 
		}
	}

	cout << "Column Picked: " << sumPicked << " | Other Column: "
			<< sumOther << "\n";

	int* returnArray = new int[2];
	returnArray[0] = sumPicked;
	returnArray[1] = sumOther;

	return returnArray;
	// TODO: Fix Segmentation fault after
}