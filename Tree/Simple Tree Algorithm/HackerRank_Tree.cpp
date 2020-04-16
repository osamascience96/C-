#include "pch.h"
#include <iostream>
#include <cstddef>

using namespace std;

// Represents one node
class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

class Solution {
public:
	Node* insert(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		}
		else {
			Node* cur;
			if (data <= root->data) {
				cur = insert(root->left, data);
				root->left = cur;
			}
			else {
				cur = insert(root->right, data);
				root->right = cur;
			}

			return root;
		}
	}

	int getHeight(Node* root) {
		//Write your code here
		if (root == nullptr) {
			return  0;
		}

		int left = getHeight(root->left);
		int right = getHeight(root->right);
		cout << left << " " << right << endl;

		return (left > right ? left : right) + 1;
	}

}; //End of Solution

int main() {
	Solution myTree;
	Node* root = NULL;
	int t;
	int data;

	cin >> t;

	while (t-- > 0) {
		cin >> data;
		root = myTree.insert(root, data);
	}
	int height = myTree.getHeight(root) - 1;
	cout << height;

	return 0;
}



