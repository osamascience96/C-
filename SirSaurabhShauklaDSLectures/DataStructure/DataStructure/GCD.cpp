#include "pch.h"
#include "GCD.h"


GCD::GCD()
{
}

int GCD::greatestCommonDivisorOfTwoNums(int a, int b)
{
	if (a == b) {
		// return any number 
		return a;
	}

	if (a%b == 0) {
		return b;
	}

	if(b%a == 0) {
		return a;
	}

	if (a > b) {
		return(GCD::greatestCommonDivisorOfTwoNums(a % b, b));
	}
	else
	{
		return(GCD::greatestCommonDivisorOfTwoNums(a, b%a));
	}
}
