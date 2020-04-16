#include<iostream>
bool Search(int x[], int data); // search function declaration (prototype)

int setOfNumbers[] = { 4,2,19,15,10,9 }; // set of numbers in array
int sizeOfArray = sizeof(setOfNumbers) / sizeof(setOfNumbers[0]); // size of array of n numbers

int main() {

	int data = 0;

	for (int i = 0; i < sizeOfArray; i++) {
		std::cout << setOfNumbers[i] << " ";
	}
	std::cout << std::endl;

	// user input 
	std::cout << "Enter the Number to find: ";
	std::cin >> data;

	// Search the number 
	if (Search(setOfNumbers, data) == 1) {
		// if the result is 1, then 
		std::cout << "The Number Exists in the list" << std::endl;
	}
	else {
		std::cout << "The Number doesn't exists in the list" << std::endl;
	}

	return 0;
}

// definition of the function of search
bool Search(int x[], int data)
{
	short countPossibility = 0; 
	// iterate through the array to find the data 
	for (int i = 0; i < sizeOfArray; i++) {
		if (x[i] == data) {
			countPossibility += 1;
		}
	}

	// if the possible result is > 0, then 
	if (countPossibility > 0) {
		// found, return 1
		return 1;
	}
	else
	{
		// not found
		return 0;
	}
}
