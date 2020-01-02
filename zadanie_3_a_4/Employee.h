#ifndef MEJDI_2_EMPLOYEE_H
#define MEJDI_2_EMPLOYEE_H

#include "Person.h"

class Employee : public Person {
public:
	Employee() = default;
	Employee(const Person &person);
	Employee(
			const char *a_firstName,
			const char *a_lastName,
			const char *a_personalNumber,
			long a_salary,
			int a_stationId
	);

	long salary() const;
	int stationId() const;

	void setSalary(long a_salary);
	void setStationId(int a_stationId);

	static Employee Read(int n);

private:
	long m_salary;
	int m_stationId;
};

std::ostream &operator<<(std::ostream &os, const Employee &employee);

#endif //MEJDI_2_EMPLOYEE_H
