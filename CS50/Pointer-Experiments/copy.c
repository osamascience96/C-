#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(void) {

	char s[] = "osama";
	int size = sizeof(s) / sizeof(*s);

	char *t = malloc(size + 1);
	
	for (int i = 0; i <= size; i++) {
		t[i] = s[i];
	}

	t[0] = toupper(t[0]);

	printf("%s\n", s);
	printf("%s\n", t);

	free(t);

	return 0;
}