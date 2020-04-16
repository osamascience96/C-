#include"pch.h"
#include<iostream>

class one {
	int x;
	friend void show();
};

class two {
	int y;
	friend void show();
};

void show() {
	one o1;
	o1.x = 10;
	two o2;
	o2.y = 20;

	std::cout << o1.x << " " << o2.y << std::endl;
}

int main() {

	show();
	return 0;
}