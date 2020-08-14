#include "pch.h"
#include "Hanoi.h"
#include <iostream>


Hanoi::Hanoi()
{
}

void Hanoi::TowerOfHanoiFunction(int numberOfDisks, char source, char auxilary, char destination)
{
	if (numberOfDisks >= 1) {
		TowerOfHanoiFunction(numberOfDisks - 1, source, destination, auxilary);
		std::cout << source << " to " << destination << std::endl;
		TowerOfHanoiFunction(numberOfDisks - 1, auxilary, source, destination);
	}
}