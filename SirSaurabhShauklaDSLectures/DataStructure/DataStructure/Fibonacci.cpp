#include "pch.h"
#include "Fibonacci.h"


Fibonacci::Fibonacci()
{

}

int Fibonacci::fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return fib(n-1) + fib(n-2);
}
