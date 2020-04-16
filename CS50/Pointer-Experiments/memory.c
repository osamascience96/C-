#include<stdlib.h>

void f(void) {
	// init the 40 bytes
	int *x = malloc(10 * sizeof(int));
	x[6] = 20;
	free(x);
}

int main(void) {
	f();
	return 0;
}