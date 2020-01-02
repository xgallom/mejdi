//
// Created by Revolware Company on 01/01/2020.
//

#ifndef MEJDI_2_PERSON_H
#define MEJDI_2_PERSON_H

#include "PersonalNumber.h"

class Person {
public:
	static const int NameLength = 32;

	Person() = default;
	Person(const char *a_firstName, const char *a_lastName, const char *a_personalNumber);

	const char *firstName() const;
	const char *lastName() const;
	const PersonalNumber &personalNumber() const;

	const char *name() const;

	void setFirstName(const char *a_firstName);
	void setLastName(const char *a_lastName);
	void setPersonalNumber(const PersonalNumber &a_personalNumber);

	static Person Read(int n);

private:
	char m_firstName[NameLength], m_lastName[NameLength];
	PersonalNumber m_personalNumber;
};

std::ostream &operator<<(std::ostream &os, const Person &person);

#endif //MEJDI_2_PERSON_H
