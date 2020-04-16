// Post-Order Traversal
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
	char nodeType;
	Tree *dataReference;
	Stack *nextPointer;

	Stack() {
		nodeType = '0';
		dataReference = nullptr;
		nextPointer = nullptr;
	}

};

void addNode(short int data);
void PushToStack(char, Tree *node);
void TraverseTree();
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
	TraverseTree();
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
			else if (data < tempNode->data) {
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
void PushToStack(char nodetype, Tree * refer)
{
	// if the rootpointer is null, then 
	if (rootStackNode == nullptr) {
		rootStackNode = new Stack();
		rootStackNode->nodeType = nodetype;
		rootStackNode->dataReference = refer;
	}
	else {
		Stack *tempNode = new Stack();
		tempNode->nodeType = nodetype;
		tempNode->dataReference = refer;
		tempNode->nextPointer = rootStackNode;
		rootStackNode = tempNode;
	}
}


void TraverseTree()
{
	Tree * currentNode = rootNode;
	do
	{
		// if the currentnode is parent, then 
		if (currentNode->leftNode != nullptr || currentNode->rightNode != nullptr) {
			// if the stack is empty, then 
			if (rootStackNode == nullptr) {
				// check if the currentnode has the right node 
				if (currentNode->rightNode != nullptr) {
					PushToStack('P', currentNode);
					PushToStack('R', currentNode->rightNode);
				}
				else
				{
					PushToStack('P', currentNode);
				}
				if (currentNode->leftNode != nullptr) {
					currentNode = currentNode->leftNode;
				}
			}
			else
			{
				// peeking to check that if the current node exists as parent in the stack 
				if ((currentNode == rootStackNode->dataReference) && (rootStackNode->nodeType == 'P')) {
					std::cout << PopStackNode()->dataReference->data << " ";
					if (rootStackNode != nullptr) {
						// peeking to the stack of the next reference
						currentNode = rootStackNode->dataReference;
					}
				}
				else
				{
					// if the currentNode does not exists in the stack, then 
					if (currentNode != rootStackNode->dataReference) {
						// check if the currentnode has the right node 
						if (currentNode->rightNode != nullptr) {
							PushToStack('P', currentNode);
							PushToStack('R', currentNode->rightNode);
						}
						else
						{
							PushToStack('P', currentNode);
						}
						// if the leftnode exists than move
						if (currentNode->leftNode != nullptr) {
							currentNode = currentNode->leftNode;
						}
					}
					else {
						if ((currentNode == rootStackNode->dataReference) && (rootStackNode->nodeType == 'R')) {
							// check if the node in the stack is parent 
							if ((rootStackNode->dataReference->leftNode != nullptr) || (rootStackNode->dataReference->rightNode != nullptr)) {
								rootStackNode->nodeType = 'P';
								if (currentNode->rightNode != nullptr) {
									// push to stack as a right child reference address
									PushToStack('R', rootStackNode->dataReference->rightNode);
								}
								// if the left reference of the currentnode does not exists
								if (currentNode->leftNode != nullptr) {
									currentNode = currentNode->leftNode;
								}
								else
								{
									currentNode = currentNode->rightNode;
								}
							}
						}
					}
				}
			}
		}
		else {
			std::cout << currentNode->data << " ";
			if ((rootStackNode->dataReference->leftNode != nullptr) || (rootStackNode->dataReference->rightNode != nullptr)) {
				currentNode = rootStackNode->dataReference;
			}
			else {
				if (currentNode != rootStackNode->dataReference) {
					currentNode = PopStackNode()->dataReference;
				}
				else
				{
					PopStackNode();
					currentNode = rootStackNode->dataReference; // reference the currentnode to the next value in Stack by peeks
				}
			}
		}
	} while (rootStackNode != nullptr);
}

// function to pop the node adress from stack and return the specific stack node 
//*** For Github Readers ***// 
// Do not confuse the Pop function with Peek function 

Stack * PopStackNode()
{
	Stack *tempStack = rootStackNode;
	rootStackNode = rootStackNode->nextPointer;
	return tempStack;
}
