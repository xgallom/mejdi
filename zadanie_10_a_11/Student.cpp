#include <cstring>
#include "Student.h"

static int compare(const Student &l, const Student &r)
{
	int result;

	if((result = strcmp(l.lastName, r.lastName)))
		return result;

	if((result = strcmp(l.firstName, r.firstName)))
		return result;

	if((result = r.dateOfBirth.year - l.dateOfBirth.year))
		return result;

	if((result = r.dateOfBirth.month - l.dateOfBirth.month))
		return result;

	return r.dateOfBirth.day - l.dateOfBirth.day;
}

bool operator>=(const Student &l, const Student &r)
{
	return compare(l, r) >= 0;
}
