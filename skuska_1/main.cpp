#include <iostream>

float derivaciaP(float **data, int n)
{
	int i = n - 1;

	float deltaY = 3 * data[i][1] - 4 * data[i - 1][1] + data[i - 2][1];

	return deltaY / (2 * (data[i][0] - data[i - 1][0]));
}

int main()
{
	int n;

	std::cout << "Zadajte pocet bodov: ";
	std::cin >> n;

	float **data = new float *[n];

	for(int i = 0; i < n; ++i) {
		data[i] = new float[2];

		std::cout << "Bod " << i << " vo formate \"x y\": ";
		std::cin >> data[i][0] >> data[i][1];
	}

	float derivacia = derivaciaP(data, n);

	std::cout << "\nDerivacia v pravom krajnom bode (" << (n - 1) << "): " << derivacia << "\n";

	return 0;
}
