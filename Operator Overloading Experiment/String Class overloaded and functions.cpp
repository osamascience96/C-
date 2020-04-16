#include"pch.h"
#include<iostream>
#include<string>

int main() {
	std::string s1("Happy");
	std::string s2("Birthday");
	std::string s3;

	// test overloaded equality and relational operators
	// Line 11 contains the << and >> overloaded operators for the string class
	std::cout << "S1 is " << s1 << "\nS2 is " << s2 << "\nS3 is " << s3 << std::endl;
	// Line 14 to 20 contains all the examples of overloaded operators with string class 
	std::cout << "\n The Results of comparing S1 and S2 are:";
	std::cout << "\n S1 == S2 yeilds " << (s1 == s2 ? "true" : "false");
	std::cout << "\n S1 != S2 yeilds " << (s1 != s2 ? "true" : "false");
	std::cout << "\n S1 > S2 yeilds " << (s1 > s2 ? "true" : "false");
	std::cout << "\n S1 < S2 yeilds " << (s1 < s2 ? "true" : "false");
	std::cout << "\n S1 >= S2 yeilds " << (s1 >= s2 ? "true" : "false");
	std::cout << "\n S1 <= S2 yeilds " << (s1 <= s2 ? "true" : "false");

	// test string member-function empty
	std::cout << "\nTesting s3.empty():" << std::endl;

	if (s3.empty()) {
		std::cout << "s3 is empty, assign s1 to s3 \n";
		s3 = s1;
		std::cout << "S3 is " << s3 << std::endl;
	}

	// test the overloaded string concatenation operator
	s1 += (" "+s2);
	std::cout << "The concatenation of s1 and s2 are " << s1 << std::endl;
	// Another Experiment for the overloaded string concatenation operator
	s1 += " to you";
	std::cout << "S1 = " << s1 << std::endl;

	// test string member function substr
	std::cout << "The substring from index location 0 to 14 " << s1.substr(0, 14) << std::endl;
	// another substr experiment
	std::cout << "The substring from index 15 to end results in " << s1.substr(15) << std::endl;

	// test copy constructor
	std::string s4(s1);
	std::cout << "S4 = " << s4 << std::endl;

	// overload subscript operator to create lvalue
	s1[0] = 'H';
	s1[6] = 'B';

	std::cout << "Again the value of s1 = " << s1 << std::endl;

	// stream the subscript overloaded operator and at function of string class
	std::cout << "Stream the characters with overloaded operators and function of string class\n";
	std::cout << s1[0] << " " << s1[6] << " " << s1.at(16) << std::endl;

	// exception handling with subscript out of range
	try {
		std::cout << "Attempt to assign 'd' to location 30 in s1" << std::endl;
		s1.at(30) = 'd';
	}
	catch (std::out_of_range &ex) {
		std::cout << "An exception occured: " << ex.what() << std::endl;
	}

	return 0;
}