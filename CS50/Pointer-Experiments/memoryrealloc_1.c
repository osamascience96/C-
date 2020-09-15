#include<stdio.h>
#include<stdlib.h>

int main(void) {
	int *x = malloc(2 * sizeof(int));

	// init 16 bits to pointer to integer
	x[0] = 10;
	x[1] = 20;

	printf("Location1: %i\n", x[0]);
	printf("Location2: %i\n", x[1]);

	// print the address in pointer to x 
	printf("Address in x pointer: %p\n", x);

	// reallocating the memory 
	int *new_x = realloc(x, 3 * sizeof(int));

	// print the address in pointer to new_x
	printf("Address in new_x pointer: %p\n", new_x);

	printf("Location1: %i\n", new_x[0]);
	printf("Location2: %i\n", new_x[1]);

	// add another data to 3rd index
	new_x[2] = 30;
	printf("Location3: %i\n", new_x[2]);

	free(new_x);

	return 0;
}