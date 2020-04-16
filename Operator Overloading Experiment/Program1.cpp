#include"pch.h"
#include<iostream>

class Complex {
private:
	int real;
	int imaginary;
public:
	Complex(){}
	Complex(int real, int imaginary) {
		this->real = real;
		this->imaginary = imaginary;
	}

	Complex operator+ (Complex obj) {
		Complex brandNew;
		brandNew.real = this->real + obj.real;
		brandNew.imaginary = this->imaginary + obj.imaginary;
		return brandNew;
	}

	void print() {
		std::cout << real << " " << imaginary << std::endl;
	}
};

int main() {

	Complex c1(10, 3), c2(2, 4);
	Complex c3 = c1 + c2;
	c3.print();

	return 0;
}