#include <iostream>
#include <fstream>
#include "List.h"
#include "Student.h"

void read(List *result, std::fstream &file)
{
	bool skip = true;
	Student previousStudent = {};

	while(!file.eof()) {
		Student student = {};

		file
				>> student.firstName >> student.lastName >> student.grade
				>> student.dateOfBirth.day >> student.dateOfBirth.month
				>> student.dateOfBirth.year;

		if(skip)
			skip = false;
		else
			result->insertOrdered(previousStudent);

		previousStudent = student;
	}
}

void print(const Student &student)
{
	std::cout
			<< student.lastName << " " << student.firstName << "\t("
			<< student.grade << ") " << student.dateOfBirth.day << "."
			<< student.dateOfBirth.month << "." << student.dateOfBirth.year
			<< "\n";
}

void print(const List &list)
{
	for(const Item *walk = list.front(); walk; walk = walk->next())
		print(walk->value());
	std::cout << "\n";
}

void searchBy(const List &list, const char (Student::*criteria)[Student::MaxNameLength])
{
	char key[Student::MaxNameLength];
	int count = 0;

	std::cout << "\nZadajte hladany kluc: ";
	std::cin >> key;

	std::cout << "\nNajdeni studenti:\n";
	for(const Item *walk = list.front(); walk; walk = walk->next()) {
		const Student &student = walk->value();

		if(!strcmp(key, student.*criteria)) {
			print(student);
			++count;
		}
	}
	std::cout << "\nPocet najdenych studentov: " << count << "\n";
}

int main()
{
	std::fstream file("prvaci.txt", std::ios::in);

	if(!file.is_open()) {
		std::cout << "Nepodarilo sa otvorit subor \"prvaci.txt\"\n";
		return 1;
	}

	List list;

	read(&list, file);

	std::cout << "Pocet studentov: " << list.size() << "\n\n";

	std::cout << "Zoznam studentov:\n";
	print(list);

	int choice;
	std::cout << "Podla coho vyhladavat?\n [0] Meno\n [1] Priezvisko\n$ ";
	std::cin >> choice;

	switch(choice) {
		case 0:
			searchBy(list, &Student::firstName);
			break;

		case 1:
			searchBy(list, &Student::lastName);
			break;

		default:
			std::cout << "Nespravna volba\n";
			return 2;
	}

	return 0;
}