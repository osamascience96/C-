#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

const char* myAbsolutePath = "C://Users//osama//OneDrive//Documents//GitHub//C-//CS50_Labs//Sort//";
double algorithmTime = 0;

/// <summary>
/// Read the file name and the number of elements in it
/// </summary>
/// <param name="fileName">name of the file</param>
/// <param name="size">number of elements in the file</param>
/// <returns>returns the integer array of the number from the file</returns>
int* GetFiguresArrayByFile(std::string fileName, int size) {
	int* figuresArray = new int[size];

	std::string fullFilePath = myAbsolutePath + fileName;
	std::ifstream inputStream;
	inputStream.open(fullFilePath, std::ios::in);
	if (!inputStream) {
		std::cout << "Failed to Open the File";
		return NULL;
	}
	else {
		std::string figure = "";
		int count = 0;
		while (std::getline(inputStream, figure)) {
			figuresArray[count] = std::stoi(figure);
			count += 1;
		}
	}
	inputStream.close();
	return figuresArray;
}

/// <summary>
/// Swaps the values of the two memory address
/// </summary>
/// <param name="memadd1">param 1 with the address of first value</param>
/// <param name="memadd2">param 2 with the address of second value</param>
void Swap(int* memadd1, int* memadd2) {
	int tempAdd = *memadd2;
	*memadd2 = *memadd1;
	*memadd1 = tempAdd;
}

/// <summary>
/// Selection Sort Alogrithm that sorts the given integer array 
/// Run Time is O(n**2)
/// </summary>
/// <param name="figuresArray">takes the array in param</param>
/// <param name="length">takes in the length</param>
/// <returns>return the sorted array</returns>
int* ApplySelectionSortAlgorithm(int* figuresArray, int length) {
	std::clock_t starttime, endtime;
	starttime = clock();
	for (int i = 0; i < length; i++) {
		int smallIndex = i;
		for (int j = i; j < length; j++) {
			if (figuresArray[j] < figuresArray[smallIndex]) {
				smallIndex = j;
			}
		}

		// sort the array
		Swap(&figuresArray[i], &figuresArray[smallIndex]);
	}
	endtime = clock();
	algorithmTime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC;
	return figuresArray;
}

/// <summary>
/// Bubble Sort Algorithm that sorts the given integer array
/// Run Time is O(n**2)
/// </summary>
/// <param name="figuresArray">takes the array in param</param>
/// <param name="length">takes in the length</param>
/// <returns>return the sorted array</returns>
int* ApplyBubbleSortAlgorithm(int* figuresArray, int length) {
	for (int i = 0; i <= length; i++) {
		bool swapped = false;
		for (int j = 0; j < length - 1; j++) {
			if (figuresArray[j] > figuresArray[j + 1]) {
				swapped = true;
				Swap(&figuresArray[j], &figuresArray[j + 1]);
			}
		}

		if (swapped == false) {
			break;
		}
	}

	return figuresArray;
}

/// <summary>
/// Stores the sorted array file in the provided absolute path with the specific algorithm name
/// </summary>
/// <param name="sortedFiguresArray">sorted figure array</param>
/// <param name="length">the length of the array</param>
/// <param name="algorithmName">the name of the algorithm</param>
void StoreSortedFile(int* sortedFiguresArray, int length, std::string algorithmName) {
	std::string fileName = "Sorted_List_" + algorithmName + "_" + std::to_string(length) + ".txt";
	// create the file in the given absolute path
	std::string fullFilePath = myAbsolutePath + fileName;
	std::fstream outputStream;
	outputStream.open(fullFilePath, std::ios::out);
	if (outputStream) {
		for (int i = 0; i < length; i++) {
			outputStream << sortedFiguresArray[i] << std::endl;
		}
	}
	else {
		std::cout << "File Cannot be Created";
	}
	outputStream.close();
}

void StoreAlgorithmTime(std::string algorithmName, std::string againstfilename) {
	std::string timefilename = "AlgorithmTime.txt";
	std::string fullFilePath = myAbsolutePath + timefilename;

	std::fstream outputStream;
	outputStream.open(fullFilePath, std::ios::app);
	if (outputStream) {
		outputStream << "The time took by " + algorithmName + " to sort the numbers in file in " + againstfilename + " is " + std::to_string(algorithmTime) + " seconds." << std::endl;
	}
	else {
		std::cout << "File Cannot be Created";
	}
	outputStream.close();
}

int main() {
	// init all the figuresArray of the Files
	int* figuresArray5000 = GetFiguresArrayByFile((char*)"random5000.txt", 5000);
	int* figuresArray10000 = GetFiguresArrayByFile((char*)"random10000.txt", 10000);
	int* figuresArray50000 = GetFiguresArrayByFile((char*)"random50000.txt", 50000);

	// Selection Sort
	// Apply Selection Sort to the 5000 Random Files
	figuresArray5000 = ApplySelectionSortAlgorithm(figuresArray5000, 5000);
	StoreSortedFile(figuresArray5000, 5000, "Selection Sort");
	StoreAlgorithmTime("Selection Sort", "random5000");
	// Apply Selection Sort to the 10000 Random Files
	figuresArray10000 = ApplySelectionSortAlgorithm(figuresArray10000, 10000);
	StoreSortedFile(figuresArray10000, 10000, "Selection Sort");
	StoreAlgorithmTime("Selection Sort", "random10000");
	// Apply Selection Sort to the 50000 Random Files
	figuresArray50000 = ApplySelectionSortAlgorithm(figuresArray50000, 50000);
	StoreSortedFile(figuresArray50000, 50000, "Selection Sort");
	StoreAlgorithmTime("Selection Sort", "random50000");

	std::cout << "Selection Sort Done" << std::endl;

	// Bubble Sort
	// apply the bubble sort to the 5000 Random Files
	figuresArray5000 = ApplyBubbleSortAlgorithm(figuresArray5000, 5000);
	StoreSortedFile(figuresArray5000, 5000, "Bubble Sort");
	StoreAlgorithmTime("Bubble Sort", "random5000");
	// Apply Bubble Sort to the 10000 Random Files
	figuresArray10000 = ApplyBubbleSortAlgorithm(figuresArray10000, 10000);
	StoreSortedFile(figuresArray10000, 10000, "Bubble Sort");
	StoreAlgorithmTime("Bubble Sort", "random10000");
	// Apply Bubble Sort to the 50000 Random Files
	figuresArray50000 = ApplyBubbleSortAlgorithm(figuresArray50000, 50000);
	StoreSortedFile(figuresArray50000, 50000, "Bubble Sort");
	StoreAlgorithmTime("Bubble Sort", "random50000");

	std::cout << "Bubble Sort Done" << std::endl;
}
