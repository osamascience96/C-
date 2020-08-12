#include<stdio.h>
#include<stdlib.h>

//define the bool type in c
typedef enum {false, true} bool;

typedef struct node {
	int number;
	struct node *leftPointer;
	struct node *rightPointer;
}node;


node *Tree;

short int Insert(node* tree, int number);
bool search(node *tree, int number);
// Make a function that frees the memory by using any traversal

int main(void) {

	// init the first memory location
	Tree = malloc(sizeof(node));

	Insert(Tree, 4);
	Insert(Tree, 1);
	Insert(Tree, 2);
	Insert(Tree, 3);
	Insert(Tree, 5);
	Insert(Tree, 6);
	Insert(Tree, 7);

	if (search(Tree, 8) == true) {
		printf("The number exists in tree\n");
	}
	else {
		printf("The number does not exists in tree\n");
	}

	return 0;
}

short int Insert(node* tree, int number) {
	// if the tree is 0,(explicit case)
	if (tree->number == 0) {
		tree->number = number;
		tree->leftPointer = NULL;
		tree->rightPointer = NULL;
		return 0;
	}
	else { 
		// if the number to be inserted is smaller, 
		if (number < tree->number) {
			if (tree->leftPointer == NULL) {
				tree->leftPointer = malloc(sizeof(node));
			}
			return Insert(tree->leftPointer, number);
		}
		else {
			// go right to insertion,
			if (tree->rightPointer == NULL) {
				tree->rightPointer = malloc(sizeof(node));
			}
			return Insert(tree->rightPointer, number);
		}
	}
}

bool search(node *tree, int number) {
	// explicit case if the tree is null, then 
	if (tree == NULL) {
		return false;
	}
	else if(number < tree->number) {
		return search(tree->leftPointer, number);
	}
	else if (number > tree->number) {
		return search(tree->rightPointer, number);
	}
	else {
		return true;
	}
}