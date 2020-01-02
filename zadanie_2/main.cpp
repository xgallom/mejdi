#include "Fraction.h"
#include <iostream>

int main()
{
	Fraction a, b;

	readFraction(&a);
	printFraction(&a);

	std::cout << "\n";

	readFraction(&b);
	printFraction(&b);

	const Fraction
		mul = mulFractions(&a, &b),
		sum = addFractions(&a, &b);

	std::cout << "\nSucin zlomkov: ";
	printFraction(&mul);

	std::cout << "Sucet zlomkov: ";
	printFraction(&sum);

	return 0;
}