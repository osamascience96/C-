#include<iostream>
// definition to function
void AddNode(int data);
void DeleteNode();
void DeleteAll();
void DisplayNode();
void SearchingNode(int data);
void UniqueData();

// initlizing the counter for the circular display
//static int countNode = 0;
// initlizing the struct
struct Node {
	int data; // data to be stored
	Node* ptr; // reference to the next memory address
	Node() {
		data = 0;
		ptr = nullptr;
	}
};

Node *startNode; // reference to the startNode to global state
int main() {
	AddNode(10);
	AddNode(40);
	DisplayNode();
	return 0;
}

void AddNode(int data) {
	Node *nextNode; // initlize the next node variable that points to null
	// if the startNode is null
	if (startNode == nullptr) {
		// initlizing the pointer to dynamic section (heap) of the memory
		startNode = new Node();
		startNode->data = data; // initlizing the data to the 1st pointer memory address 
	}
	else {
		// if the startnode does not points to null 
		nextNode = startNode; // pointing the nextNode on the same address of the startNode
							  // iterate to node upto null 
		while (nextNode->ptr != nullptr) {
			nextNode = nextNode->ptr; // initlize reference of the nextNode to the reference of the nextptr
		}
		// code for the circular node 
		
		// initlizing the temp node  
		Node *tempNode = new Node();
		tempNode->data = data; // initlized the data to the tempNode
		nextNode->ptr = tempNode; // reference the pointer of the nextNode to the address of tempNode-
	}
	
}

void DeleteNode() {
	Node *delNode;
	delNode = startNode; // initlized the delnode to the reference of the startNode 
						 // reference the startNode to the nextpointer of the startNode 
	startNode = startNode->ptr; // startNode new memory reference 
	delete delNode; // node deallocated from memory
}

void DisplayNode() {
	Node *displayNode;
	displayNode = startNode; // initlize the displaynode to the reference of the startNode
							 // iterate to the displayNode 
	if (displayNode != nullptr) { // if the displaypointer is not null
		while (displayNode != nullptr) {
			std::cout << displayNode->data << " "; // displaying the data
			displayNode = displayNode->ptr; // reference the displaynode to the nextpointer
		} 
		// code for displaying the non circular node 
		/*code for the circular Node connectivity*/

		std::cout << "\n"; // move the cursor to the next line
	}
	else {
		std::cout << "List is Empty" << "\n";
	}
}
void DeleteAll() {
	while (startNode != nullptr) { // iterate until the startNode initlizes to null ptr
		Node *tempNodeptr = startNode;
		startNode = startNode->ptr; // reference the startNode to the nextNode of the startNode
		delete tempNodeptr; // deallocate the startNode 
	}
}
void SearchingNode(int data) {
	Node *searchNode = startNode; // initlizing the searchNode to the reference of the startNode
	int nodeIndex = 0; // init the varibale for node index
	bool nodeTrigger = false; // if the node data matches the requested data, then trigger happens
	if (searchNode != nullptr) { // if the startNode is not null
		while (searchNode != nullptr) { // iterate up to startNode is not equal to nullptr
			if (data == searchNode->data) {
				// if the requested data is matched with the data inside the node, then ...
				std::cout << "The Requested Data is found at Node " << nodeIndex + 1 << ". \n";
				nodeTrigger = true; // trigger the bool 
			}
			// increment to the nodeIndex to 1
			nodeIndex = nodeIndex + 1;
			searchNode = searchNode->ptr; // reference the searchNode to the nextPointer
		}
		if (nodeTrigger != true) {
			// if the node is not triggered, then ...
			std::cout << "The Data was not found in the list \n"; // message to user
		}
	}
	else {
		// if the startNode is null, then, 
		std::cout << "The List is empty" << std::endl;
	}
}
void UniqueData() {
	Node *uniqueNode = startNode; // initlizing the startNode
	while (uniqueNode->ptr != nullptr) { // iterate to last pointer to null
		int tempVar = uniqueNode->data; // initlize the data to the tempVar
		Node *tempNode = uniqueNode; // refernce the memory address to te tempNode
		while (tempNode->ptr != nullptr) { // iterate to the last pointer of the tempNode
			tempNode = tempNode->ptr; // reference of the tempNode to the nextNode in memory address
			if (tempVar == tempNode->data) { // if the data is equal to the tempNode 
											 // deallocate the pointer
			}
		}
	}
}
