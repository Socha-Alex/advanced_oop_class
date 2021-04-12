//
//  CList.hpp
//  Part of Object Oriented Prin Prac C++ Player Class.
//  Created by Nicholas Ferranti and Alexander Socha on 3/20/2021.
//

#ifndef CList_hpp
#define CList_hpp

#include <iostream>

using namespace std;

template<class T>class CList;

template<class T>
class Node{
	friend class CList<T>;

    private:
        T data;
        Node<T>* next;

    public:
        Node() {
            this->next = NULL; 
        }
        ~Node() = default;
        T getData(){return data;}
        Node<T> *getNext(){return next;}

        friend ostream &operator<<( ostream &out, const Node<T> &n)
        {
        	out << n.data;
        	return out;
        }
};

template<class T>class CList{
private:
	Node<T>* head; 
	Node<T>* currentPos;
	int length = 0;

public:
	CList(): currentPos{nullptr}, head{nullptr}, length{0} {}
	~CList();

	int count(){return length;}
	bool empty(){if(length>0) return false; else return true;}
	void add(T item);
	void init();
	T next();
	void remove();
	void remove(T item);

	T getData(){return head->getData();}

	template< class TT>
	friend ostream &operator<< (ostream& out, const CList<TT> &cl)
	{
		Node<TT> *temp = cl.head;
		int i = 0;
		while(i<cl.length)
		{
			out << *temp->getData() << endl;
			temp = temp->getNext();
			i++;
		}
		cout << endl;
		return out;
	}
};

template<class T>
CList<T>::~CList(){
	Node<T>* temp = nullptr; 
	while(head != nullptr){
		temp = head;
		delete head;
		head = temp->next;
		delete temp;  
	}
	length = 0; 
}

template<class T>
void CList<T>::add(T item){
	Node<T>* temp = new Node<T>[1];
	temp->data = item; 
	if(head == nullptr){
		head = temp;
		head->next = temp;
		cout << "Added node to the first head\n";
		length++;
		return;
	}

	Node<T>* tempHead = head;
	while(tempHead->next != head){
		tempHead = tempHead->next;
	}
	tempHead->next = temp;
	temp->next = head; 
	length++;
	cout << "Added node to the next open slot\n";
}

template<class T>
void CList<T>::init(){
	if(head == nullptr)
		throw "Circular Linked List is empty!"; 
	currentPos = head;
}

template<class T>
T CList<T>::next(){
	if(currentPos->next == nullptr)
		throw "Out of range"; 

	T data = currentPos->data;
	currentPos = currentPos->next;
	return data; 
}


template<class T>
void CList<T>::remove(){
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

template<class T>
void CList<T>::remove(T item){
	// Empty case 
	if(head == nullptr){
		cout << "List is empty\n";
		return;
	}

	currentPos = head->next;
	// Deleting head
	if(head->data == item){
		if(length == 1){
			free(head);
			head = nullptr;
			currentPos = nullptr;
			length--;
			cout << "\nRemoved the final object from the list\n";
		}else{
			delete head;
			head = currentPos;
			length--; 
			cout << "\nRemoved the head object from the list but there are more objects in the list\n";
		}
		return;
	}

	// Deleting further in the list
	currentPos = head; 
	while(currentPos->next != nullptr){
		if(currentPos->next->data == item){
			Node<T>* temp = currentPos->next; 
			currentPos->next = currentPos->next->next; 
			delete temp; 
			length--;
			cout << "\nRemoved an object in the middle of the list\n";
			return; 
		}
		currentPos = currentPos->next;
	}
}

#endif /* CList_hpp */