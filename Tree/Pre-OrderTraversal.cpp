// Pre-Order Traversal
#include"pch.h"
#include<iostream>

struct Tree {
	short int data;
	Tree *leftNode;
	Tree *rightNode;

	Tree() {
		data = 0;
		leftNode = nullptr;
		rightNode = nullptr;
	}
};

struct Stack {
	Tree* dataNode;
	Stack* nextNode;

	Stack() {
		dataNode = nullptr;
		nextNode = nullptr;
	}
};

void addNode(short int data);
void PushStackNode(Tree *node);
void TraverseTree(Tree *node);
Stack *PopStackNode();

Tree *rootNode;
Stack *rootStackNode;

// MAIN Function
int main() {
	addNode(2);
	addNode(4);
	addNode(10);
	addNode(6);
	addNode(8);
	addNode(11);
	addNode(1);
	addNode(0);
	TraverseTree(rootNode);
	return 0;
}

// function to add the node to the tree
void addNode(short int data)
{
	// if rootptr is null, then
	if (rootNode == nullptr) {
		rootNode = new Tree();
		rootNode->data = data;
	}
	else
	{
		// if the rootPtr is not null, then 
		Tree *tempNode = rootNode;
		// check each time if the current node is not nullptr
		while (tempNode != nullptr) {
			// if the data to be inserted is greater, then 
			if (data > tempNode->data) {
				// move the pointer to the left side 
				if (tempNode->leftNode == nullptr) {
					tempNode->leftNode = new Tree();
					tempNode->leftNode->data = data;
					// move the pointer to the next left pointer 
					tempNode = tempNode->leftNode;
				}
				else {
					// if the next left pointer is not null, then 
					tempNode = tempNode->leftNode;
				}
			}
			else if (data < tempNode -> data) {
				// move the pointer to the right side 
				if (tempNode->rightNode == nullptr) {
					tempNode->rightNode = new Tree();
					tempNode->rightNode->data = data;
					// move the pointer to the next left pointer 
					tempNode = tempNode->rightNode;
				}
				else {
					// if the next left pointer is not null, then 
					tempNode = tempNode->rightNode;
				}
			}
			else
			{
				tempNode = nullptr;
			}
		}
	}
}

// function to push the node address to stack
void PushStackNode(Tree * node){
	// if the rootStack node is null, then 
	if (rootStackNode == nullptr) {
		rootStackNode = new Stack();
		rootStackNode->dataNode = node;
	}
	else {
		// if the rootstack node is not null, then 
		Stack *tempPushStackNode = new Stack();
		tempPushStackNode->dataNode = node;
		tempPushStackNode->nextNode = rootStackNode;
		// let the rootnode be the new created node 
		rootStackNode = tempPushStackNode;
	}
}

// Traveral through recursive manner
void TraverseTree(Tree *node)
{
	// check if the node is not null, then 
	if (node != nullptr) {
		// check if the node is parent 
		if (node->leftNode != nullptr || node->rightNode != nullptr) {
			std::cout << node->data << " ";
		}
		else {
			// if the node is leaf, then also show its data as well 
			std::cout << node->data << " ";
			// while stack is not empty, then 
			while (rootStackNode != nullptr) {
				TraverseTree(PopStackNode()->dataNode);
			}
		}
		// check that if the parent has the right hand node, then push to stack 
		if (node->rightNode != nullptr) {
			PushStackNode(node->rightNode);
		}
		// check if the parent has the left hand node, then move the pointer to the next left node 
		if (node->leftNode != nullptr) {
			node = node->leftNode;
			TraverseTree(node); // recursive call to Traversal
		}
	}
}

// function to pop the node adress from stack and return the specific stack node 
//*** For Github Readers ***// 
// Do not confuse the Pop function with Peek function 

Stack * PopStackNode()
{
	Stack *PopNode = rootStackNode;
	rootStackNode = rootStackNode->nextNode;
	return PopNode;
}
