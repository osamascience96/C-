#include<iostream>

using namespace std;

struct Tree {
	char data;
	Tree *nextLeftPointer;
	Tree *nextRightPointer;

	Tree() {
		data = '0';
		nextLeftPointer = nullptr;
		nextRightPointer = nullptr;
	}
};

void add(char data);

Tree *rootPtr;

int main() {
	add('a');
	add('b');
	add('A');
	return 0;
}

void add(char data) {
	if (rootPtr == nullptr) {
		rootPtr = new Tree();
		rootPtr->data = data;
	}
	else {
		// rule logic for adding the data nodes in tree
		if (data > rootPtr->data && rootPtr->nextLeftPointer == nullptr) {
			Tree *tempPtr = new Tree();
			tempPtr->data = data;
			rootPtr->nextLeftPointer = tempPtr;
		}
		else if (data < rootPtr->data && rootPtr->nextRightPointer == nullptr) {
			Tree *tempPtr = new Tree();
			tempPtr->data = data;
			rootPtr->nextRightPointer = tempPtr;
		}
	}
}
