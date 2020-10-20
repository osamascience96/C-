// Program that uses the random number generator with I/O Operation at constant time to produce the random number in double type
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double doubleRandomNumber();

int main() {
	std::cout << doubleRandomNumber() << std::endl;
	return 0;
}

// Time Complexity of the function is O(1)
double doubleRandomNumber() {
	// taking the input from the seed
	srand(time(0));

	double f = (double)rand() / (double)RAND_MAX;
	return rand() * f;
}
