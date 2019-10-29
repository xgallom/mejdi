//
// Created by xgallom on 10/29/19.
//

#include "RodneCislo.h"

namespace {
	enum RodneCisloIndex {
		RokDesiatky = 0,
		RokJednotky,
		MesiacDesiatky,
		MesiacJednotky,
		DniDesiatky,
		DniJednotky,

		Lomitko,

		Id0,
		Id1,
		Id2,
		Id3
	};

	int digit(char c)
	{
		return c - '0';
	}
}

RodneCislo::RodneCislo(const char *newRodneCislo)
{
	setRodneCislo(newRodneCislo);
}

const char *RodneCislo::rodneCislo() const
{
	return m_rodneCislo;
}

void RodneCislo::setRodneCislo(const char *newRodneCislo)
{
	for(int n = 0; n < RodneCisloLength; n++)
		m_rodneCislo[n] = newRodneCislo[n];
}

bool RodneCislo::pohlavie() const
{
	return m_rodneCislo[MesiacDesiatky] < '5';
}

int RodneCislo::denNarodenia() const
{
	return digit(m_rodneCislo[DniDesiatky]) * 10 + digit(m_rodneCislo[DniJednotky]);
}

int RodneCislo::mesiacNarodenia() const
{
	const int value = digit(m_rodneCislo[MesiacDesiatky]) * 10 + digit(m_rodneCislo[MesiacJednotky]);

	return value > 50 ? value - 50 : value;
}

int RodneCislo::rokNarodenia() const
{
	const int value = digit(m_rodneCislo[RokDesiatky]) * 10 + digit(m_rodneCislo[RokJednotky]);

	return value < 15 ? value + 2000 : value + 1900;
}
