#include <iostream>

struct Point {
	double x, y;
};

double slope(const Point *points, int count, int i)
{
	double deltaY;
	const double step = points[1].x - points[0].x;

	if(!i)
		deltaY = -3 * points[0].y + 4 * points[1].y - points[2].y;
	else if(i == count - 1)
		deltaY = 3 * points[i].y - 4 * points[i - 1].y - points[i - 2].y;
	else
		deltaY = points[i + 1].y - points[i - 1].y;

	return deltaY / (2 * step);
}

int main()
{
	int count;

	std::cout << "Zadajte pocet bodov funkcie: ";
	std::cin >> count;

	Point *points = new Point[count];

	std::cout << "\nZadajte " << count << " hodnot x a y funkcie:\n";
	for(int n = 0; n < count; ++n)
		std::cin >> points[n].x >> points[n].y;

	int i;

	std::cout << "\nVlozte index bodu, v ktorom vypocitat derivaciu: ";
	std::cin >> i;

	std::cout
			<< "\nDerivacia funkcie v indexe " << i << " je: "
			<< slope(points, count, i) << "\n";

	delete[] points;

	return 0;
}