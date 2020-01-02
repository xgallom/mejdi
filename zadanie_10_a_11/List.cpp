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

int List::size() const
{
	return m_size;
}

void List::insertEnd(const Student &value)
{
	if(m_end)
		m_end = Item::CreateWithPrevious(value, m_end);
	else
		m_front = m_end = Item::Create(value);

	++m_size;
}

void List::insertOrdered(const Student &value)
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
