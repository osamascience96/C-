#include "pch.h"
#include <iostream>
#include"Recursion.h"

int sum(int);

int main()
{
	Recursion *recursiveObj = new Recursion();

	int k = recursiveObj->recursiveSum(10);
	std::cout << k << std::endl;
	return 0;
}