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

struct Queue {
	Node *node;
	Queue *nextQueueNode;

	Queue() {
		node = nullptr;
		nextQueueNode = nullptr;
	}
};

Node *binaryTree = nullptr;
Queue *queueList = nullptr;

void make_binary_tree();
void level_traversal(Node);

void enqueueNode(Node*);
Node* dequeueNode();
bool isQueueEmpty();

void level_traversal(Node*);

int main() {
	make_binary_tree();

	level_traversal(binaryTree);
	return 0;
}

void make_binary_tree() {
	binaryTree = new Node();
	// making the tree hardcodedly 
	binaryTree->data = 1;
	
	binaryTree->leftNode = new Node();
	binaryTree->rightNode = new Node();

	binaryTree->leftNode->data = 2;
	binaryTree->rightNode->data = 3;

	binaryTree->leftNode->leftNode = new Node();
	binaryTree->leftNode->rightNode = new Node();

	binaryTree->leftNode->leftNode->data = 4;
	binaryTree->leftNode->rightNode->data = 5;

	binaryTree->rightNode->leftNode = new Node();
	binaryTree->rightNode->rightNode = new Node();

	binaryTree->rightNode->leftNode->data = 6;
	binaryTree->rightNode->rightNode->data = 7;
}

void enqueueNode(Node* node) {
	if (queueList == nullptr) {
		queueList = new Queue();
		queueList->node = node;
	}
	else {
		Queue *tempQueue = queueList;
		while (tempQueue->nextQueueNode != nullptr) {
			tempQueue = tempQueue->nextQueueNode;
		}

		tempQueue->nextQueueNode = new Queue();
		tempQueue->nextQueueNode->node = node;
	}
}

Node* dequeueNode() {
	Queue *tempQueue = queueList;
	Node *tempNode = tempQueue->node;
	queueList = queueList->nextQueueNode;
	delete(tempQueue);
	return tempNode;
}

bool isQueueEmpty() {
	return queueList != nullptr ? true : false;
}

void level_traversal(Node *root) {
	enqueueNode(root);

	while (isQueueEmpty()) {
		Node *tempNode = dequeueNode();
		std::cout << tempNode->data << " ";

		if (tempNode->leftNode != nullptr) {
			enqueueNode(tempNode->leftNode);
		}

		if (tempNode->rightNode != nullptr) {
			enqueueNode(tempNode->rightNode);
		}

		delete(tempNode);
	}

	delete(queueList);
}
