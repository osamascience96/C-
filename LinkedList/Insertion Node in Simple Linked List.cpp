// double linked list program
#include "pch.h"
#include<iostream>

void AddNode(int data);
void InsertNode(int data, int index);
void Display();

struct Node {
	int data;
	Node *nextPtr;

	Node() {
		data = 0;
		nextPtr = nullptr;
	}
};

// globally initlize
Node *rootNode;

int main() {

	AddNode(22);
	AddNode(12);
	AddNode(52);
	AddNode(29);

	Display();

	std::cout << "============================" << std::endl;

	InsertNode(33, 2);

	Display();

	return 0;
}

void AddNode(int data) {
	if (rootNode == nullptr) {
		rootNode = new Node();
		rootNode->data = data;
	}
	else
	{
		Node *nextNode = rootNode;

		// move node to the next reference 
		while (nextNode->nextPtr != nullptr) {
			nextNode = nextNode->nextPtr;
		}

		Node *tempNode = new Node();
		tempNode->data = data;
		nextNode->nextPtr = tempNode;
	}
}

void InsertNode(int data, int index)
{
	Node *nextNode = rootNode;
	// init the new node 
	Node *newNode = new Node();
	newNode->data = data;

	Node *tempNode = nullptr;
	for (int i = 0; i < index; i++) {
		tempNode = nextNode;
		nextNode = nextNode->nextPtr;
	}

	// replace the address of the nextpointer in the inserted pointer 
	newNode->nextPtr = nextNode;

	// pointer of the previous pointer to the newNode 
	tempNode->nextPtr = newNode;
}

void Display() {
	Node *displayNode = rootNode;

	while (displayNode != nullptr) {
		std::cout << displayNode->data << std::endl;
		displayNode = displayNode->nextPtr;
	}
}
