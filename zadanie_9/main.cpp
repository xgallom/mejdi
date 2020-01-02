#include <iostream>
#include "List.h"

List &read(int id)
{
	List *result = new List;
	int count;

	std::cout << "Zadajte pocet prvkov zoznamu " << id << ": ";
	std::cin >> count;

	std::cout << "Zadajte prvky zoznamu " << id << ": ";
	for(int n = 0; n < count; ++n) {
		int value;
		std::cin >> value;

		result->insertEnd(value);
	}

	std::cout << "Zoznam " << id << ": ";
	result->print();

	return *result;
}

void readOrdered(List *result, int id, int count)
{
	std::cout << "Zadajte " << count << " prvkov do zoradeneho zoznamu " << id << ": ";
	for(int n = 0; n < count; ++n) {
		int value;
		std::cin >> value;

		result->insertOrdered(value);
	}

	std::cout << "Zoznam " << id << ": ";
	result->print();
}

int main()
{
	List &list1 = read(1), list2;

	readOrdered(&list2, 2, 5);
	readOrdered(&list2, 2, 3);

	int searchValue;
	std::cout << "Cislo na vyhladavanie v zozname 2: ";
	std::cin >> searchValue;
	std::cout
			<< "Pocet vyskytov cisla " << searchValue << " v zozname 2: "
			<< list2.countOf(searchValue) << "\n\n";

	List &list12 = list1 + list2;
	std::cout << "zoznam 1 + zoznam 2:\n  ";
	list12.print();

	List &list121 = list12.join(list1);
	std::cout << "(zoznam 1 + zoznam 2).join(zoznam 1):\n  ";
	list121.print();

	List &list1211o = list121.joinOrdered(list1);
	std::cout << "(zoznam 1 + zoznam 2).join(zoznam 1).joinOrdered(zoznam 1):\n  ";
	list1211o.print();

	std::cout << "(zoznam 1 + zoznam 2).join(zoznam 1).reverse():\n  ";
	list121.reverse().print();

	std::cout << "(zoznam 1 + zoznam 2).join(zoznam 1).joinOrdered(zoznam 1).reverse():\n  ";
	list1211o.reverse().print();

	return 0;
}