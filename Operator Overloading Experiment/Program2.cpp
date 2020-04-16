#include"pch.h"
#include<iostream>

class Complex {
private:
	int real;
	int imaginary;
public:
	Complex() {} // defaut constructor
	Complex(int real, int imaginary) {
		this->real = real;
		this->imaginary = imaginary;
	}

	void print() {
		std::cout << real << " " << imaginary << std::endl;
	}

	friend Complex operator+ (Complex c1, Complex c2);
};

int main() {
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2;
	c3.print();
	return 0;
}

Complex operator+(Complex c1, Complex c2)
{
	return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}
