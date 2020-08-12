// program to read 3 bytes of the picture
#include<stdio.h>

int main(int argc, char *argv[]) {
	//printf("%i==>%s\n", argc, argv[1]);

	// if the program not provides 2 arguments
	if (argc != 2) {
		return 1;
	}

	// open the file 
	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		return 1;
	}

	// Read 3 bytes from a file 
	unsigned char bytes[3]; // unsigned char to read number from 0 to 255
	/* arg1(the array i wanna store the bytes) arg2(how many bytes) 
	arg3(how many times i wanaa read) arg4(from where i wanna read those bytes)*/
	fread(bytes, 3, 1, file);

	// Check if bytes are 0xff 0xd8 0xff (1st 3 bytes of any jpeg image in the world)
	if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff) {
		printf("Maybe a JPEG\n");
	}
	else {
		printf("NOT A JEPG\n");
	}
}