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

bool Rational::isZero() {
	if (numerator == 0 || denominator == 0)
	{
		return true;
	}

	return false;
}

Rational::Rational(int numerator, int denominator) {
	setNumerator(numerator);
	setDenominator(denominator);
	reduce();
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
	reduce();
	if (isZero()) {
		numerator = 0;
		denominator = 0;
	}
	return numerator;
}

/*
	Gets and returns the denominator
*/
int Rational::getDenominator() {
	reduce();
	if (isZero()) {
		numerator = 0;
		denominator = 0;
	}
	return denominator;
}

/*
	Returns the string representation of numerator and denominator
*/
string Rational::toString()
{
	reduce();
	if (isZero())
	{
		return "0";
	}

	return std::to_string(numerator) + "/" + std::to_string(denominator);
}

// Rational operator which returns if the first Rational smaller than second Rational
bool Rational::operator <(const Rational& rhs) {
	double rational1 = numerator * 1.0 / denominator * 1.0;
	double rational2 = rhs.numerator * 1.0 / rhs.denominator * 1.0;
    return rational1 < rational2;
}

// Rational operator which returns if the first Rational smaller than second Rational or equal
bool Rational::operator <=(const Rational& rhs) {
    double rational1 = numerator * 1.0 / denominator * 1.0;
	double rational2 = rhs.numerator * 1.0 / rhs.denominator * 1.0;
    return rational1 <= rational2;
}

// Rational operator which returns if the first Rational bigger than second Rational
bool Rational::operator >(const Rational& rhs) {
    double rational1 = numerator * 1.0 / denominator * 1.0;
	double rational2 = rhs.numerator * 1.0 / rhs.denominator * 1.0;
    return rational1 > rational2;
}

// Rational operator which returns if the first Rational bigger than second Rational or equal
bool Rational::operator >=(const Rational& rhs) {
    double rational1 = numerator * 1.0 / denominator * 1.0;
	double rational2 = rhs.numerator * 1.0 / rhs.denominator * 1.0;
    return rational1 >= rational2;
}

// Rational operator which return true if two Rationals not equal
bool Rational::operator !=(const Rational& rhs) {
    double rational1 = numerator * 1.0 / denominator * 1.0;
	double rational2 = rhs.numerator * 1.0 / rhs.denominator * 1.0;
    return rational1 != rational2;
}

// Rational operator which return true if two Rationals equal
bool Rational::operator ==(const Rational& rhs) {
    return numerator == rhs.numerator && denominator == rhs.denominator;
}

// Operator to add two Rationals
Rational& Rational::operator +(const Rational& rhs) {
    int new_denominator = denominator * rhs.denominator;
    int new_numerator = numerator * rhs.denominator;
    int new_numerator2 = rhs.numerator * denominator;
    new_numerator += new_numerator2;

    Rational rational(new_numerator, new_denominator);

    return rational;
}

// Operator to add subtract Rationals
Rational& Rational::operator -(const Rational& rhs) {
    int new_denominator = denominator * rhs.denominator;
    int new_numerator = numerator * rhs.denominator;
    int new_numerator2 = rhs.numerator * denominator;
    new_numerator -= new_numerator2;

    Rational rational(new_numerator, new_denominator);

    return rational;
}

// Operator to add divide Rationals
Rational& Rational::operator /(const Rational& rhs) {
    int new_numerator = numerator * rhs.denominator;
    int new_denominator = denominator * rhs.numerator;

    Rational rational(new_numerator, new_denominator);

    return rational;
}

// Operator to add multiply Rationals
Rational& Rational::operator *(const Rational& rhs) {
    int new_numerator = numerator * rhs.numerator;
    int new_denominator = denominator * rhs.denominator;

    Rational rational(new_numerator, new_denominator);

    return rational;
}
