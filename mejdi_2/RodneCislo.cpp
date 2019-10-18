//
// Created by xgallom on 10/18/19.
//

#include <iostream>
#include "RodneCislo.h"

int RodneCislo::rokNarodenia()
{
	return (m_rodneCislo[0] - '0') * 10 + m_rodneCislo[1] - '0';
}

Mesiac::Enum RodneCislo::mesiacNarodenia()
{
	return static_cast<Mesiac::Enum>(
			(m_rodneCislo[2] - '0' - (pohlavie() ? 5 : 0)) * 10 + m_rodneCislo[3] - '0' - 1
	);
}

int RodneCislo::denNarodenia()
{
	return (m_rodneCislo[4] - '0') * 10 + m_rodneCislo[5] - '0';
}

Pohlavie::Enum RodneCislo::pohlavie()
{
	return m_pohlavie;
}

RodneCislo RodneCislo::precitajRodneCislo()
{
	RodneCislo vysledok;
	std::cout << "Rodne cislo: ";

	std::cin >> vysledok.m_rodneCislo;
	vysledok.m_pohlavie = static_cast<Pohlavie::Enum>((vysledok.m_rodneCislo[2] - '0') >= 5);

	return vysledok;
}

std::ostream &operator<<(std::ostream &os, const Mesiac::Enum &mesiac)
{
	static constexpr char NameTable[Mesiac::Size][10] = {
			"Januar",
			"Februar",
			"Marec",
			"April",
			"Maj",
			"Jun",
			"Jul",
			"August",
			"September",
			"October",
			"November",
			"December"
	};

	return os << NameTable[mesiac];
}

std::ostream &operator<<(std::ostream &os, const Pohlavie::Enum &pohlavie)
{
	return os << (pohlavie ? "Zena" : "Muz");
}
