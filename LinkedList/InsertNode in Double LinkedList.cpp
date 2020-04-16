#include"pch.h"
#include<iostream>

void Add(int data);
void Display();
void InsertNode(int data, int index);

struct Node {
	int data; // holds the data
	Node *prevNode; // holds the memory address of the previous Node
	Node *nextNode; // holds the memory address of the next node 

	Node() { // ctor 
			 // initlization of the member variables 
		data = 0;
		prevNode = nullptr;
		nextNode = nullptr;
	}
};
Node *startNode; // Init the startNode 
Node *lastAddressOfNode; // storing the last address of the node being initlized in the add function 
int main() {

	Add(44);
	Add(55);
	Add(90);
	Add(190);
	Add(80);
	Add(901);
	Display();
	std::cout << "--------------------------" << std::endl;
	InsertNode(69, 2); // ;)
	Display();

	// Call any Search type function and debug. Code here ....
	return 0;
}

void Add(int data) {
	if (startNode == nullptr) { // if the startNode is null, then ...
		startNode = new Node();
		startNode->data = data; // init the data in startNode 
	}
	else
	{
		// if the startNode is not null 
		Node *nextNode = startNode; // making another node that shares the same memory with startNode.
									// moving the nextNode to th nextpointer to make the list of the nodes 
		while (nextNode->nextNode != nullptr)
		{
			nextNode = nextNode->nextNode; // memory reference of the nextNode points to the nextNode nextpointer points to nextnode
		}
		// This piece of code will initlize another memory address to link it to the nextNode 
		Node *tempNode = new Node();
		tempNode->data = data; // init the data
		nextNode->nextNode = tempNode; // the pointer of the nextNode points to tempNode in memory 
		tempNode->prevNode = nextNode; // the previous pointer of the tempNode points to previous node.
		lastAddressOfNode = tempNode; // for storing the reference of the lastNode made
	}
}

void Display()
{
	Node *displayNode = startNode; // referencing the memory to the address of the displayNode 
	while (displayNode != nullptr) { //while the display Node reaches to null
		std::cout << displayNode->data << " "; // displaying the data stored in the memory block
		displayNode = displayNode->nextNode; // referencing the node to the nextPointer reference of the memory
	}
	std::cout << "\n";
}

void InsertNode(int data, int index) {
	Node* sampleNode = startNode;

	// iterate node  to the index-1
	for (int i = 0; i < index; i++) {
		sampleNode = sampleNode->nextNode;
	}

	//creating a new node to be inserted
	Node* newNode = new Node();
	newNode->data = data;
	newNode->nextNode = sampleNode; // set the newnode nextpointer to the indexed pointer 
	newNode->prevNode = sampleNode->prevNode; // set the newnode previouspoiter to the indexed previous pointer

	// update the link between the indexedNode and indexedNode-1
	sampleNode->prevNode->nextNode = newNode;
	sampleNode->prevNode = newNode;
}
