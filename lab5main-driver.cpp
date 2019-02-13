#include <iostream>
#include "Rational.h"

using std::cout;
using std::cin;

std::ostream& operator <<(std::ostream& out, Rational& r) {
    out << r.toString();
    return out;
}

int main() {
	// create variables
	int numerator1, denominator1, numerator2, denominator2;

	// getting values from user
	cout << "Enter numerator: ";
	cin >> numerator1;

	cout << "Enter Denominator: ";
	cin >> denominator1;

	cout << "Enter another numerator: ";
	cin >> numerator2;
	
	cout << "Enter another denominator: ";
	cin >> denominator2;

	// create Rational class from values
	Rational rational1(numerator1, denominator1);
	Rational rational2(numerator2, denominator2);

	cout << rational1 * rational2;

	return 0;
}
