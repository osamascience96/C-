#include<stdio.h>

typedef char *string;

int main(void) {

	string i = "a";
	string j = "b";

	scanf("%s", &i);
	scanf("%s", &j);

	if (i == j) {
		printf("Same\n");
	}
	else {
		printf("Different\n");
	}

	return 0;
}