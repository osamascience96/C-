#include<iostream>
bool GetTargetValue(int arr[], int mid, int start, int end);

int targetValue = 0;

int main() {
	std::cout << "Binary Search" << std::endl;
	// set of numbers in ordered form 
	int setOfNumbers[8] = {1, 2, 10, 15, 20, 25, 30, 35};
	// values to use in the algorithm 
	int midValue = 0; // value in the 
	int startValue = midValue; // startValue
	int endValue = (sizeof(setOfNumbers) / sizeof(setOfNumbers[0])) - 1; // ratio of numbers 

	// displaying the data in order to find the number 
	for (int i = 0; i < endValue; i++) {
		std::cout << " " << setOfNumbers[i] << " ";
	}
	std::cout << std::endl; // to the  next line 

	std::cout << "Enter the Target Value: ";
	std::cin >> targetValue;

	if (GetTargetValue(setOfNumbers, midValue, startValue, endValue) == 1) {
		// if the flag from the function is 1 ==> value found 
		std::cout << "The Value is found in the list" << std::endl;
	}
	else {
		// this block runs if the flag is 0, 
		std::cout << "The Value doesn't exists in the list" << std::endl;
	}

	return 0;
}

bool GetTargetValue(int arr[], int mid, int start, int end)
{
	/*For successful finding, the value of the mid should not remain the same
	at each iteration*/

	bool checkFound = 0; // default check flag is 0
	// find the mid value 
	mid = (start + end) / 2;
	// check mid value using chcekMid var
	int checkMid = 0;
	while (1)
	{
		
		// for best case in order to decrease processing power
		if (targetValue == arr[mid]) {
			// check for the best case in the list 
			checkFound = 1;
			break; // break for the infinite loop 
		}
		else
		{
			if (targetValue < arr[mid]) {
				// if the target value is less than the mid value 
				end = mid; // Make the end value the mid value
				// init new mid value according to the left part of the list 
				mid = (start + end) / 2;
			}
			else if (targetValue > arr[mid]) {
				// if the target value is greater than the mid value 
				start = mid;
				// init the new mid value according to the right part of the list 
				mid = (start + end) / 2;
			}
		}
		// if the mid value is not equal to checkMid 
		if (mid != checkMid) {
			checkMid = mid;
		}
		else
		{
			// if mid and checkmid that checks are same then break the loop
			break;
		}
	}
	return checkFound;
}
