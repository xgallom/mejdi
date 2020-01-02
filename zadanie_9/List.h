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
	int countOf(int value) const;

	void insertFront(int value);
	void insertEnd(int value);
	void insertOrdered(int value);

	List &join(const List &b) const;
	List &joinOrdered(const List &b) const;
	List &reverse() const;

	void removeFront();
	void removeAll();

	void print() const;

private:
	Item
			*m_front = nullptr,
			*m_end = nullptr;
	int m_size = 0;
};

List &operator+(const List &a, const List &b);

#endif //ZADANIE_9_LIST_H
