#include <iostream>

static const int Size = 20, Max = 80, Min = 1;

void fill(int *data, int count)
{
	std::cout << "Zrebovane cisla: ";
	for(int n = 0; n < count; ++n) {
		data[n] = rand() % Max + Min;
		std::cout << data[n] << " ";
	}
	std::cout << "\n";
}

void selectionSort(int *data, int count)
{
	for(int n = 0; n < count - 1; ++n) {
		int min = n;

		for(int m = n + 1; m < count; ++m) {
			if(data[m] < data[min])
				min = m;
		}

		std::swap(data[min], data[n]);
	}
}

bool checkSorted(const int *data, int count)
{
	bool isSorted = true;

	std::cout << "Zoradene cisla: ";
	for(int n = 1; n < count; ++n) {
		if(data[n - 1] > data[n])
			isSorted = false;

		std::cout << data[n] << " ";
	}
	std::cout << "\n";

	return isSorted;
}

bool findDuplicates(int *data, int count)
{
	selectionSort(data, count);

	if(!checkSorted(data, count)) {
		std::cout << "Zoradenie zlyhalo\n";
		return false;
	}

	for(int n = 1; n < count; ++n) {
		if(data[n - 1] == data[n])
			return true;
	}

	return false;
}

int main()
{
	srand(time(NULL));

	int data[Size];
	fill(data, Size);

	while(findDuplicates(data, Size)) {
		std::cout << "V zrebovanych cislach su duplikaty, zrebujem znovu.\n\n";
		fill(data, Size);
	}

	return 0;
}