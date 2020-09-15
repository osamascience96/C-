#include<stdio.h>
#include<stdlib.h>

int main(void) {

	// calloc function take 2 arguments:
	// 5 memory blocks of size 4 bytes(Total = 20 bytes)
	// all memory blocks are inits to 0
	int *arr = calloc(5, sizeof(int));

	// read the data of 0, being allocated by the calloc
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("Location %i: %i\n", i+1, arr[i]);
	}

	// simple count program
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		arr[i] = i + 1;
	}

	// read the data again
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("Location %i: %i\n", i + 1, arr[i]);
	}

	// freeing the memory created
	free(arr);
	return 0;
}