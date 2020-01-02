#include <iostream>
#include <cstdlib>
#include <ctime>

static const long Max = 80;
static const int LookedForCount = 1000;

static long *load(int count)
{
	srand(time(NULL));

	long *data = new long[count + 1];

	data[0] = rand() % Max;
	for(int n = 1; n < count; ++n)
		data[n] = data[n - 1] + rand() % Max;

	return data;
}

static int linearSearch(long value, long *data, int length)
{
	int n = 0;
	while(n < length && data[n] != value)
		++n;

	return n < length ? n : -1;
}

static int bumperSearch(long value, long *data, int length)
{
	data[length] = value;

	int n = 0;

	while(data[n] != value)
		++n;

	return n < length ? n : -1;
}

static int binarySearch(long value, long *data, int length)
{
	int found = 0,
			left = 0,
			right = length - 1,
			mid = 0;

	while(left <= right && !found) {
		mid = (left + right) / 2;

		if(data[mid] == value)
			found = 1;
		else if(data[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return found ? mid : -1;
}

static void search(long *data, const long *lookedFor, int count,
				   int (&searchFunction)(long, long *, int),
				   const char *searchName)
{
	clock_t startTime, endTime;

	int found = 0, notFound = 0;

	startTime = clock();

	for(int n = 0; n < LookedForCount; ++n) {
		if(searchFunction(lookedFor[n], data, count) == -1)
			++notFound;
		else
			++found;
	}

	endTime = clock();

	std::cout
			<< searchName << ": \n"
			<< "  Najdenych: " << found << "\n"
			<< "  Nenajdenych: " << notFound << "\n"
			<< "  Cas: " << ((endTime - startTime) * 1000000 / CLOCKS_PER_SEC) << " us\n\n";
}

int main()
{
	int count;

	std::cout << "Rozmer prehladavaneho pola: ";
	std::cin >> count;

	std::cout << "Pocet hladanych cisel: " << LookedForCount << "\n\n";

	long *data = load(count);

	long lookedFor[LookedForCount];
	for(int n = 0; n < LookedForCount; ++n)
		lookedFor[n] = rand() % data[count - 1];

	search(data, lookedFor, count, linearSearch, "Linearne vyhladavanie");
	search(data, lookedFor, count, bumperSearch, "Naraznikove vyhladavanie");
	search(data, lookedFor, count, binarySearch, "Binarne vyhladavanie");

	return 0;
}