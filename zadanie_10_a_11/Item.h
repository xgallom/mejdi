#ifndef ZADANIE_9_ITEM_H
#define ZADANIE_9_ITEM_H

#include "Student.h"

class Item {
public:
	const Student &value() const;
	Item *next() const;

	void setNext(Item *a_next);

	static Item *Create(const Student &a_value);
	static Item *CreateWithPrevious(const Student &a_value, Item *a_previous);
	static Item *CreateWithNext(const Student &a_value, Item *a_next);

private:
	Item(const Student &a_value, Item *a_next = nullptr);

	Student m_value;
	Item *m_next;
};

#endif //ZADANIE_9_ITEM_H
