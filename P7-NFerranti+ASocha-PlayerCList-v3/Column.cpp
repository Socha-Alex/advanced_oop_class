//
//  Column.cpp
//  Column Class File
//  Written by Alex Socha and Nick Ferranti on 2/12/2021
//
#include "Column.hpp"

Column::Column(int colNum) : colNum(colNum){}


// Places a new tower, depending on the current player's marker position
bool 
Column::startTower(Player* p)
{
    // Gets the players color who's turn it is
	color = p->getColor(); 

    // If a tower is placed already in the column move it up one slot
    // Else puts tower in slot 1 if no marker
    // Else puts a tower 1 slot in front of the color marker
	if(colContent[White] != 0)
        move();
    else if(colContent[color] == 0) colContent[White] = 1; 
	else colContent[White] = (colContent[color] + 1);
	
    // Checks to see if the tower is on the last tile
    if(colContent[White] == colLeng[colNum]){
    	ofstream outFile("output.txt", ios_base::app);

    	outFile << "\nTower position: " << colContent[White] << "\nLast Tile: " 
            << colLeng[colNum] << "\n";

		cout << "Tower position: " << colContent[White] << "\nLast Tile: " 
            << colLeng[colNum] << "\n";

        outFile.close();
		state = PENDING;
	}
    
    // Returns true (legal move) if the tower is not in 0
    // And is not greater than colLen[colNum]
	return (colContent[White] != 0 && colContent[White] < colLeng[colNum]);
}

// ---------------------------------------------------------------
// Advances the tower one tile
bool 
Column::move()
{
    // Moves the white tower up one tile
	colContent[White] = colContent[White]+1; 

    // Checks to see if the tower is in the last tile
	if (colContent[White] == colLeng[colNum]){
		state = PENDING;
	}

    // Checks if the tower went over the column length (illegal) or not (legal)
	if (colContent[White] > colLeng[colNum]){
		return false;
	}else{
		return true;
	}
}

// ---------------------------------------------------------------

void 
Column::stop(Player* p)
{
	ofstream outFile("output.txt", ios_base::app);

    color = p->getColor();
    
    // Puts the color marker on the position where the tower is
	colContent[color] = colContent[White];
    
    // Removes the tower from the column
    colContent[White] = 0;

    // If column is captured then call wonColumn function on column
    if(state == PENDING && colContent[color] == colLeng[colNum]){
    	state = CAPTURED;
        p->wonColumn(colNum);
        outFile <<"\nColumn Number: " <<colNum <<" has been " << states[state] 
            <<"! By:\n";
        cout <<"\nColumn Number: " <<colNum <<" has been " << states[state] 
            <<"! By:\n";
    }
    outFile.close();
}

// ---------------------------------------------------------------

void 
Column::bust()
{
    // Temporary bust function to remove tower
    cout << "\nPlayer has busted!\n";
    colContent[White] = 0;
    state = AVAILABLE; // Set column state back to available
    cout << "\nTower has been removed from Column!\n";
    cout << "\nTower state: " << state << endl;
}

// ---------------------------------------------------------------
//Prints that contents of the Column
void 
Column::print(ostream& os)
{
    // Prints to an appended file
    ofstream outFile("output.txt", ios_base::app);

    // Prints Column details in a line (Column Number, Length, and State)
    os << "\nCol: " <<colNum << " | " << "\t" << states[state] << " |  \t";
    outFile << "\nCol: " <<colNum << " | " << "\t" << states[state] << " |  \t";
    
    // Prints the column's contents (towers and markers) in a nice line
    for(int i = 1; i<=colLeng[colNum]; i++){
        if(colContent[0] == i && colContent[0] != 0){
            os << "T";
            outFile << "T";
        } else{
            os << "-";
            outFile << "-";
        }
        if(colContent[1] == i && colContent[1] != 0){
            os << "O";
            outFile << "O";
        } else{
            os << "-";
            outFile << "-";
        }
        if(colContent[2] == i && colContent[2] != 0){
            os << "Y";
            outFile << "Y";
        } else{
            os << "-";
            outFile << "-";
        }
        if(colContent[3] == i && colContent[3] != 0){
            os << "G";
            outFile << "G";
        } else{
            os << "-";
            outFile << "-";
        }
        if(colContent[4] == i && colContent[4] != 0){
            os << "B ";
            outFile << "B ";
        } else{
            os << "- ";
            outFile << "- ";
        }
        if(i == colLeng[colNum]){
            os <<"\n";
            outFile <<"\n";
        }
    }

    outFile.close();
}