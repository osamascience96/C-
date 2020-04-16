#include "pch.h"
#include <iostream>

// declare the add function to add the node to binary tree
void addNode(int data);
bool findNode(int searchData);

// binary tree for 2byte short integer
struct BinaryTree {
	// 3 member variables 
	short int data;
	BinaryTree *leftPointer;
	BinaryTree *rightPointer;

	// init the members of the construct 
	BinaryTree() {
		data = 0;
		leftPointer = nullptr;
		rightPointer = nullptr;
	}
};

// declare the root pointer 
BinaryTree *rootBinaryPointer;

int main() {
	addNode(21);
	addNode(15);
	addNode(26);
	addNode(10);
	addNode(20);

	if (findNode(22) == true) {
		// Node found 
		std::cout << "Node Found Successfully" << std::endl;
	}
	else {
		// Node not found 
		std::cout << "Node doesen't exist in tree" << std::endl;
	}
	return 0;
}

void addNode(int data)
{
	if (rootBinaryPointer == nullptr) {
		// adding the data to the root where the root is leaf on the 1st call of the function 
		rootBinaryPointer = new BinaryTree();
		rootBinaryPointer->data = data;
	}
	else {
		BinaryTree *tempNode = rootBinaryPointer;
		while (tempNode != nullptr) {
			// check if the data to be inserted is greater, then move the pointer to the right 
			if (data > tempNode->data) {
				// check if the right pointer is null
				if (tempNode->rightPointer == nullptr) {
					// make the right node pointer 
					BinaryTree *rightPointer = new BinaryTree();
					rightPointer->data = data;
					tempNode->rightPointer = rightPointer;
					// move (reference) the tempNode to the right of the current node 
					tempNode = tempNode->rightPointer;
				}
				else {
					tempNode = tempNode->rightPointer;
				}
			}else if (data < tempNode->data) {
				// check if the leftpointer to be inserted nullptr
				if (tempNode->leftPointer == nullptr) {
					// if the data to be inserted is smaller, then move the pointer to the left 
					BinaryTree *leftPointer = new BinaryTree();
					leftPointer->data = data;
					tempNode->leftPointer = leftPointer;
					// move (reference) the tempNode to the leftPointer of the current node
					tempNode = tempNode->leftPointer;
				}
				else {
					tempNode = tempNode->leftPointer;
				}
			}
			else{
				// let the tempNode be nullptr
				tempNode = nullptr;
			}
		}
	}
}

bool findNode(int searchData)
{
	bool foundFlag = false;
	BinaryTree *tempNode = rootBinaryPointer;
	while (tempNode!=nullptr)
	{
		// if the data is equal to the node, then 
		if (searchData == tempNode->data) {
			foundFlag = true;
			tempNode = nullptr;
		}else if (searchData < tempNode->data) {
			// if the data to be searched is smaller, then move the pointer to left
			tempNode = tempNode->leftPointer;
		}
		else {
			// if not smaller, then move the pointer to right
			tempNode = tempNode->rightPointer;
		}
	}
	return foundFlag;
}


