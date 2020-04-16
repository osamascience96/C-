/* 
This code contains 2 important functions of delete that deallocate the memory in terms of Stack (Delete_2) and
deallocate the memory in terms of queue (Delete)
This Code also contains 2 searchtype function.
   1) StackSearch search according to the stack algorithm LIFO
   2) QueueSearch search according to the queue algorithm FIFO
*/
#include<iostream>
void Add(int data);
void Delete();
void Delete_2();
void Display();
void SearchStack(int data);
void SearchQueue(int data);
struct Node {
	int data; // holds the data
	Node *prevNode; // holds the memory address of the previous Node
	Node *nextNode; // holds the memory address of the next node 

	Node() { // ctor 
			 // initlization of the member variables 
		data = 0;
		prevNode = nullptr;
		nextNode = nullptr;
	}
};
Node *startNode; // Init the startNode 
Node *lastAddressOfNode; // storing the last address of the node being initlized in the add function 
int main() {
	Add(44);
	Add(55);
	Add(90);
	Add(190);
	Add(80);
	Add(901);
	Add(101);
	Add(69); // ;)
	Display();
	Delete();
	Display();
	Delete_2();
	Display();
	// Call any Search type function and debug. Code here ....
	return 0;
}

void Add(int data) {
	if (startNode == nullptr) { // if the startNode is null, then ...
		startNode = new Node();
		startNode->data = data; // init the data in startNode 
	}
	else
	{
		// if the startNode is not null 
		Node *nextNode = startNode; // making another node that shares the same memory with startNode.
									// moving the nextNode to th nextpointer to make the list of the nodes 
		while (nextNode->nextNode != nullptr)
		{
			nextNode = nextNode->nextNode; // memory reference of the nextNode points to the nextNode nextpointer points to nextnode
		}
		// This piece of code will initlize another memory address to link it to the nextNode 
		Node *tempNode = new Node();
		tempNode->data = data; // init the data
		nextNode->nextNode = tempNode; // the pointer of the nextNode points to tempNode in memory 
		tempNode->prevNode = nextNode; // the previous pointer of the tempNode points to previous node.
		lastAddressOfNode = tempNode; // for storing the reference of the lastNode made
	}
}
void Delete()
{
	Node *delNode;
	delNode = startNode; // reference the rootNode to the delNode
	startNode = startNode->nextNode; // init the rootNode to the address of the nextNode 
	startNode->prevNode = nullptr; // null to the previous pointer to unidentified address
	delete delNode; // deallocating the memory address from the delNode
}
void Delete_2()
{
	// deleting the node from right to left 
	Node *delNode; // init the delNode pointer 
	delNode = lastAddressOfNode; // referene the delNode to the lastNode 
	lastAddressOfNode = lastAddressOfNode->prevNode; // reference the node to the previous Node 
	lastAddressOfNode->nextNode = nullptr; // init the nullptr to the nextNode that points to some other unidentified address
	delete delNode; // deallocating the memory address 
}
void Display()
{
	Node *displayNode = startNode; // referencing the memory to the address of the displayNode 
	while (displayNode != nullptr) { //while the display Node reaches to null
		std::cout << displayNode->data << " "; // displaying the data stored in the memory block
		displayNode = displayNode->nextNode; // referencing the node to the nextPointer reference of the memory
	}
	std::cout << "\n";
}

void SearchStack(int data)
{
	/*This function is responsible to search the data in terms of stack rules in this list*/
	Node *searchNode = lastAddressOfNode;
	while (searchNode!=nullptr){
		if (searchNode->data == data) { // if the data is matched, ... 
			std::cout << "Data found in the list successfully" << std::endl;
			break;
		}
		searchNode = searchNode->prevNode; // reference the searchNode to the previous Node in the memory 
	}
}

void SearchQueue(int data)
{
	Node *searchNode = startNode;
	while (searchNode!=nullptr){
		if (searchNode->data = data) {
			std::cout << "Data found in the list Successfully" << std::endl;
			break;
		}
		searchNode = searchNode->nextNode;
	}
}
