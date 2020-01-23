#include <iostream>
#include <fstream>

static const int MaxNameLength = 64, MaxStudentsCount = 100, BirthDateLength = 7;

struct Student {
	char firstName[MaxNameLength], lastName[MaxNameLength];
	char birthDate[BirthDateLength];
	int points;
	char address[MaxNameLength];
	int distance;
};

int search(const Student *students, int length,
		   bool (&searchFunction)(const Student &, const char *),
		   const char *value)
{
	int n = 0;

	while(n < length && !searchFunction(students[n], value))
		++n;

	return n < length ? n : -1;
}

bool searchFirstName(const Student &student, const char *value)
{
	return strcmp(student.firstName, value) == 0;
}

bool searchLastName(const Student &student, const char *value)
{
	return strcmp(student.lastName, value) == 0;
}

bool searchGrade(const Student &student, const char *value)
{
	return student.grade == value[0];
}

float averageGrade(const Student *students, int count)
{
	float sum = 0.;

	for(int n = 0; n < count; ++n)
		sum += students[n].grade - 'A' + 1.;

	return sum / count;
}

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
	return student->birthDate[2] - '0' >= 5;
}

void print(Student *student)
{
	std::cout
			<< student->firstName << " " << student->lastName
			<< ", nar. " << student->birthDate << ", bodov " << student->points << ", v "
			<< student->address << ", vo vzdial. " << student->distance << " je " <<
			(isWoman(student) ? "zena" : "muz") << "\n";
}

//void printAboveAverage(const Student *students, int count)
//{
//	const float average = averageGrade(students, count);
//
//	std::cout << "Zoznam studentov s nadpriemernou znamkou:\n";
//
//	for(int n = 0; n < count; ++n) {
//		if(students[n].grade - 'A' + 1 < average)
//			print(students[n]);
//	}
//
//	std::cout << "\n";
//}
//
//void searchAndPrint(const Student *students, int count,
//					bool (&searchFunction)(const Student &, const char *))
//{
//	char input[MaxNameLength];
//
//	std::cin >> input;
//	int n = search(students, count, searchFunction, input);
//
//	if(n == -1)
//		std::cout << "Student sa nenasiel\n";
//	else {
//		std::cout << "Student sa nasiel: " << n << " - ";
//		print(students[n]);
//	}
//
//	std::cout << "\n";
//}
//
//void printStudentsWithGrade(const Student *students, int count, const char *grade)
//{
//	for(int n = 0; n < count; ++n) {
//		if(searchGrade(students[n], grade))
//			print(students[n]);
//	}
//
//	std::cout << "\n";
//}

int main()
{
	std::fstream file("studenti.txt", std::ios::in);

	if(!file.is_open()) {
		std::cout << "Nepodarilo sa otvorit subor studenti.txt na citanie\n";
		return 1;
	}

	Student *students[MaxStudentsCount];

	const int count = read(students, file);

	for(int n = 0; n < count; ++n) {
		std::cout << "Student " << n << ": ";
		print(students[n]);
	}

//	printAboveAverage(students, count);
//
//	char input[MaxNameLength];
//	std::cout << "Zoznam studentov so znamkou: ";
//	std::cin >> input;
//	printStudentsWithGrade(students, count, input);
//
//	std::cout << "Hladana znamka: ";
//	searchAndPrint(students, count, searchGrade);
//
//	std::cout << "Hladane krstne meno: ";
//	searchAndPrint(students, count, searchFirstName);

	clean(students, count);

	return 0;
}
