#include <iostream>
#include <cstring>

#define STRING_LENGTH 30
#define MAX_ZOO 3

class Zoo {
public:

	Zoo(const char *a_miesto, const char *a_zviera, int a_cisloZvierata, long a_hodnotaZvierata);

	const char *miesto() const;
	const char *zviera() const;
	int cislo() const;
	long hodnota() const;

private:
	char
		m_miesto[STRING_LENGTH],
		m_zviera[STRING_LENGTH];
	int m_cisloZvierata;
	long m_hodnotaZvierata;
};

Zoo::Zoo(const char *a_miesto, const char *a_zviera, int a_cisloZvierata, long a_hodnotaZvierata)
{
	strncpy(m_miesto, a_miesto, STRING_LENGTH);
	strncpy(m_zviera, a_zviera, STRING_LENGTH);
	m_cisloZvierata = a_cisloZvierata;
	m_hodnotaZvierata = a_hodnotaZvierata;
}

const char *Zoo::miesto() const
{
	return m_miesto;
}

const char *Zoo::zviera() const
{
	return m_zviera;
}

int Zoo::cislo() const
{
	return m_cisloZvierata;
}

long Zoo::hodnota() const
{
	return m_hodnotaZvierata;
}

std::ostream &operator<<(std::ostream &os, const Zoo &zoo)
{
	os << "Miesto zoo: " << zoo.miesto() << "\n";
	os << "Druh zvierata: " << zoo.zviera() << "\n";
	os << "Cislo zvierata: " << zoo.cislo() << "\n";
	os << "Spolocenska hodnota zvierata [eur]: " << zoo.hodnota() << "\n";

	return os;
}

int main()
{
	int count;
	Zoo *zvierata[MAX_ZOO + 1]; // +1 kvoli predvytvorenemu slonovi


	std::cout << "Pocet zvierat[1 - " << MAX_ZOO << "]: ";
	std::cin >> count;
	std::cout << "\n";

	if(count == 0 || count > MAX_ZOO) {
		std::cout << "Nevhodny pocet zvierat\n";
		return 1;
	}


	zvierata[0] = new Zoo("Bojnice", "Slon", 1002, 11000);

	for(int i = 1; i < count + 1; ++i) {
		char miesto[STRING_LENGTH], zviera[STRING_LENGTH];
		int cislo;
		long hodnota;

		std::cout << "Miesto kde zviera[" << i << "] zije: ";
		std::cin >> miesto;

		std::cout << "Druh zvierata[" << i << "]: ";
		std::cin >> zviera;

		std::cout << "Cislo zvierata[" << i << "]: ";
		std::cin >> cislo;

		std::cout << "Spolocenska hodnota zvierata[" << i << "] [eur]: ";
		std::cin >> hodnota;
		std::cout << "\n";

		zvierata[i] = new Zoo(miesto, zviera, cislo, hodnota);
	}


	std::cout << "Predvytvoreny slon:\n\n" << *zvierata[0] << "\n";

	std::cout << "Zadane zvierata:\n\n";
	for(int i = 1; i < count + 1; ++i)
		std::cout << *zvierata[i] << "\n";


	long kolektivnaHodnota = 0;

	for(int i = 0; i < count + 1; ++i)
		kolektivnaHodnota += zvierata[i]->hodnota();

	std::cout << "Kolektivna spolocenska hodnota vsetkych zvierat [eur]: " << kolektivnaHodnota << "\n";
}


