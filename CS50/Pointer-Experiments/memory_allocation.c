#include<stdio.h>
#include<stdlib.h>

int main(void) {

	// allocate the interger pointer a random memory...

	// experiment about memory allocation
	int num = 8;
	int *p = &num;
	printf("Address of the memory location pointing at num: %p\n", &p);
	printf("Pointer before malloc(): %p\n", p);

	p = malloc(sizeof(int));

	printf("Address of the memory location pointing at new allocated address: %p\n", &p);
	printf("Pointer after malloc(): %p\n", p);

	free(p);

	return 0;
}