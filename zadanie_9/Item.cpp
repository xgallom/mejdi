#include "Item.h"

int Item::value() const
{
	return m_value;
}

Item *Item::next() const
{
	return m_next;
}

void Item::setNext(Item *a_next)
{
	m_next = a_next;
}

Item *Item::Create(int a_value)
{
	return new Item(a_value);
}

Item *Item::CreateWithPrevious(int a_value, Item *a_previous)
{
	Item *result = new Item(a_value, a_previous->next());
	a_previous->setNext(result);

	return result;
}

Item *Item::CreateWithNext(int a_value, Item *a_next)
{
	return new Item(a_value, a_next);
}

Item::Item(int a_value, Item *a_next) :
	m_value{a_value},
	m_next{a_next}
{}
