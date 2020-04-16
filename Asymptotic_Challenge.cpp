#include "pch.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool GetPrimeFlag(int);

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int T;
	int n;
	cin >> T;

	// This is 1, O(n) algorithm
	while (T-- != 0) {
		cin >> n;

		if (GetPrimeFlag(n) == 1) {
			cout << "Prime" << endl;
		}
		else {
			cout << "Not prime" << endl;
		}
	}
	return 0;
}

bool GetPrimeFlag(int n)
{
	bool flag = 1; // O(1)

	if (n == 1) {
		flag = 0;
	}else {
		int sq = sqrt(n) + 1; // O(sqrt(n)) + 1
		for (int i = 2; i < sq; i++) { // O(n)
			if (n % i == 0) {
				flag = 0;
			}
		}
	}
	return flag;
}
