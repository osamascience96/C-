#include "pch.h"
#include<iostream>

void add(char data);
void display();

struct Tree {
	char data;
	Tree *nextLeftPtr;
	Tree *nextRightPtr;

	// ctor all var to 0
	Tree() {
		data = '0';
		nextLeftPtr = nullptr;
		nextRightPtr = nullptr;
	}
};

Tree *rootPtr;

int main() {
	add('a');
	add('b');
	add('c');
	display();
	return 0;
}

void add(char data) {
	if (rootPtr == nullptr) {
		// if the root pointer is null, then 
		Tree *tempNode = new Tree();
		tempNode->data = data;
		rootPtr = tempNode;
	}
	else {
		// if the root pointer is not null, then 
		Tree *tempptr = rootPtr;

		// if the left pointer is null, then  
		if (tempptr->nextLeftPtr == nullptr) {
			Tree *nextPointer = new Tree();
			nextPointer->data = data;
			tempptr->nextLeftPtr = nextPointer;
		}
		else if (tempptr->nextRightPtr == nullptr) {
			// if the right pointer is null, then 
			Tree *nextPointer = new Tree();
			nextPointer->data = data;
			tempptr->nextRightPtr = nextPointer;
		}
	}
}

void display() {
	Tree *displayNode = rootPtr;

	// display the root node
	std::cout << "  " << displayNode->data << std::endl;
	// display the next left node
	displayNode = displayNode->nextLeftPtr;
	std::cout << displayNode->data << "    ";
	// display the next right node
	displayNode = rootPtr;
	displayNode = displayNode->nextRightPtr;
	std::cout << displayNode->data << std::endl;
}
