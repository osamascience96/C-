// Main Class Code 
#include "pch.h"
#include "LinkedList.h"

int main()
{
	LinkedList *linkedList = new LinkedList();
	linkedList->Add(54);
	linkedList->Add(22);
	linkedList->Add(12);
	linkedList->Add(52);
	linkedList->Add(62);
	linkedList->Display();
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// header files code 
// ********************

// Node header
#pragma once
class Node
{
private:
	int data;
	Node *ptr;
public:
	Node();
	void SetNode(int data);
	void SetPointer(Node *ptr);
	Node *GetPointer();
	int GetData();
};
// LinkedList Header
#pragma once
#include "Node.h"
#include<iostream>

class LinkedList
{
private:
	Node *startNode;
public:
	LinkedList();
	void Add(int data);
	void Display();
};
// +++++++++++++++++++++++++++++++++++++++++++++++++++++
// classes code 
// *************************************
// Node Class Code
#include "pch.h"
#include "Node.h"


Node::Node()
{
	data = 0;
	ptr = nullptr;
}


void Node::SetNode(int data)
{
	this->data = data;
}

void Node::SetPointer(Node * ptr)
{
	this->ptr = ptr;
}

Node * Node::GetPointer()
{
	return ptr;
}

int Node::GetData()
{
	return data;
}
// LinkedList Class Code
#include "pch.h"
#include "LinkedList.h"


LinkedList::LinkedList()
{
}


void LinkedList::Add(int data)
{
	if (startNode == nullptr) {
		// init the startPointer 
		startNode = new Node();
		startNode->SetNode(data);
	}
	else {
		Node *nextNode = startNode; // init the startNode to the nextNode 
		while (nextNode->GetPointer() != nullptr)
		{
			// move the pointer to the nextNode 
			nextNode = nextNode->GetPointer();
		}
		Node *tempNode = new Node();
		tempNode->SetNode(data);
		nextNode->SetPointer(tempNode);
	}
}

void LinkedList::Display()
{
	Node *displayNode = startNode; // init the node inside the fuction to the address of the startNode

	while (displayNode != nullptr) {
		std::cout << displayNode->GetData() << std::endl;
		displayNode = displayNode->GetPointer();
	}
}
