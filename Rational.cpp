#include <iostream>
#include <algorithm>
#include "Rational.h"
#include <string>

using std::string;

int Rational::gcd(int a, int b) {
	// make sure both are positive
	a = abs(a);
	b = abs(b);

	// figure out which is bigger
	int mn = std::min(a, b);
	int mx = std::max(a, b);

	// since both are 0, the gcd is undefined, but we return 1
	if (mx == 0) return 1;
	// base case when the min is 0, then both can be divided by the max
	else if (mn == 0) return mx;
	// recursive case just focuses on the part of mx that doesn't already
	// divide evenly by mn
	else return gcd(mn, mx % mn);
}

/*
	Reduces the numerator and denominator by common diviser
*/
void Rational::reduce() {
	int gcd_result = gcd(numerator, denominator);
	setNumerator(numerator / gcd_result);
	setDenominator(denominator / gcd_result);
}

Rational::Rational(int numerator, int denominator) {
	setNumerator(numerator);
	setDenominator(denominator);
}

/*
	Sets the numerator
*/
void Rational::setNumerator(int number) {
	numerator = number;
}

/*
	Sets the denominator
*/
void Rational::setDenominator(int number) {
	denominator = number;
}

/*
	Gets and returns the numerator
*/
int Rational::getNumerator() {
	return numerator;
}

/*
	Gets and returns the denominator
*/
int Rational::getDenominator() {
	return denominator;
}

/*
	Returns the string representation of numerator and denominator
*/
string Rational::toString()
{
	reduce();
	return std::to_string(numerator) + "/" + std::to_string(denominator);
}
