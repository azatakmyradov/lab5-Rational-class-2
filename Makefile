app.o: Rational.cpp Rational.h lab5main-driver.o
	g++ Rational.cpp lab5main-driver.cpp --std=c++11 -o app.o

test.o: Rational.cpp RationalTests.cpp Rational.h lab5test-driver.o
	g++ Rational.cpp RationalTests.cpp lab5test-driver.o --std=c++11 -o test.o

lab5test-driver.o: lab5test-driver.cpp catch.hpp
	g++ -c lab5test-driver.cpp --std=c++11
