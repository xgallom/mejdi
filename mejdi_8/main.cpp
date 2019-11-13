#include <iostream>
#include <cmath>

// Maximum pre nahodnu generaciu
#define MaxReal 9
#define MaxImag 18

// Struktura komplexnych cisel
struct Complex {
	int real, imag;

	// Absolutna hodnota komplexneho cisla
	double abs() const { return sqrt(real * real + imag * imag); }

	// Nastavenie komplexneho cisla na nahodnu hodnotu
	void setRandom()
	{
		real = 1 + (rand() % MaxReal);
		imag = 1 + (rand() % MaxImag);
	}
};

// Porovna dve komplexne cisla a vrati:
//   -1 ak l < r
//   0  ak l == r
//   1  ak l > r
int compare(const Complex *l, const Complex *r)
{
	const double labs = l->abs(), rabs = r->abs();

	if(labs > rabs)
		return 1;
	else if(labs < rabs)
		return -1;
	else
		return 0;
}

// Pretypovanie pre kniznicnu funkciu qsort
int compare(const void *l, const void *r)
{
	return compare(*(const Complex **) l, *(const Complex **) r);
}

// Nasa implementacia funkcie quick sort
void quickSort(Complex **data, int left, int right)
{
	if(left >= right)
		return;

	int i = left, j = right, m = (left + right) / 2;
	Complex *p = data[m];

	do {
		while(compare(p, data[i]) > 0)
			++i;

		while(compare(data[j], p) > 0)
			--j;

		if(i <= j)
			std::swap(data[i++], data[j--]);
	} while(i <= j);

	quickSort(data, left, j);
	quickSort(data, i, right);
}

// Kontrola zoradenosti pola komplexnych cisel
bool check(Complex **data, int n)
{
	for(int i = 0; i < n - 1; ++i)
		if(compare(data[i], data[i + 1]) > 0)
			return false;

	return true;
}

// Kontrola zhodnosti dvoch poli komplexnych cisel
bool check(Complex **data1, Complex **data2, int n)
{
	for(int i = 0; i < n; ++i)
		if(compare(data1[i], data2[i]) > 0)
			return false;

	return true;
}

// Vypise pole komplexnych cisel
void print(Complex **data, int n)
{
	for(int i = 0; i < n; ++i)
		std::cout << "  " << data[i]->real << " + " << data[i]->imag << "i (" << data[i]->abs() << ")\n";
}

int main()
{
	int n;

	// Nacitanie poctu prvkov
	std::cout << "Zadaj pocet prvkov: ";
	std::cin >> n;
	std::cout << "\n";

	// Vytvorenie poli ukazovatelov na komplexne cisla
	Complex **data1 = new Complex *[n];
	Complex **data2 = new Complex *[n];

	// Nastavenie seedovacej hodnoty generatora nahodnych cisel
	srand(time(nullptr));

	// Naplnenie pola nahodnymi komplexnymi cislami
	for(int i = 0; i < n; ++i) {
		data1[i] = new Complex;

		data1[i]->setRandom();
		data2[i] = data1[i];
	}

	// Vypisanie poli
	std::cout << "data1:\n";
	print(data1, n);

	std::cout << "data2:\n";
	print(data2, n);

	// Zoradenie pola 1
	{
		const clock_t startTime = clock();

		quickSort(data1, 0, n - 1);

		const clock_t endTime = clock();

		bool isValid = check(data1, n);

		std::cout
				<< "Usporiadanie pomocou vlastnej funkcie quickSort:\n"
				<< "  cas: " << ((endTime - startTime) * 1e6 / CLOCKS_PER_SEC) << " us\n"
				<< "  spravne: " << isValid << "\n"
				<< "\n";
	}

	// Zoradenie pola 2
	{
		const clock_t startTime = clock();

		std::qsort(data2, n, sizeof(Complex *), compare);

		const clock_t endTime = clock();

		bool isValid = check(data2, n);

		std::cout
				<< "Usporiadanie pomocou kniznicnej funkcie qsort:\n"
				<< "  cas: " << ((endTime - startTime) * 1e6 / CLOCKS_PER_SEC) << " us\n"
				<< "  spravne: " << isValid << "\n"
				<< "\n";
	}

	// Kontrola zhody poli
	std::cout << "Zhoda medzi prvkami data1 a data2: " << check(data1, data2, n) << "\n\n";

	// Vypis zoradenych poli
	std::cout << "usporiadane data1:\n";
	print(data1, n);

	std::cout << "usporiadane data2:\n";
	print(data2, n);

	return 0;
}
