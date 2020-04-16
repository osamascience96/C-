// Bubble Sort using bucky method
#include<iostream>

int main() {
	int i, temp, swapped;
	const int howMany = 10;
	int goals[howMany];
	// init the array to numbers
	for (int i = 0; i < howMany; i++) {
		goals[i] = (rand() % 25) + 1; // random numbers in an array 
	}
	// print the array of random numbers 
	std::cout << "Original List" << std::endl;
	for (int i = 0; i < howMany; i++) {
		std::cout << goals[i] << std::endl;
	}

	// bubble algorithm
	while (true)
	{
		swapped = 0;
		
		for (int i = 0; i < howMany-1; i++) {
			if (goals[i] > goals[i + 1]) {
				int temp = goals[i];
				goals[i] = goals[i + 1];
				goals[i + 1] = temp;
				swapped = 1;
			}
		}

		if (swapped == 0) {
			break;
		}
	}

	// sorted list of an array 
	std::cout << "Sorted List" << std::endl;
	for (int i = 0; i < howMany; i++) {
		std::cout << goals[i] << std::endl;
	}

	return 0;
}
