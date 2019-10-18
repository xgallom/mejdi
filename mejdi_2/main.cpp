#include <iostream>
#include "RodneCislo.h"

using namespace std;

int main()
{
	RodneCislo moje = RodneCislo::precitajRodneCislo();

	std::cout << "Rok narodenia: " << moje.rokNarodenia() << std::endl;
	std::cout << "Mesiac narodenia: " << moje.mesiacNarodenia() << std::endl;
	std::cout << "Den narodenia: " << moje.denNarodenia() << std::endl;
	std::cout << "Pohlavie: " << moje.pohlavie() << std::endl;

	return 0;
}
