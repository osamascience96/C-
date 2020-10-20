// Program to solve the word puzzle problem
#include <iostream>
#include <string>

const int rowBound = 4;
const int colBound = 4;

struct board {
	char wordBoard[rowBound][colBound] = {
		{'t', 'h', 'i', 's'},
		{'w', 'a', 't', 's'},
		{'o', 'a', 'h', 'g'},
		{'f', 'g', 'd', 't'}
	};
}bd;

int main()
{
	// init the list of words
	std::string listOfWords[] = {"this", "two", "fat", "that", "his"};

	// iterate through the list linearly 1-n
	for (int k = 0; k < listOfWords->size(); k++) {
		std::string word = listOfWords[k];
		
		// program incomplete
	}
	return 0;
}
