#include "pch.h"
#include <iostream>
struct Tree {
	double data;
	Tree *nextLeftPointer;
	Tree *nextRightPointer;

	Tree() {
		data = 0.0;
		nextLeftPointer = nullptr;
		nextRightPointer = nullptr;
	}
};

void add(double data);
void GetNodeCountAtLevel(int lvl);
void GetNodeCoutOfTree(int lvl);
int getHeight(Node *node);



Tree *rootPtr;
int levelCount = 0;

int main() {
	add(2.0);
	add(3.0);
	add(1.0);
	add(4.0);
	return 0;
}



void add(double data) {
	if (rootPtr == nullptr) {
		// let define the 1st data at the root
		rootPtr = new Tree();
		rootPtr->data = data;
		levelCount += 1;
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
					// if the rightNode of the current pointer is empty, then increment levelCount
					if (tempNode->nextRightPointer == nullptr) {
						levelCount += 1;
					}
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
					// if the leftpointer of the current pointer is empty, then increment the levelCount 
					if (tempNode->nextLeftPointer == nullptr) {
						levelCount += 1;
					}
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

void GetNodeCountAtLevel(int lvl)
{
	if (lvl > levelCount) {
		std::cout << "Level Not Available" << std::endl;
	}
	else
	{
		std::cout << pow(2, lvl - 1) << std::endl;
	}
}

void GetNodeCoutOfTree(int lvl)
{
	if (lvl > levelCount) {
		std::cout << "Nodes cannot be counted of the level not created" << std::endl;
	}
	else
	{
		std::cout << pow(2, lvl) - 1;
	}
}

// Not an efficient code
// Objective: to find the path of maximum edges to leaf. Reference HackerRank
int getHeight(Node* root) {
		//Write your code here
		if (root == nullptr) {
			return  -1;
		}

		int left = getHeight(root->left);
		int right = getHeight(root->right);
		cout << left << " " << right << endl;

		return (left > right ? left : right) + 1;
}


