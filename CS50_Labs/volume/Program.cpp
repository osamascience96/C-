#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>

const char *absolutePath = "C://Users//osama//OneDrive//Documents//GitHub//C-//CS50_Labs//volume//";

std::string GetInputFilePath() {
	std::string inputfile = "input.wav";
	std::string inputfilepath = absolutePath + inputfile;
	return inputfilepath;
}

std::string GetOutputFilePath() {
	std::string outputfile = "output.wav";
	std::string outputfilepath = absolutePath + outputfile;
	return outputfilepath;
}

const int headerBytes = 44;

int main() 
{
	// declare the stream
	std::FILE *fileRead = fopen(const_cast<char*>(GetInputFilePath().c_str()), "r");
	std::FILE *fileWrite = fopen(const_cast<char*>(GetOutputFilePath().c_str()), "w");
	
	// read the header bytes from the buffer
	// header size of each element in the stream is 8 bit
	// init the array of 1 byte of 44 elements in memory
	uint8_t headerbuffer[headerBytes];
	fread(&headerbuffer, headerBytes, 1, fileRead);
	fwrite(&headerbuffer, headerBytes, 1, fileWrite);

	float factor = 0;

	std::cout << "Enter the Factor to control the volume of the audio file: ";
	std::cin >> factor;

	if (factor > 0) {
		uint16_t buffer;
		// product with factor
		while (fread(&buffer, sizeof(uint16_t), 1, fileRead)) {
			buffer *= factor;
			fwrite(&buffer, sizeof(uint16_t), 1, fileWrite);
		}
	}
	else {
		std::cout << "The Factor must be greater than 0" << std::endl;
	}

	fclose(fileRead);
	fclose(fileWrite);
}