#include <iostream>

void calculateJumps(float height, float reflection)
{
	int n = 0;

	height *= reflection;

	while(height > 1.) {
		height *= reflection;
		++n;
	}

	std::cout << "Počet odrazov: " << n << "\n";
}

void jump(float height, float reflection)
{
	const char *unit = "m";

	for(int n = 0; n <= 10; ++n) {
		if(height < 1.) {
			height *= 100.;
			unit = "cm";
		}

		std::cout << n << ": " << height << " " << unit << "\n";

		height *= reflection;
	}
}

int main()
{
	float height, reflection;

	std::cout << "Zadajte počiatočnú výšku: ";
	std::cin >> height;

	std::cout << "Zadajte počiatočnú mieru odrazu: ";
	std::cin >> reflection;

	calculateJumps(height, reflection);

	jump(height, reflection);

	return 0;
}