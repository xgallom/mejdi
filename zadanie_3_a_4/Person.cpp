#include "Person.h"
#include <cstring>

Person::Person(const char *a_firstName, const char *a_lastName, const char *a_personalNumber)
{
	strcpy(m_firstName, a_firstName);
	strcpy(m_lastName, a_lastName);
	m_personalNumber = PersonalNumber(a_personalNumber);
}

const PersonalNumber &Person::personalNumber() const
{
	return m_personalNumber;
}

const char *Person::name() const
{
	char *name = new char[NameLength * 2 + 2];

	const int nameLength = strlen(m_firstName);

	strcpy(name, m_firstName);
	name[nameLength] = ' ';

	strcpy(name + nameLength + 1, m_lastName);

	return name;
}

void Person::setFirstName(const char *a_firstName)
{
	strcpy(m_firstName, a_firstName);
}

void Person::setLastName(const char *a_lastName)
{
	strcpy(m_lastName, a_lastName);
}

void Person::setPersonalNumber(const PersonalNumber &a_personalNumber)
{
	m_personalNumber = a_personalNumber;
}

Person Person::Read(int n)
{
	Person result = {};

	char input[NameLength] = {};

	std::cout << "Zadajte krstne meno " << n << ". osoby: ";
	std::cin >> input;

	result.setFirstName(input);

	memset(input, '\0', NameLength);

	std::cout << "Zadajte priezvisko " << n << ". osoby: ";
	std::cin >> input;

	result.setLastName(input);

	result.setPersonalNumber(PersonalNumber::Read(n));

	return result;
}

std::ostream &operator<<(std::ostream &os, const Person &person)
{
	return os
			<< "Meno: " << person.name() << "\n"
			<< "Rodne cislo: " << person.personalNumber();
}
