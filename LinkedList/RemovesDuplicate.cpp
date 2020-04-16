// Worst Code 
#include "pch.h"
#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int d) {
		data = d;
		next = NULL;
	}
};
class Solution {
public:

	vector<Node*> GetDuplicates(Node *head) {
		// Write Code here
		Node *list = head;
		Node *headNode = head;
		vector<Node*> nodeVector;
		while (list != nullptr) {
			int data = headNode->data;
			while (headNode != nullptr) {
				if (headNode->next != nullptr) {
					if (data == (headNode->next)->data) {
						nodeVector.push_back(headNode);
						nodeVector.push_back(headNode->next);
					}
				}
				headNode = headNode->next;
			}
			// code for moving on to the next node 
			list = list->next;
			headNode = list;
		}
		return nodeVector;
	}

	Node* removeDuplicates(Node *head)
	{
		Node *tempNode = nullptr;
		vector<Node*> nodeDuplicates = GetDuplicates(head);

		for (int i = 0; i < nodeDuplicates.size(); i++) {
			if (nodeDuplicates[i] != nullptr) {
				tempNode = nodeDuplicates[i + 1]->next;
				nodeDuplicates[i]->next = tempNode;
				nodeDuplicates[i + 1] = nullptr;
			}
		}

		// check for the duplication again 
		vector<Node*> nodeDuplicates_1 = GetDuplicates(head);

		for (int i = 0; i < nodeDuplicates_1.size(); i++) {
			if (nodeDuplicates_1[i] != nullptr) {
				tempNode = nodeDuplicates_1[i + 1]->next;
				nodeDuplicates_1[i]->next = tempNode;
				nodeDuplicates_1[i + 1] = nullptr;
			}
		}

		if (head->next != nullptr) {
			if (head->data == (head->next)->data) {
				head->next = nullptr;
			}
		}


		return head;
	}

	Node* insert(Node *head, int data)
	{
		Node* p = new Node(data);
		if (head == NULL) {
			head = p;

		}
		else if (head->next == NULL) {
			head->next = p;

		}
		else {
			Node *start = head;
			while (start->next != NULL) {
				start = start->next;
			}
			start->next = p;

		}
		return head;


	}
	void display(Node *head)
	{
		Node *start = head;
		while (start)
		{
			cout << start->data << " ";
			start = start->next;
		}
	}
};

int main()
{
	Node* head = NULL;
	Solution mylist;
	int T, data;
	cin >> T;
	while (T-- > 0) {
		cin >> data;
		head = mylist.insert(head, data);
	}
	head = mylist.removeDuplicates(head);

	mylist.display(head);

}
