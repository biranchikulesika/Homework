/*
 * Program: Operator Overloading Example
 * Description: This C++ program demonstrates operator overloading.
 *              It defines a Complex class and overloads the '+' operator
 *              to add two Complex objects.
 * Author: Biranchi Kulesika
 */

#include <iostream>
using namespace std;

class Complex
{
	float real, imag;

public:
	Complex(float r = 0, float i = 0) : real(r), imag(i) {}

	Complex operator+(Complex c)
	{
		return Complex(real + c.real, imag + c.imag);
	}

	void display()
	{
		cout << real << " + " << imag << "i" << endl;
	}
};

int main()
{
	Complex c1(3, 2), c2(1, 7);
	Complex c3 = c1 + c2;
	c3.display();

	return 0;
}
