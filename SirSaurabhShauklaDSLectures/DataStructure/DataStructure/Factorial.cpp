#include "pch.h"
#include "Factorial.h"


Factorial::Factorial()
{
}

int Factorial::performFactorial(int n)
{
	if (n > 0) {
		return n * Factorial::performFactorial(n - 1);
	}

	return 1;
}
