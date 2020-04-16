#include<stdio.h>
#include<string.h>

int main(int n, char *args[]) {

	if (n < 3) {
		return 1;
	}

	FILE *file = fopen("phonebook.csv", "a");

	char *name = args[1];
	char *number = args[2];

	fprintf(file, "%s,%s\n", name, number);

	fclose(file);
}