#include "pch.h"
#include <iostream>

// Program for Binary Tree

struct Tree {
	int data;
	Tree *leftNode;
	Tree *rightNode;

	Tree() {
		data = 0;
		leftNode = nullptr;
		rightNode = nullptr;
	}
};

Tree *headNode = nullptr;

void AddNode(int);
void DeleteNode(int);
void TraversalTree(int);
int heightOfTree();


int main()
{
    std::cout << "Binary Tree Program!\n";
	bool flag = 0;
	do {

		int choice = 0;
		int data = 0;

		std::cout << "Enter 1, 2, 3 for the following Choice\n";
		std::cout << "1) Insert the data in Tree \n";
		std::cout << "2) Delete the data from Tree\n";
		std::cout << "3) Traversal the data from Tree\n";
		std::cout << "4) Number of Nodes, Ancestor Nodes and Decendentants\n";
		std::cout << "Enter: ";
		std::cin >> choice;


		if (choice == 1) {
			system("cls");
			std::cout << "Enter Data: ";
			std::cin >> data;
			AddNode(data);
		}
		else if (choice == 2) {
			system("cls");
			std::cout << "Enter Data: ";
			std::cin >> data;
			DeleteNode(data);
		}
		else if (choice == 3) {
			system("cls");
			std::cout << "Enter Data to traverse: ";
			std::cin >> data;
			TraversalTree(data);
		}
		else if (choice == 4) {
			// you can use this as global scope as well for other uses
			int nodeCount = heightOfTree() + 1;
			std::cout << "The Number of Nodes in this Tree wrt layers: " <<  std::pow(2, nodeCount) - 1 << std::endl;
		}
		else {
			std::cout << "\t\t Wrong Output\n";
		}

		std::cout << "Enter 1 to Enter Again Or 0 to exit: ";
		std::cin >> flag;
	} while (flag == 1);
}

void AddNode(int data)
{
	if (headNode == nullptr) {
		// add the node the root node 
		headNode = new Tree();
		headNode->data = data;
	}
	else {
		Tree *currentNode = headNode;
		while (currentNode != nullptr) {
			if (data > currentNode->data) {
				// if the data is greater, move to left child node 
				if (currentNode->leftNode != nullptr) {
					currentNode = currentNode->leftNode;
				}
				else {
					currentNode->leftNode = new Tree();
					currentNode->leftNode->data = data;
					currentNode = nullptr;
				}
			}
			else {
				// if the data is smaller, move to right child node
				if (currentNode->rightNode != nullptr) {
					currentNode = currentNode->rightNode;
				}
				else {
					currentNode->rightNode = new Tree();
					currentNode->rightNode->data = data;
					currentNode = nullptr;
				}
			}
		}
	}
}

void DeleteNode(int data)
{
	if (headNode == nullptr) {
		std::cout << "Tree Underflow" << std::endl;
	}
	else {
		Tree *currentNode = headNode;
		while (currentNode != nullptr) {
			if (data == headNode->data){
				headNode = nullptr;
			}
			else if (data > currentNode->data) {
				if (currentNode->leftNode != nullptr) {
					if (currentNode->leftNode->data = data) {
						currentNode->leftNode = nullptr;
						currentNode = nullptr;
					}
					else {
						currentNode = currentNode->leftNode;
					}
				}
				else {
					std::cout << "Data is not found" << std::endl;
				}
			}
			else {
				if (currentNode->rightNode != nullptr) {
					if (currentNode->rightNode->data = data) {
						currentNode->rightNode = nullptr;
						currentNode = nullptr;
					}
					else {
						currentNode = currentNode->rightNode;
					}
				}
				else {
					std::cout << "Data is not found" << std::endl;
				}
			}
		}
	}
}

void TraversalTree(int data)
{
	Tree *currentNode = headNode;

	if (currentNode->data == data) {
		std::cout << currentNode->data << " ";
	}
	else {
		while (currentNode != nullptr) {
			if (data > currentNode->data) {
				if (currentNode->leftNode != nullptr) {
					currentNode = currentNode->leftNode;
					if (currentNode->data = data) {
						std::cout << currentNode->data << " ";
						currentNode = nullptr;
					}
					else {
						std::cout << currentNode->data << " ";
					}
				}
			}
			else {
				currentNode = currentNode->rightNode;
				if (currentNode->data = data) {
					std::cout << currentNode->data << " ";
					currentNode = nullptr;
				}
				else {
					std::cout << currentNode->data << " ";
				}
			}
		}
	}
	std::cout << "\n";
}

int heightOfTree()
{
	int depth = 0;

	Tree* node = headNode;

	while (node->leftNode != nullptr || node->rightNode != nullptr) {
		depth += 1;
		node = node->leftNode;
	}
	return depth;
}
