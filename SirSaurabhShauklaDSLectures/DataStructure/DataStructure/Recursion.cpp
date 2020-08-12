#include "pch.h"
#include "Recursion.h"


Recursion::Recursion()
{
}

int Recursion::recursiveSum(int a) {
	int s;
	if (a == 1)
		return a;
	else
		s = a + Recursion::recursiveSum(a - 1);

	return s;
}

Recursion::~Recursion()
{
}
