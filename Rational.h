#include <string>

/*
	Rational Class Definition
*/
class Rational {
private:
	int numerator;
	int denominator;

	int gcd(int, int);
	void reduce();
	bool isZero();
public:
	void setNumerator(int);
	void setDenominator(int);

	int getNumerator();
	int getDenominator();

	std::string toString();

	Rational(int numerator = 1, int denominator = 1);

	bool operator <(const Rational&);
	bool operator <=(const Rational&);
	bool operator >(const Rational&);
	bool operator >=(const Rational&);
	bool operator !=(const Rational&);
	bool operator ==(const Rational&);

	Rational& operator +(const Rational&);
	Rational& operator -(const Rational&);
	Rational& operator *(const Rational&);
	Rational& operator /(const Rational&);
};
