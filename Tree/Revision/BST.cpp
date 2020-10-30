// binary search tree program and operations 


#include <iostream>

struct Node {
	int data;
	struct Node *leftNode;
	struct Node *rightNode;

	Node() {
		data = 0;
		leftNode = nullptr;
		rightNode = nullptr;
	}
};

Node *binarySearchTree = nullptr;

void InsertNode(int data);
Node* FindNode(Node *rootNode, int no_to_find);

int main() {
	// sampling the Node addition 
	binarySearchTree = new Node();
	binarySearchTree->data = 25;
	binarySearchTree->leftNode = new Node();
	binarySearchTree->leftNode->data = 15;
	binarySearchTree->rightNode = new Node();
	binarySearchTree->rightNode->data = 35;
	binarySearchTree->leftNode->leftNode = new Node();
	binarySearchTree->leftNode->leftNode->data = 5;
	binarySearchTree->leftNode->rightNode = new Node();
	binarySearchTree->leftNode->rightNode->data = 16;
	binarySearchTree->rightNode->leftNode = new Node();
	binarySearchTree->rightNode->leftNode->data = 30;
	binarySearchTree->rightNode->rightNode = new Node();
	binarySearchTree->rightNode->rightNode->data = 45;

	InsertNode(3);
	return 0;
}

void InsertNode(int data) {
	if (binarySearchTree == nullptr) {
		binarySearchTree = new Node();
		binarySearchTree->data = data;
	}
	else {
		Node *tempNode = binarySearchTree;

		while (tempNode->leftNode != nullptr || tempNode->rightNode != nullptr) {
			if (data < tempNode->data) {
				// check if the left node is not null
				if (tempNode->leftNode != nullptr) {
					tempNode = tempNode->leftNode;
				}
				else {
					break;
				}
			}
			else if(data > tempNode->data) {
				// check if the right node is not node
				if (tempNode->rightNode != nullptr) {
					tempNode = tempNode->rightNode;
				}
				else {
					break;
				}
			}
		}

		if (data < tempNode->data) {
			tempNode->leftNode = new Node();
			tempNode->leftNode->data = data;
		}
		else if (data > tempNode->data) {
			tempNode->rightNode = new Node();
			tempNode->rightNode->data = data;
		}
	}
}

// function that finds the Node using the BST rules of finding node in a binary tree
Node* FindNode(Node *rootNode, int no_to_find) {
	if (rootNode != nullptr) {
		if (rootNode->data == no_to_find) {
			return rootNode;
		}
		else {
			return no_to_find < rootNode->data ? FindNode(rootNode->leftNode, no_to_find) : FindNode(rootNode->rightNode, no_to_find);
		}
	}

	return rootNode;
}
