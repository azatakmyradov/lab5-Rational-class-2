#include "catch.hpp"
#include "Rational.h"

TEST_CASE("TESTING RATIONAL CLASS") {
	Rational r;
	
	SECTION("testing setters and getters") {
		r.setNumerator(2);
		r.setDenominator(6);
		REQUIRE(r.getNumerator() == 1);
		REQUIRE(r.getDenominator() == 3);

		r.setNumerator(-2);
		r.setDenominator(-6);
		REQUIRE(r.getNumerator() == -1);
		REQUIRE(r.getDenominator() == -3);

		r.setNumerator(0);
		r.setDenominator(-6);
		REQUIRE(r.getNumerator() == 0);
		REQUIRE(r.getDenominator() == 0);
	}

	SECTION("Testing toString method from Rational") {
		r.setNumerator(2);
		r.setDenominator(6);
		REQUIRE(r.toString() == "1/3");

		r.setNumerator(0);
		r.setDenominator(0);
		REQUIRE(r.toString() == "0");

		r.setNumerator(-6);
		r.setDenominator(-2);
		REQUIRE(r.toString() == "-3/-1");
	}
}

