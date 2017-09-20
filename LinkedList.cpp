/*
* File:   LinkedList.cpp
* Author: Andrea Silvestro Ortino
* Last modified 21/03/2017
* Implements the LinkedList class.
*/

#include <string>
#include <cassert>
#include <iostream>
#include <sstream>
#include "linked_list.h"
using namespace std;

//creates an empty list
LinkedList::LinkedList()
{

}

//creates a list with an initial value to store
LinkedList::LinkedList(int value)
{
	//Creates a new head Node and puts the value passed inside. Then sets the tail.
	head = new Node;
	head->data = value;
	head->next = nullptr;
	tail = head;
}

//copy constructor (performs a deep copy)
LinkedList::LinkedList(const LinkedList& rhs)
{
	if (rhs.head != nullptr)
	{
		Node *curr = rhs.head;

		//iterates through the list and calls append to copy all the nodes.
		while (curr != nullptr)
		{
			append(curr->data);
			curr = curr->next;
		}
	}
}



//destroys (cleans up) the list
LinkedList::~LinkedList()
{
	if (head)
	{
		Node* current = head;

		//iterates from the head, clearing all the nodes, and setting head/tail to null in the end.
		while (current != nullptr) {
			Node *next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
		tail = nullptr;
		cout << "Destructor called. List cleared.\n" << endl;
	}
}

//adds a value to the head of the list
void LinkedList::push(int value)
{
	Node *node = new Node;
	node->data = value;
	node->next = head;
	head = node;
	
	// moving the head to the next nodes and puts the new nodes as new head.
	while (head->next != nullptr)
	{
		head = head->next;

		if (head->next == nullptr)
			tail = head;
	}
	head = node;
}

//gets the last element from the list, without removing it
//requires: list not empty
int LinkedList::peekTail()
{
	assert(head != nullptr && tail != nullptr);
	int last = 0;
	
	if (head)
	{
		Node *temp = head;
		
		// Uses temp to find the last node, and return the last member.
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		last = temp->data;
		tail = temp;
	}
	return last;
}

//prints the list in order from head to tail
string LinkedList::toString() const
{
	string s = "";
	Node *curr = head;

	// iterates through the nodes, converting the data into string, while adding a space between numbers.
	while (curr != nullptr)
	{
		s += to_string(curr->data);

		if (curr->next == nullptr)
			break;
		else
		{
			s += " ";
			curr = curr->next;
		}
	}
	return s;
}

//removes and returns the value at the head of the list
//requires: list not empty
int LinkedList::pop()
{
	assert(head != nullptr && tail != nullptr);
	int value = 0;
	Node *curr = new Node;

	// if the list is not empty, iterates through the nodes and moves the head to the next nodes, while storing the first value returning it.
	if (head)
	{
		curr = head;
		while (curr != nullptr)
		{
			curr = head;
			value = curr->data;
			head = head->next;

			delete curr;
			return value;
		}
	}
	return value;
}

//adds a value to the end of the list
void LinkedList::append(int value)
{
	// Creates a temp to hold the last node, and set last's data and next.
	Node *last = new Node;
	last->data = value;
	last->next = nullptr;

	// If the linked list is empty then sets head = last
	if (head == nullptr) 
	{
		head = last;
	}
	
	else 
	{
		// Creates a temp node and sets it to head
		Node *temp = head;

		// Uses temp to find the last node
		while (temp->next != nullptr) 
		{
			temp = temp->next;
		}

		// Appends the last node with last
		temp->next = last;
	}
	tail = last;
}

//appends the deep copies of the nodes of rhs on to the end of this list
void LinkedList::appendList(const LinkedList& rhs)
{
	if (rhs.head != nullptr)
	{
		Node *curr = rhs.head;

		// iterates through nodes appeding the rhs' data at the end of the other list. 
		while (curr != nullptr)
		{
			append(curr->data);
			curr = curr->next;
		}
		delete curr;
	}
}

//inserts a value immediately after the first occurrence of afterValue,
//if afterValue is not in the list then inserts at the tail
void LinkedList::insertAfter(int value, int afterValue)
{
	Node* prev = nullptr;
	Node* curr = head;
	Node* newNode = new Node;
	newNode->data = value;

	// iterates through the list and checks if the current data is equal to aftervalue.
	while (curr->next && curr->data != afterValue)
	{
		prev = curr;
		curr = curr->next;
	}
	
	// when the current data is equal to after value, copies it in the prev node and moves forward the next one, creating space to the new nodes with the value passed.
	prev = curr;
	newNode->next = curr->next;
	prev->next = newNode;
	
	while (newNode->next != nullptr)
	{
		newNode = newNode->next;
	}
	tail = newNode;
}

//removes all occurrences of value from the list
void LinkedList::removeAllOccurences(int value)
{
	Node *temp = nullptr;
	Node *prev = nullptr;
	Node *next = nullptr;

	// for loop that moves temp in the next nodes and removes every node that contain data = value.
	for (temp = head; temp != nullptr; temp = next)
	{
		next = temp->next;

		if (temp->data != value) 
		{
			prev = temp;
			continue;
		}

		if (prev != nullptr)
			prev->next = next;
		else
			head = next;

		delete temp;
	}
}

//reverses the list
void LinkedList::reverse()
{
	if (head == nullptr)
		return;

	Node *prev = nullptr;
	Node *curr = head;
	Node *next = nullptr;

	// a loop that interchanges next's node and curr's one, reversing the order. 
	while (curr != nullptr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	// now let the head point at the last node (prev)
	head = prev;
}

//checks if two lists are equal in state (contain the same values in the same order)
bool LinkedList::operator ==(const LinkedList& other) const
{
	Node *curr = head;
	Node *curr2 = other.head;
	
	// iterates through the nodes of the lists, and checks whether the current data is equal or not.
	while (curr != nullptr)
	{
		if (curr->data != curr2->data)
		{
			return false;
		}

		curr = curr->next;
		curr2 = curr2->next;
	}
	return true;
}

//checks if two lists are not equal in state
bool LinkedList::operator !=(const LinkedList& other) const
{
	Node *curr = head;
	Node *curr2 = other.head;
	
	// iterates through the nodes of the lists, and checks whether the current data is equal or not.
	while (curr == nullptr)
	{
		if (curr->data != curr2->data)
		{
			return false;
		}

		curr = curr->next;
		curr2 = curr2->next;
	}
	return true;
}

//pushes a new value onto the head of the list
LinkedList& LinkedList::operator +(int value)
{
	push(value);
	return *this;
}

//copy assignment operator (performs a deep copy)
LinkedList& LinkedList::operator =(const LinkedList& rhs)
{
	// if the lists are the same, returns the list.
	if (this == &rhs)
		return *this;

	Node* start = head;
	Node* tmp = nullptr;

	//deleting the first list.
	while (start != nullptr) 
	{
		tmp = start->next;
		delete start;
		start = tmp;
	}

	head = nullptr;

	if (rhs.head == nullptr)
		return *this;

	if (rhs.head != nullptr)
	{
		Node *curr = rhs.head;

		// iterates through the second list while appending the data to the first list.
		while (curr != nullptr)
		{
			append(curr->data);
			curr = curr->next;
		}
		delete curr;
	}
	return *this;
}

//pushes values from an input stream onto the front of the list
std::istream& operator >> (std::istream &in, LinkedList &value)
{
	int val = 0;

	while (true)
	{ 
		if (in.eof())
		{
			// using pop to handle endl, and avoiding repetition of the last member of the stream.
			value.pop();
			break;
		}

		// passes the stream's values, and pushes in the list.
		in >> val;
		value.push(val);
	}
	return in;
}

//writes the values, in order, to an output stream
std::ostream& operator<<(std::ostream &out, const LinkedList &value)
{
	// transorms the value list into a string and passes it to the outstream.
	out << value.toString();
	return out;
}
