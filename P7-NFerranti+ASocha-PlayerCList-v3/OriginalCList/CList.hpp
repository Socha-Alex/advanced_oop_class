//
//  CList.hpp
//  Part of Object Oriented Prin Prac C++ Player Class.
//  Created by Nicholas Ferranti and Alexander Socha on 3/20/2021.
//

#ifndef CList_hpp
#define CList_hpp

#include <iostream>
#include "Node.hpp"

using namespace std;

class CList{
private:
	Node* head; 
	Node* currentPos;
	int length = 0;

public:
	CList(): currentPos{nullptr}, head{nullptr}, length{0} {}
	~CList();

	int count(){return length;}
	bool empty(){if(length>0) return false; else return true;}
	void add(Player item);
	void init();
	Player next();
	void remove();

	Player getData(){return currentPos->data;}

	friend ostream &operator<< (ostream& out, const CList &cl)
	{
		Node *temp = cl.head;
		int i = 0;
		while(i<cl.length)
		{
			out << temp->data << endl;
			temp = temp->next;
			i++;
		}
		cout << endl;
		return out;
	}
};

#endif /* CList_hpp */