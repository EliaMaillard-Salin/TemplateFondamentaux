#include "Items.h"

Items::Items(): m_weight(0), m_name(" "), m_IDInList(-1) {}

Items::Items(const char* name, int weight): m_weight(weight), m_name(name), m_IDInList(-1) {}

Items::~Items() {}

const char* Items::GetName()
{
	return m_name;
}

int Items::GetWeight()
{
	return m_weight;
}

void Items::SetName(const char* name)
{
	m_name = name;
}

void Items::SetWeight(int weight)
{
	m_weight = weight;
}

int Items::GetID()
{
	return m_IDInList;
}

std::ostream& operator<<(std::ostream& os, Items& pItem)
{
	os << pItem.GetName() << " (weight : " << pItem.GetWeight() << ")";
	return os;
}
