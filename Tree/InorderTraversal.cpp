// In-Order Traversal
#include"pch.h"
#include<iostream>

using namespace std;

struct Tree {
	double data;
	Tree *nextLeftPointer;
	Tree *nextRightPointer;

	Tree() {
		data = 0;
		nextLeftPointer = nullptr;
		nextRightPointer = nullptr;
	}
};

struct ParentNode {
	Tree *referenceNode;
	ParentNode *nextPtr;

	ParentNode() {
		referenceNode = nullptr;
		nextPtr = nullptr;
	}
};

bool flag = false;

void add(double data);
void addParentToStack(Tree *parentAddress);
Tree* PopStack();
void InorderTraversal();

Tree *rootPtr;
ParentNode *rootParentNode;

int main() {
	add(2.0);
	add(3.0);
	add(1.0);
	add(1.5);
	add(0.5);
	add(4.0);
	add(2.5);
	add(5.0);
	add(3.5);
	add(2.8);
	add(2.4);
	InorderTraversal();
	return 0;
}

void add(double data) {
	if (rootPtr == nullptr) {
		// let define the 1st data at the root
		rootPtr = new Tree();
		rootPtr->data = data;
	}
	else {
		// let a tempnode be equal to the root node
		Tree *tempNode = rootPtr;
		// check iteratively, that if tempnode is not nullptr, then
		while (tempNode != nullptr) {
			// check if the data to be inserted is greater, then
			if (data > tempNode->data) {
				// reference the tempNode to the left pointer
				if (tempNode->nextLeftPointer == nullptr) {
					Tree *leftNode = new Tree();
					leftNode->data = data;
					tempNode->nextLeftPointer = leftNode;
					// move the pointer to the nextleftpointer (to the next level)
					tempNode = tempNode->nextLeftPointer;
				}
				else {
					// move the pointer to the nextleftpointer (to the next level)
					tempNode = tempNode->nextLeftPointer;
				}
			}
			else if (data < tempNode->data) {
				// else, reference the tempNode to the right pointer
				if (tempNode->nextRightPointer == nullptr) {
					Tree *rightNode = new Tree();
					rightNode->data = data;
					tempNode->nextRightPointer = rightNode;
					// move the pointer to the nextrightpointer (to the next level)
					tempNode = tempNode->nextRightPointer;
				}
				else {
					// move the pointer to the nextrightpointer (to the next level)
					tempNode = tempNode->nextRightPointer;
				}
			}
			else {
				// let the tempnode be null,
				tempNode = nullptr;
			}
		}
	}
}


void addParentToStack(Tree *parentAddress) {
	if (rootParentNode == nullptr) {
		rootParentNode = new ParentNode();
		rootParentNode->referenceNode = parentAddress;
	}
	else {
		ParentNode *tempParentNode = new ParentNode();
		tempParentNode->referenceNode = parentAddress;
		tempParentNode->nextPtr = rootParentNode; // reference the nextpointer to the 1st node as stack structure
		// let the rootpointer be the newely created node
		rootParentNode = tempParentNode;
	}
}


void InorderTraversal() {
	Tree *displayTree = rootPtr;
	do
	{
		// loop shall be running until the stack becomes nullptr,
		while (displayTree->nextLeftPointer != nullptr || displayTree->nextRightPointer != nullptr) {
			// if any of the child node of the parent node are not null, 
			// then it would be consider as a parent node and it's address 
			// would be pushed into the stack  
			addParentToStack(displayTree);
			// moving the pointer with top priority of the left node movement
			if (displayTree->nextLeftPointer != nullptr) {
				displayTree = displayTree->nextLeftPointer;
			}
			else {
				displayTree = displayTree->nextRightPointer;
			}
		}
		std::cout << displayTree->data << " ";
		displayTree = PopStack();
		if (rootParentNode != nullptr) {
			std::cout << "P-->" << displayTree->data << " ";
			displayTree = displayTree->nextRightPointer;
		}
	} while (rootParentNode != nullptr);

	std::cout << "\n";

}

Tree * PopStack()
{
	// reference to the current node of the stack 
	ParentNode *currentParentNode = rootParentNode;
	// reference the rootnode to the nextnode 
	if (currentParentNode->nextPtr == nullptr && flag == false) {
		flag = true;
	}
	else {
		rootParentNode = rootParentNode->nextPtr;
	}
	return currentParentNode->referenceNode;
}


