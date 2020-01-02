#include <iostream>

static const int
		MaxKeyLength = 100,
		MaxTextLength = 1000;

void read(char *key, char **found, char **notFound, int &foundLength, int &notFoundLength)
{
	std::cout << "Hladane slovo: ";
	std::cin.getline(key, MaxKeyLength);

	std::cout << "\nText:\n";

	for(;;) {
		char line[MaxTextLength + 1];
		int lineLength = 0;

		std::cin.getline(line, MaxTextLength);
		lineLength = strlen(line);

		if(!lineLength)
			break;

		char **destination = strstr(line, key) ? found + foundLength++ : notFound + notFoundLength++;

		*destination = new char[MaxTextLength + 1];
		strcpy(*destination, line);
	}
}

void print(char *key, char **lines, int linesLength)
{
	for(int n = 0; n < linesLength; ++n) {
		std::cout << lines[n] << "\n";
		delete[] lines[n];
	}

	std::cout << "\n";
}

int main()
{
	char key[MaxKeyLength + 1], *found[MaxTextLength], *notFound[MaxTextLength];
	int foundLength = 0, notFoundLength = 0;

	read(key, found, notFound, foundLength, notFoundLength);

	std::cout << "Riadky s najdenym slovom \"" << key << "\" (" << foundLength << "):\n";
	print(key, found, foundLength);

	std::cout << "Riadky s nenajdenym slovom \"" << key << "\" (" << notFoundLength << "):\n";
	print(key, notFound, notFoundLength);

	return 0;
}