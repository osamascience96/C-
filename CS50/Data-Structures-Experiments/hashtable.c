#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	char* name;
	struct node *nextNode;
}node;

int HashFunction(int ascii);
void InsertData(char* name);

node *hashTable = NULL;

int main(void) {
	// 10 contigous memory allocations(back to back) in memory
	hashTable = calloc(10, sizeof(node));
	if (hashTable == NULL) {
		return 0;
	}

	InsertData("Osama");

}

int HashFunction(int ascii) {
	return ascii % 10;
}

void InsertData(char* name) {
	// check the index for the name
	int index = HashFunction(name[0]);
	if (hashTable[index] == NULL) {
		hashTable[index].name = name;
		hashTable[index].nextNode = NULL;
	}
	else {
		//handle the collision
		node *tempNode = hashTable->nextNode;
		while (tempNode != null) {
			tempNode = hashTable->nextNode;
		}
		tempNode = malloc(sizeof(node));
		node *temp = tempNode;
		if (temp != NULL) {
			temp->name = name;
			temp->nextNode = NULL;
		}
	}
}