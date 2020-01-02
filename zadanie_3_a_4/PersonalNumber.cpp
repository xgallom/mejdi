#include <iostream>
#include "PersonalNumber.h"

PersonalNumber::PersonalNumber(const char *a_personalNumber)
{
	strncpy(m_personalNumber, a_personalNumber, PersonalNumberSize);
	m_gender = (m_personalNumber[2] - '0') >= 5 ? Gender::Female : Gender::Male;
}

int PersonalNumber::birthYear() const
{
	const int year = (m_personalNumber[0] - '0') * 10 + m_personalNumber[1] - '0';

	if(year < 15)
		return year + 2000;
	else
		return year + 1900;
}

int PersonalNumber::birthMonth() const
{
	return (m_personalNumber[2] - '0' - (gender() ? 5 : 0)) * 10 + m_personalNumber[3] - '0';
}

int PersonalNumber::dayOfBirth() const
{
	return (m_personalNumber[4] - '0') * 10 + m_personalNumber[5] - '0';
}

Gender::Enum PersonalNumber::gender() const
{
	return m_gender;
}

void PersonalNumber::setPersonalNumber(const char *a_personalNumber)
{
	strncpy(m_personalNumber, a_personalNumber, PersonalNumberSize);
	m_gender = (m_personalNumber[2] - '0') >= 5 ? Gender::Female : Gender::Male;
}

PersonalNumber PersonalNumber::Read(int n)
{
	PersonalNumber result = {};
	std::cout << "Zadajte rodne cislo " << n << ": ";

	std::cin >> result.m_personalNumber;
	result.m_gender = static_cast<Gender::Enum>((result.m_personalNumber[2] - '0') >= 5);

	return result;
}

std::ostream &operator<<(std::ostream &os, const Gender::Enum &gender)
{
	return os << (gender ? "Zena" : "Muz");
}

std::ostream &operator<<(std::ostream &os, const PersonalNumber &personalNumber)
{
	return os
			<< "Datum narodenia: " << personalNumber.dayOfBirth() << "." << personalNumber.birthMonth()
			<< "." << personalNumber.birthYear() << "\n"
			<< "Pohlavie: " << personalNumber.gender() << "\n";
}
