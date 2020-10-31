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
Node* FindMaxNode(Node*);
Node* DeleteNode(Node*, int);
Node* FindNode(Node *rootNode, int no_to_find);

int main() {
	InsertNode(4);
	InsertNode(2);
	InsertNode(1);
	InsertNode(8);
	InsertNode(5);
	InsertNode(9);
	InsertNode(7);
	InsertNode(6);

	DeleteNode(binarySearchTree, 8);
	return 0;
}

Node* FindMaxNode(Node *rootNode) {
	Node *tempNode = rootNode;
	while (tempNode->rightNode != nullptr) {
		tempNode = tempNode->rightNode;
	}

	return tempNode;
}

Node* DeleteNode(Node *rootNode, int data) {
	if (rootNode == nullptr) {
		return nullptr;
	}
	else if(data < rootNode->data) {
		// if the data is shorter than that of the root data
		rootNode->leftNode = DeleteNode(rootNode->leftNode, data);
	}
	else if (data > rootNode->data) {
		// if the data is greater than that of the root data
		rootNode->rightNode = DeleteNode(rootNode->rightNode, data);
	}
	else {
		Node *tempNode = nullptr;
		if (rootNode->leftNode != nullptr && rootNode->rightNode != nullptr) {
			// Case1: if the node to be deleted has a non linear branch on its denendants
			/*The Code of case 1 is a non-practical solution, the practical solution is mentioned in the tree notes, that is simple and standard to implement.*/
			Node *maxNode = FindMaxNode(rootNode->leftNode);
			rootNode->data = maxNode->data;
			tempNode = rootNode->leftNode;
			Node *prevNode = tempNode;

			while (tempNode->rightNode != nullptr) {
				prevNode = tempNode;
				tempNode = tempNode->rightNode;
			}

			prevNode->rightNode = DeleteNode(tempNode, maxNode->data);
			
			// release memory
			prevNode = nullptr;
			maxNode = nullptr;
			delete(prevNode);
			delete(maxNode);

		}else if ((rootNode->leftNode != nullptr && rootNode->rightNode == nullptr) || (rootNode->leftNode == nullptr && rootNode->rightNode != nullptr)) {
			// Case2: if the node to be deleted has a linear branch on its desendants
			if (rootNode->leftNode == nullptr) {
				rootNode = rootNode->rightNode;
			}
			else if (rootNode->rightNode == nullptr) {
				rootNode = rootNode->leftNode;
			}
		} else if (rootNode->leftNode == nullptr && rootNode->rightNode == nullptr) {
			// Case3: if the node to be deleted is a leaf
			delete(rootNode);
			rootNode = nullptr;
		}
	}
	// return the root Node
	return rootNode;
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
