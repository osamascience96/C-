#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int *list = malloc(3 * sizeof(int));
	if (list == NULL) {
		return 1;
	}

	list[0] = 1;
	list[1] = 2;
	list[2] = 3;

	int *temp = malloc(4 * sizeof(int));
	if (temp == NULL) {
		return 1;
	}

	// copy the integers from an old array into the new array
	for (int i = 0; i < 3; i++) {
		temp[i] = list[i];
	}

	temp[3] = 4;

	// free the memory from the list pointer
	free(list);

	list = temp;

	for (int i = 0; i < 4; i++) {
		printf("%i\n", list[i]);
	}

	free(list);
}