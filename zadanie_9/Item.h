#ifndef ZADANIE_9_ITEM_H
#define ZADANIE_9_ITEM_H

class Item {
public:
	int value() const;
	Item *next() const;

	void setNext(Item *a_next);

	static Item *Create(int a_value);
	static Item *CreateWithPrevious(int a_value, Item *a_previous);
	static Item *CreateWithNext(int a_value, Item *a_next);

private:
	Item(int a_value, Item *a_next = nullptr);

	int m_value;
	Item *m_next;
};

#endif //ZADANIE_9_ITEM_H
