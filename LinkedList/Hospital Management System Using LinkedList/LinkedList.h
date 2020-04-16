#pragma once
#include"Node.cpp"

class LinkedList
{
private:
	Node *startNode;
public:
	LinkedList();
	void AddPatient(int, std::string, std::string, short int, std::string, std::string, short int, std::string, 
		std::string);

	std::string GetSearchResult(Node *node);
	Node* DataExists(int patient_id);
	std::string GetEditSearchResults(int, std::string, std::string, short int, std::string, std::string, short int, 
		std::string, std::string, Node*);

	//void SetArrangeNode();


	Node* GetListNode();

};

