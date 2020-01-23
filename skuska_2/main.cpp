#include <iostream>
#include <fstream>
#include <string>

static const int MaxStudentsCount = 100;

struct Student {
	std::string firstName, lastName;
	int birthDate;
	int points;
	std::string address;
	int distance;
};

int read(Student **students, std::fstream &file)
{
	int count = 0;

	while(!file.eof()) {
		Student *student = students[count++] = new Student;

		file
				>> student->firstName >> student->lastName
				>> student->birthDate >> student->points
				>> student->address >> student->distance;
	}

	return count;
}

void clean(Student **students, int count)
{
	for(int n = 0; n < count; ++n)
		delete students[n];
}

int isWoman(Student *student)
{
	return student->birthDate / 100 % 100 >= 50;
}

int birthDay(Student *student)
{
	return student->birthDate % 100;
}

int birthMonth(Student *student)
{
	const int month = student->birthDate / 100 % 100;

	return month > 50 ? month - 50 : month;
}

int birthYear(Student *student)
{
	const int year = student->birthDate / 10000;

	return year < 17 ? year + 2000 : year + 1900;
}

void printDate(Student *student)
{
	std::cout << birthDay(student) << "." << birthMonth(student) << "." << birthYear(student);
}

void print(Student *student)
{
	std::cout
			<< student->lastName << " " << student->firstName
			<< " (" << student->points << ") " << student->birthDate << (isWoman(student) ? " z " : " m ");

	printDate(student);

	std::cout
			<< " " <<
			student->address << " (" << student->distance << ")\n";
}

void print(Student **students, int count)
{
	for(int n = 0; n < count; ++n)
		print(students[n]);
}

int compare(Student *left, Student *right)
{
	int dist = left->points - right->points;

	if(!dist) {
		dist = left->distance - right->distance;

		if(!dist) {
			dist = birthYear(left) - birthYear(right);

			if(!dist) {
				dist = birthMonth(left) - birthMonth(right);

				if(!dist)
					dist = birthDay(left) - birthDay(right);
			}
		}
	}

	return dist;
}

void shellSort(Student **students, int count)
{
	int jump = count;

	while(jump /= 2) {
		const int dist = count - jump;

		for(int n = 0; n < dist; ++n) {
			for(int m = n; m >= 0 && compare(students[m], students[m + jump]) < 0; m -= jump)
				std::swap(students[m], students[m + jump]);
		}
	}
}

int search(Student **students, int count, bool gender, int maxPoints, int minDistance)
{
	int result = 0;

	for(int n = 0; n < count; ++n) {
		Student *student = students[n];

		if(isWoman(student) == gender && student->points <= maxPoints && student->distance >= minDistance) {
			print(student);
			++result;
		}
	}

	return result;
}

int main()
{
	std::fstream file("studenti.txt", std::ios::in);

	if(!file.is_open()) {
		std::cout << "Nepodarilo sa otvorit subor studenti.txt na citanie\n";
		return 1;
	}

	Student *students[MaxStudentsCount];

	const int count = read(students, file);

	std::cout << "\nNeusporiadani studenti:\n";
	print(students, count);

	shellSort(students, count);

	std::cout << "\nUsporiadani studenti:\n";
	print(students, count);

	bool gender = false;
	char input;
	int maxPoints, minDistance;

	std::cout << "\nPohlavie: ";
	std::cin >> input;

	switch(input) {
		case 'z':
			gender = true;
		case 'm':
			break;

		default:
			std::cout << "Nespravne pohlavie\n";
			return 1;
	}

	std::cout << "Maximalne bodov: ";
	std::cin >> maxPoints;

	std::cout << "Minimalna vzdialenost: ";
	std::cin >> minDistance;

	std::cout << "\nNajdeni studenti:\n";
	int found = search(students, count, gender, maxPoints, minDistance);

	std::cout << "\nPocet najdenych studentov: " << found << "\n";

	clean(students, count);

	return 0;
}
