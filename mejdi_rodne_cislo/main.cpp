#include <iostream>
#include "RodneCislo.h"

int main()
{
	RodneCislo moje("970427/1434");

	std::cout
			<< "Rodne cislo: " << moje.rodneCislo() << "\n"
			<< "Pohlavie: " << (moje.pohlavie() ? "Muz" : "Zena") << "\n"
			<< "Rok narodenia: " << moje.rokNarodenia() << "\n"
			<< "Mesiac narodenia: " << moje.mesiacNarodenia() << "\n"
			<< "Den narodenia: " << moje.denNarodenia() << "\n";

	return 0;
}
