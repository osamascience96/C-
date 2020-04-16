#include<stdio.h>

typedef char *string;

int main(void) {

	// init the string with the pointer 
	string name = "Osama";
	printf("%p\n", name);

	printf("%p\n", &name[0]);
	printf("%c\n", *(name + 1));
	printf("%c\n", *(name + 2));

	return 0;
}