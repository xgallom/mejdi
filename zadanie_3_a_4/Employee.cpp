//
// Created by Revolware Company on 01/01/2020.
//

#include "Employee.h"

Employee::Employee(const Person &person) : Person(person)
{}

Employee::Employee(
		const char *a_firstName,
		const char *a_lastName,
		const char *a_personalNumber,
		long a_salary,
		int a_stationId
) : Person(a_firstName, a_lastName, a_personalNumber), m_salary{a_salary}, m_stationId{a_stationId} {}

long Employee::salary() const
{
	return m_salary;
}

int Employee::stationId() const
{
	return m_stationId;
}

void Employee::setSalary(long a_salary)
{
	m_salary = a_salary;
}

void Employee::setStationId(int a_stationId)
{
	m_stationId = a_stationId;
}

Employee Employee::Read(int n)
{
	Employee result(Person::Read(n));

	long salary;

	std::cout << "Zadajte mzdu " << n << ". zamestnanca: ";
	std::cin >> salary;

	result.setSalary(salary);

	int stationId;

	std::cout << "Zadajte cislo prevadzky " << n << ". zamestnanca: ";
	std::cin >> stationId;

	result.setStationId(stationId);

	return result;
}

std::ostream &operator<<(std::ostream &os, const Employee &employee)
{
	return os
			<< static_cast<const Person &>(employee)
			<< "Vyplata: " << employee.salary() << "\n"
			<< "Cislo Prevadzky: " << employee.stationId() << "\n";
}