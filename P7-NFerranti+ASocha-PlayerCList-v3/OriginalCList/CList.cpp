#include "CList.hpp"

CList::~CList(){
	Node* temp = nullptr; 
	while(head != nullptr){
		temp = head;
		head = head->next;
		delete temp;  
	}
	length = 0; 
}

void CList::add(Player item){
	Node* temp = new Node;
	temp->data = item; 
	if(head == nullptr){
		head = temp;
		head->next = temp;
		cout << "Added node to the first head\n";
		length++;
		return;
	}

	Node* tempHead = head;
	while(tempHead->next != head){
		tempHead = tempHead->next;
	}
	tempHead->next = temp;
	temp->next = head; 
	length++;
	cout << "Added node to the next open slot\n";
}

void CList::init(){
	if(head == nullptr)
		throw "Circular Linked List is empty!"; 
	currentPos = head;
}

Player CList::next(){
	if(currentPos->next == nullptr)
		throw "Out of range"; 

	Player data = currentPos->data;
	cout << data << "\n";
	currentPos = currentPos->next;
	return data; 
}

void CList::remove(){
	if(head == nullptr){
		cout << "List is empty\n";
		return;
	}

	if(count() == 1){
		head = nullptr;
		currentPos = nullptr;
		length--;
		cout << "Last item removed from List\n";
		return;
	}

	currentPos = head;
	while(currentPos->next!=head)
		currentPos=currentPos->next;

	currentPos->next = head->next;
	free(head);
	head = currentPos->next;
	cout << "Removed an item from the list\n";
	length--;
}