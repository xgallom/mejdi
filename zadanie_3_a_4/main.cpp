#include "Employee.h"
#include <iostream>

static void addPersonalNumbers()
{
	int count;

	std::cout << "Pocet rodnych cisel: ";
	std::cin >> count;

	PersonalNumber personalNumbers[count];

	for(int n = 0; n < count; ++n) {
		personalNumbers[n] = PersonalNumber::Read(n + 1);
		std::cout << personalNumbers[n];

		std::cout << "\n";
	}

	std::cout << "\n";
}

static void addPersons()
{
	int count;

	std::cout << "Pocet osob: ";
	std::cin >> count;

	Person persons[count];

	for(int n = 0; n < count; ++n) {
		persons[n] = Person::Read(n + 1);
		std::cout << persons[n];

		std::cout << "\n";
	}

	std::cout << "\n";
}

static void addEmployees()
{
	int count;

	std::cout << "Pocet zamestnancov: ";
	std::cin >> count;

	Employee employees[count];

	for(int n = 0; n < count; ++n) {
		employees[n] = Employee::Read(n + 1);
		std::cout << employees[n];

		std::cout << "\n";
	}

	std::cout << "\n";
}

int main()
{
	addPersonalNumbers();
	addPersons();
	addEmployees();

	return 0;
}
