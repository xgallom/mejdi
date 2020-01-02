//
// Created by Revolware Company on 02/01/2020.
//

#ifndef ZADANIE_9_LIST_H
#define ZADANIE_9_LIST_H

#include "Item.h"

class List {
public:
	~List();

	Item *front() const;
	int size() const;

	void insertEnd(const Student &value);
	void insertOrdered(const Student &value);

	void removeAll();

private:
	Item
			*m_front = nullptr,
			*m_end = nullptr;
	int m_size = 0;
};

#endif //ZADANIE_9_LIST_H
