#include <iostream>

class Item {
public:
	int value() const { return m_value; }

	Item *next() const { return m_next; }

	void setNext(Item *a_next) { m_next = a_next; }

	static Item *Create(int a_value) { return new Item(a_value); }
	static Item *CreateWithNext(int a_value, Item *a_next) { return new Item(a_value, a_next); }
	static Item *CreateWithPrevious(int a_value, Item *a_previous)
	{
		Item *result = new Item(a_value, a_previous->next());
		a_previous->setNext(result);

		return result;
	}

private:
	Item(int a_value, Item *a_next = NULL) :
			m_value(a_value),
			m_next(a_next) {}

	int m_value;
	Item *m_next;
};

class List {
public:
	List() : m_front(NULL), m_end(NULL), m_size(0) {}
	~List() { removeAll(); }

	int countOf(int minValue, int maxValue) const
	{
		int result = 0;

		for(const Item *walk = m_front; walk; walk = walk->next()) {
			int value = walk->value();
			if(value >= minValue && value <= maxValue)
				++result;
		}

		return result;
	}

	void insertOrdered(int value)
	{
		if(!m_size++)
			m_front = m_end = Item::Create(value);
		else {
			Item *walk = m_front, *previous = NULL;

			for(;;) {
				if(previous == m_end) {
					m_end = Item::CreateWithPrevious(value, m_end);
					break;
				}
				else if(walk->value() >= value) {
					if(previous)
						Item::CreateWithPrevious(value, previous);
					else
						m_front = Item::CreateWithNext(value, m_front);
					break;
				}

				previous = walk;
				walk = walk->next();
			}
		}
	}

	void reverse()
	{
		Item *prev = NULL, *walk = m_front;

		while(walk) {
			Item *next = walk->next();

			walk->setNext(prev);

			prev = walk;
			walk = next;
		}

		std::swap(m_front, m_end);
	}

	void print() const
	{
		std::cout << "List[" << m_size << "]{ ";
		for(Item *walk = m_front; walk; walk = walk->next())
			std::cout << walk->value() << " ";
		std::cout << "}\n\n";
	}

	void printValuesIn(int minValue, int maxValue) const
	{
		std::cout << "{ ";
		for(Item *walk = m_front; walk; walk = walk->next()) {
			int value = walk->value();
			if(value >= minValue && value <= maxValue)
				std::cout << value << " ";
		}
		std::cout << "}\n\n";
	}

	void removeAll()
	{
		for(Item *walk = m_front; walk;) {
			Item *next = walk->next();
			delete walk;
			walk = next;
		}

		m_front = m_end = NULL;
		m_size = 0;
	}

private:
	Item
			*m_front,
			*m_end;
	int m_size;
};

List &read()
{
	List *result = new List;
	int count;

	std::cout << "Zadajte pocet prvkov zoznamu: ";
	std::cin >> count;

	std::cout << "Zadajte prvky zoznamu: ";
	for(int n = 0; n < count; ++n) {
		int value;
		std::cin >> value;

		result->insertOrdered(value);
	}

	std::cout << "Usporiadane vlozeny zoznam: ";
	result->print();

	return *result;
}

int main()
{
	List &list = read();

	int minValue, maxValue;
	for(;;) {
		std::cout << "Interval hodnot \"min max\", vlozte -1000 1000 pre ukoncenie: ";
		std::cin >> minValue >> maxValue;

		if(minValue == -1000 && maxValue == 1000)
			break;

		std::cout << "List<" << minValue << "," << maxValue << ">[" << list.countOf(minValue, maxValue) << "]";
		list.printValuesIn(minValue, maxValue);
	};

	list.reverse();
	std::cout << "\nReverzny zoznam list1: ";
	list.print();

	return 0;
}
