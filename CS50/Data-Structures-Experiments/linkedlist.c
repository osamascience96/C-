#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int number;
	struct node *next;
}node;

int main(void) {

	node *list = NULL;

	node *n = malloc(sizeof(node));
	if (n == NULL) {
		return 1;
	}
	n->number = 20;
	n->next = NULL;
	list = n;

	n = malloc(sizeof(node));
	if (n == NULL) {
		return 1;
	}
	n->number = 30;
	n->next = NULL;
	list->next = n;

	n = malloc(sizeof(node));
	if (n == NULL) {
		return 1;
	}
	n->number = 40;
	n->next = NULL;
	list->next->next = n;

	// print list 
	for (node *temp = list; temp != NULL; temp = temp->next) {
		printf("%i\n", temp->number);
	}

	// Free the list
	while (list != NULL) {
		node *temp = list->next;
		free(list);
		list = temp;
	}
	
	return 0;
}