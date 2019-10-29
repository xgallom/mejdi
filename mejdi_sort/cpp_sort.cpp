//
// Created by xgallom on 10/29/19.
//

#include <iostream>
#include <vector>
#include <random>
#include <functional>

struct Person {
	int id;
	std::string name;

	bool operator<(const Person &rhs) const { return id < rhs.id; }
};

std::ostream &operator<<(std::ostream &os, const Person &person)
{
	return os << "{ id: " << person.id << ", name: " << person.name << " }";
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &data)
{
	os << "{\n";
	for(const auto &x : data)
		os << "  " << x << "\n";
	return os << "}\n";
}

int main()
{
	const int n = 5;
	std::vector<Person> data(n);

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(1,6);

	std::generate(data.begin(), data.end(), [&rng, &dist]() {
		return Person{ int(dist(rng)), "Jozef Vajda" };
	});

	std::cout << data << "\n";

	std::sort(data.begin(), data.end());

	std::cout << data << "\n";

	return 0;
}
