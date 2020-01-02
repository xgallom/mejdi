#include "Item.h"

const Student &Item::value() const
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

Item *Item::Create(const Student &a_value)
{
	return new Item(a_value);
}

Item *Item::CreateWithPrevious(const Student &a_value, Item *a_previous)
{
	Item *result = new Item(a_value, a_previous->next());
	a_previous->setNext(result);

	return result;
}

Item *Item::CreateWithNext(const Student &a_value, Item *a_next)
{
	return new Item(a_value, a_next);
}

Item::Item(const Student &a_value, Item *a_next) :
	m_value{a_value},
	m_next{a_next}
{}
