//
// Created by xgallom on 10/29/19.
//

#ifndef MEJDI_RODNE_CISLO__RODNECISLO_H
#define MEJDI_RODNE_CISLO__RODNECISLO_H

#include <iostream>

static const bool Zena = false, Muz = true;
static const int RodneCisloLength = 12;

class RodneCislo {
public:
	RodneCislo(const char *newRodneCislo);

	const char *rodneCislo() const;
	void setRodneCislo(const char *newRodneCislo);

	bool pohlavie() const;

	int denNarodenia() const;
	int mesiacNarodenia() const;
	int rokNarodenia() const;

private:
	char m_rodneCislo[RodneCisloLength];
};

std::ostream& operator<<(std::ostream &os, const RodneCislo &r);

#endif //MEJDI_RODNE_CISLO__RODNECISLO_H
