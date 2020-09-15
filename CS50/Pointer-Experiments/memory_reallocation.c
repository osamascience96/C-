#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int arr[2];
	arr[0] = 10;
	arr[1] = 20;

	int *ptr = arr;

	printf("Location1: %i\n", ptr[0]);
	printf("Location2: %i\n", ptr[1]);

	// reallocating the memory
	int *new_ptr = realloc(ptr, 3*sizeof(int));

	// The output will be abortd as the memory is allocated on the stack instead on the heap, as it takes the old allocated memory from the heap
	printf("Location1: %i\n", new_ptr[0]);
	printf("Location2: %i\n", new_ptr[1]);
	return 0;
}