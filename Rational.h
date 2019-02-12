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
public:
	void setNumerator(int);
	void setDenominator(int);

	int getNumerator();
	int getDenominator();

	std::string toString();

	Rational(int numerator = 1, int denominator = 1);
};
