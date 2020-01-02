#include <iostream>
#include "List.h"

List::~List()
{
	removeAll();
}

Item *List::front() const
{
	return m_front;
}

int List::countOf(int value) const
{
	int result = 0;

	for(const Item *walk = m_front; walk; walk = walk->next()) {
		if(value == walk->value())
			++result;
	}

	return result;
}

void List::insertFront(int value)
{
	m_front = Item::CreateWithNext(value, m_front);

	if(!m_size++)
		m_end = m_front;
}

void List::insertEnd(int value)
{
	if(m_end)
		m_end = Item::CreateWithPrevious(value, m_end);
	else
		m_front = m_end = Item::Create(value);

	++m_size;
}

void List::insertOrdered(int value)
{
	if(!m_size++)
		m_front = m_end = Item::Create(value);
	else {
		Item *walk = m_front, *previous = nullptr;

		for(;;) {
			if(previous == m_end) {
				m_end = Item::CreateWithPrevious(value, m_end);
				break;
			} else if(walk->value() >= value) {
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

List &List::join(const List &b) const
{
	List *result = new List;

	for(Item *walk = front(); walk; walk = walk->next())
		result->insertEnd(walk->value());
	for(Item *walk = b.front(); walk; walk = walk->next())
		result->insertEnd(walk->value());

	return *result;
}

List &List::joinOrdered(const List &b) const
{
	List *result = new List;

	for(Item *walk = front(); walk; walk = walk->next())
		result->insertOrdered(walk->value());
	for(Item *walk = b.front(); walk; walk = walk->next())
		result->insertOrdered(walk->value());

	return *result;
}

List &List::reverse() const
{
	List *result = new List;

	for(const Item *walk = m_front; walk; walk = walk->next())
		result->insertFront(walk->value());

	return *result;
}

void List::removeFront()
{
	if(m_size) {
		Item *oldFront = m_front;
		m_front = oldFront->next();

		--m_size;

		delete oldFront;
	}
}

void List::removeAll()
{
	for(Item *walk = m_front; walk;) {
		Item *next = walk->next();
		delete walk;
		walk = next;
	}

	m_front = m_end = nullptr;
	m_size = 0;
}

void List::print() const
{
	std::cout << "List[" << m_size << "]{ ";
	for(Item *walk = m_front; walk; walk = walk->next())
		std::cout << walk->value() << " ";
	std::cout << "}\n\n";
}

List &operator+(const List &a, const List &b)
{
	return a.join(b);
}
