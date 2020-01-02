#include "Fraction.h"
#include <iostream>

Fraction createFraction(int nominator, int denominator)
{
	Fraction fraction = {nominator, denominator};

	reduceFraction(&fraction);

	return fraction;
}

void readFraction(Fraction *fraction)
{
	std::cout << "Zadajte zlomok: ";
	std::cin >> fraction->nominator >> fraction->denominator;
}

void printFraction(const Fraction *fraction)
{
	Fraction reducedFraction = *fraction;

	reduceFraction(&reducedFraction);

	const int
			whole = fraction->nominator / fraction->denominator,
			part = fraction->nominator % fraction->denominator;

	if(whole)
		std::cout << whole << " ";

	if(part)
		std::cout << part << "/" << fraction->denominator;

	std::cout << "\n";
}

static int greatestCommonDenominator(int a, int b)
{
	while(b) {
		int c = a % b;
		a = b;
		b = c;
	}

	return a;
}

void reduceFraction(Fraction *fraction)
{
	const int gcd = greatestCommonDenominator(fraction->nominator, fraction->denominator);

	fraction->nominator /= gcd;
	fraction->denominator /= gcd;
}

Fraction addFractions(const Fraction *a, const Fraction *b)
{
	return createFraction(
			a->nominator * b->denominator + b->nominator * a->denominator,
			a->denominator * b->denominator
	);
}
Fraction mulFractions(const Fraction *a, const Fraction *b)
{
	return createFraction(
			a->nominator * b->nominator,
			a->denominator * b->denominator
	);
}
