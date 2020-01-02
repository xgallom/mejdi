//
// Created by Revolware Company on 01/01/2020.
//

#ifndef ZADANIE_2_FRACTION_H
#define ZADANIE_2_FRACTION_H


struct Fraction {
	int nominator, denominator;
};

Fraction createFraction();
void readFraction(Fraction *fraction);
void printFraction(const Fraction *fraction);
void reduceFraction(Fraction *fraction);
Fraction addFractions(const Fraction *a, const Fraction *b);
Fraction mulFractions(const Fraction *a, const Fraction *b);

#endif //ZADANIE_2_FRACTION_H
