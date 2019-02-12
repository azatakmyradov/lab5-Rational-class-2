#include "catch.hpp"
#include "Rational.h"

TEST_CASE("TESTING RATIONAL CLASS") {
	Rational r;
	
	SECTION("testing setters and getters") {
		r.setNumerator(2);
		r.setDenominator(6);
		REQUIRE(r.getNumerator() == 2);
		REQUIRE(r.getDenominator() == 6);

		r.setNumerator(-2);
		r.setDenominator(-6);
		REQUIRE(r.getNumerator() == -2);
		REQUIRE(r.getDenominator() == -6);

		r.setNumerator(0);
		r.setDenominator(-6);
		REQUIRE(r.getNumerator() == 0);
		REQUIRE(r.getDenominator() == -6);
	}

	SECTION("testing reduce method from Rational class") {
		r.setNumerator(2);
		r.setDenominator(6);
		REQUIRE(r.getNumerator() == 1);
		REQUIRE(r.getDenominator() == 3);

		r.setNumerator(0);
		r.setDenominator(0);
		REQUIRE(r.getNumerator() == 0);
		REQUIRE(r.getDenominator() == 0);

		r.setNumerator(-2);
		r.setDenominator(-6);
		REQUIRE(r.getNumerator() == -1);
		REQUIRE(r.getDenominator() == -3);
	}

	SECTION("Testing toString method from Rational") {
		r.setNumerator(2);
		r.setDenominator(6);
		REQUIRE(r.toString() == "2/6");

		r.setNumerator(0);
		r.setDenominator(0);
		REQUIRE(r.toString() == "0/0");

		r.setNumerator(-6);
		r.setDenominator(-2);
		REQUIRE(r.toString() == "-6/-2");
	}
}

