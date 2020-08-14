#include "pch.h"
#include <iostream>
#include"Hanoi.h"

int sum(int);

int main()
{
	// Call of the 1st program
	/*Recursion *recursiveObj = new Recursion();

	int k = recursiveObj->recursiveSum(10);
	std::cout << k << std::endl;*/

	// Call of the 2nd Tower of Hanoi Program
	Hanoi *hanoiObj = new Hanoi();
	hanoiObj->TowerOfHanoiFunction(3, 'a', 'b', 'c');
	return 0;
}