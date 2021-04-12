//Board Class File
//Written by Alex Socha and Nick Ferranti

#include "Board.hpp"

Board::Board(){
	// Creates columns for the board
	for(int k = 0; k<13; k++){
		backBone[k] = new Column(k);
	}
}

// ---------------------------------------------------------------
// Gets a player ready for their turn
void 
Board::startTurn(Player* p){
	currPlayer = p;
	nTowers = 0;
	for(int k=0; k<3; k++)
		towerCol[k] = 0;

	cout << *currPlayer;
}

// ---------------------------------------------------------------
// Moves a tower down the column (only works for 1 tower as of now)
bool 
Board::move(int colNum){
	int k;
	for(k = 0; k < nTowers; k++){
		if(towerCol[k] == colNum){
			cout << "Column: " << colNum << " has been started by the player already!\n";
			cout << "It was their " << k << " column they started on this turn\n";
			break;
		}
	}

	if(backBone[colNum]->getState() == PENDING || 
		backBone[colNum]->getState() == CAPTURED){
		return false;
	}else {
		if(k == nTowers){
			backBone[colNum]->startTower(currPlayer);
			towerCol[nTowers] = colNum;
			nTowers++;
			if(nTowers > 3) return false;
		}else backBone[colNum]->move();
		cout << *backBone[colNum];
		return true;
	}
}

// ---------------------------------------------------------------
// Stops a players turn and puts down markers if towers were placed
void
Board::stop(){
	if(nTowers != 0){
		for(int k=0; k<nTowers; k++){
			if(towerCol[k] != 0){
				backBone[towerCol[k]]->stop(currPlayer);
			}
		}
	}else{
		cout << "No towers were placed!\n";
	}
}

// ---------------------------------------------------------------
// Removes all towers on the board and ends players turn
void
Board::bust(int colNum){
	for(int k=0;k<nTowers; k++){
		towerCol[k] = 0;
	}
	nTowers = 0;
	currPlayer = nullptr;
	backBone[colNum]->bust();
	cout << "You have busted, it is no longer your turn!\n";

}


// ---------------------------------------------------------------
// Print the Board for the game
void 
Board::print(ostream& os){
    // appends the boards details to a file
  	//ofstream outFile("output.txt", ios_base::app);

  	for(int k = 2; k<13; k++){
		os << *backBone[k];
		//outFile << *backBone[k];
	}

	//outFile.close();
}