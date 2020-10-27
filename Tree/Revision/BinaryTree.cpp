#include <iostream>

struct Node {
	int data;
	struct Node *leftNode;
	struct Node *rightNode;

	Node(int data) {
		this->data = data;
		leftNode = nullptr;
		rightNode = nullptr;
	}
};

Node *startNode = nullptr;

void addNode(int);
void pre_order(Node*);

int main() {
	addNode(10);
	addNode(11);
	addNode(15);
	addNode(12);
	addNode(9);
	addNode(7);

	// traversing in pre order manner
	pre_order(startNode);
	return 0;
}

// adding the node in the binary tree based on the number comparison
void addNode(int data) {
	if (startNode == nullptr) {
		startNode = new Node(data);
	}
	else {
		Node *tempNode = startNode;
		while (tempNode->leftNode != nullptr && data > tempNode->data) {
			tempNode = tempNode->leftNode;
		}

		while (tempNode->rightNode != nullptr && data < tempNode->data) {
			tempNode = tempNode->rightNode;
		}

		if (data > tempNode->data) {
			tempNode->leftNode = new Node(data);
		}
		else if(data < tempNode->data) {
			tempNode->rightNode = new Node(data);
		}
	}
}

void pre_order(Node *root) {
	if (root != nullptr) {
		// accessing the root node data
		std::cout << root->data << " ";
		// recursive to the left of the node 
		pre_order(root->leftNode);
		// recursive to the right of the node
		pre_order(root->rightNode);
	}
}
