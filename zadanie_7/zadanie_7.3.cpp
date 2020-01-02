#include <fstream>
#include <iostream>

static const int MaxNameLength = 16, MaxAddressLength = 31;

struct Person {
	long date;
	char firstName[MaxNameLength],
			lastName[MaxNameLength],
			address[MaxAddressLength + 1];
};

int read(Person **persons, std::fstream &file)
{
	int count = 0;

	while(!file.eof()) {
		persons[count] = new Person;

		file
				>> persons[count]->date
				>> persons[count]->firstName
				>> persons[count]->lastName;

		file.getline(persons[count]->address, MaxAddressLength);
		++count;
	}

	return count - 1;
}

long compare(const Person *left, const Person *right)
{
	int result;

	if((result = strcmp(left->lastName, right->lastName)))
		return result;

	if((result = strcmp(left->firstName, right->firstName)))
		return result;

	return left->date - right->date;
}

void insertionSort(const Person **persons, int count)
{
	for(int n = 1; n < count; ++n) {
		const Person *key = persons[n];

		int m = n - 1;

		while(m >= 0 && compare(persons[m], key) > 0) {
			persons[m + 1] = persons[m];
			--m;
		}

		persons[m + 1] = key;
	}
}

void print(const Person *person)
{
	std::cout << person->date << " " << person->firstName << " " << person->lastName << person->address << "\n";
}

int main()
{
	std::fstream file("pacienti.txt", std::ios::in);

	if(!file.is_open()) {
		std::cout << "Nepodarilo sa otvorit subor pacienti.txt\n";
		return 1;
	}

	Person *persons[1000];

	const int count = read(persons, file);

	std::cout
			<< "V zozname " << (2 <= count && count <= 4 ? "su " : "je ") << count
			<< " vysetrenia nasledovnych pacientov:\n";

	insertionSort(const_cast<const Person **>(persons), count);

	for(int n = 0; n < count; ++n)
		print(persons[n]);

	return 0;
}
