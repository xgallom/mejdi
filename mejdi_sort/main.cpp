#include <iostream>
#include <cstdlib>
#include <ctime>

void sort(int *data, int n)
{
	for(int sortedEnd = 1; sortedEnd < n; ++sortedEnd) {
		int sortedCurrent = sortedEnd;
		int current = data[sortedCurrent];

		for(; sortedCurrent > 0 && data[sortedCurrent - 1] > current; --sortedCurrent)
			data[sortedCurrent] = data[sortedCurrent - 1];

		data[sortedCurrent] = current;
	}
}

void print(int *data, int n)
{
	while(n--)
		std::cout << *data++ << " ";
	std::cout << "\n\n";
}

void fillRandom(int *data, int n)
{
	while(n--)
		*data++ = rand();
}

int main()
{
	const int n = 5;
	int data[n] = {3, 8, 2, 4, 1};

	srand(time(NULL));

	//fillRandom(data, n);

	print(data, n);

	sort(data, n);

	print(data, n);

	return 0;
}
