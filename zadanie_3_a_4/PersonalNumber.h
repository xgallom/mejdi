#ifndef MEJDI_2__RODNECISLO_H
#define MEJDI_2__RODNECISLO_H

#include <iostream>

namespace Gender {
	enum Enum : bool {
		Male,
		Female
	};
}

class PersonalNumber {
public:
	static const int PersonalNumberSize = 12;

	PersonalNumber() = default;
	PersonalNumber(const char *a_personalNumber);

	int birthYear() const;
	int birthMonth() const;
	int dayOfBirth() const;

	Gender::Enum gender() const;

	void setPersonalNumber(const char *a_personalNumber);

	static PersonalNumber Read(int n);
private:
	char m_personalNumber[PersonalNumberSize];
	Gender::Enum m_gender;
};

std::ostream &operator<<(std::ostream &os, const Gender::Enum &gender);
std::ostream &operator<<(std::ostream &os, const PersonalNumber &personalNumber);

#endif //MEJDI_2__RODNECISLO_H
