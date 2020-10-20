// for the selection problem where the comparisons are k/2 write the program and notice  the sample constant runtimes using its time complexity formula 
// which is 1/2(n^2 - n)

#include <iostream>

void selectionSort(int arr[], int aLength) {
	for (int i = 0; i < aLength - 1; i++) {
		int jMin = i;
		for (int j = i + 1; j < aLength; j++) {
			if (arr[j] < arr[jMin]) {
				jMin = j;
			}
		}

		if (jMin != i) {
			int temp = arr[i];
			arr[i] = arr[jMin];
			arr[jMin] = temp;
		}
	}

}

int main()
{
	int arr[] = { 8, 5, 2, 6, 9 };
	selectionSort(arr, sizeof(arr)/sizeof(arr[0]));

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";

	// The runtime values achieved for various values of n are as under
	// let for n = 5, i received the constant runtime of 10 and for n = 10, i received the constant runtime of 45 etc

	return 0;
}
