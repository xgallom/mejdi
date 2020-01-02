//
// Created by Revolware Company on 02/01/2020.
//

#ifndef ZADANIE_10_STUDENT_H
#define ZADANIE_10_STUDENT_H

struct Student {
	static const int MaxNameLength = 32;

	char firstName[MaxNameLength], lastName[MaxNameLength];
	struct {
		int day, month, year;
	} dateOfBirth;
	char grade;
};

bool operator>=(const Student &l, const Student &r);

#endif //ZADANIE_10_STUDENT_H
