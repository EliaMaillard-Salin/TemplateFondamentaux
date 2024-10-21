#include "Inventory.h"
#include <iostream>
#include <algorithm>
#include <string>

Inventory::Inventory(): m_itemsList(std::vector<Items*>()) {}

Inventory::~Inventory() {}

void Inventory::AddItem(Items* pItem)
{
	m_itemsList.push_back(pItem);
	pItem->m_IDInList = m_itemsList.size() - 1;
	std::cout << *pItem << " added to inventory" << std::endl;
}

void Inventory::DeleteItemByName(const char* name, bool destroyDuplication)
{
	for (int i = 0; i < m_itemsList.size(); i++)
	{
		if (m_itemsList[i]->GetName() == name)
		{
			std::cout << *m_itemsList[i] << " deleted. " << std::endl;
			m_itemsList.erase(m_itemsList.begin() + i);
			if (destroyDuplication == false)
				return;
		}
	}
}

Items* Inventory::FindItem(Items* pItem)
{
	std::vector<Items*>::iterator it = std::find(m_itemsList.begin(), m_itemsList.end(), pItem);
	if (it != m_itemsList.end())
		return *it;
}

bool CompareName(Items* name1, Items* name2)
{
	if (name1->GetName() == name2->GetName())
		return false;
	int index = 0;

	while ( index < ( sizeof(name1->GetName()) / sizeof(*name1->GetName()) ) && name1->GetName()[index] == name2->GetName()[index])
		index++;

	return name1->GetName()[index] < name2->GetName()[index];
}

void Inventory::SortByName()
{
	std::sort(m_itemsList.begin(), m_itemsList.end(),CompareName);
	PrintInventory();
}

void Inventory::SortByWeightAscending()
{
	for (int i = 0; i < m_itemsList.size();i++)

		for (int j = i+1; j < m_itemsList.size(); j++)
		{
			if (m_itemsList[i]->GetWeight() > m_itemsList[j]->GetWeight())
			{
				Items* save = m_itemsList[i];
				m_itemsList[i] = m_itemsList[j];
				m_itemsList[j] = save;
			}
		}
	
	PrintInventory();
}

void Inventory::SortByWeightDescending()
{
	for (int i = 0; i < m_itemsList.size(); i++)

		for (int j = i + 1; j < m_itemsList.size(); j++)
		{
			if (m_itemsList[i]->GetWeight() < m_itemsList[j]->GetWeight())
			{
				Items* save = m_itemsList[i];
				m_itemsList[i] = m_itemsList[j];
				m_itemsList[j] = save;
			}
		}

	PrintInventory();
}

void Inventory::PrintInventory()
{
	std::cout << std::endl;
	for (int i = 0; i < m_itemsList.size(); i++)
	{
		std::cout << *m_itemsList[i];
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Inventory::FilterBy(Filter filter, int param)
{
	std::cout << "FILTER : ";
	switch (filter)
	{

	case heavier_than:
		std::cout << "Heavier than " << param << std::endl;
		for (int i = 0; i < m_itemsList.size(); i++)
		{
			if (m_itemsList[i]->GetWeight() > param)
			{
				std::cout << *m_itemsList[i];
				std::cout << std::endl;
			}
		}
		break;

	case lighter_than:
		std::cout << "lighter than " << param << std::endl;
		for (int i = 0; i < m_itemsList.size(); i++)
		{
			if (m_itemsList[i]->GetWeight() < param)
			{
				std::cout << *m_itemsList[i];
				std::cout << std::endl;
			}
		}
		break;

	case weighs:
		std::cout << "weighs " << param << std::endl;
		for (int i = 0; i < m_itemsList.size(); i++)
		{
			if (m_itemsList[i]->GetWeight() == param)
			{
				std::cout << *m_itemsList[i];
				std::cout << std::endl;
			}
		}
		break;

	case name_start_with:

		std::cout << "name start with " << (char)param << std::endl;
		for (int i = 0; i < m_itemsList.size(); i++)
		{
			if (m_itemsList[i]->GetName()[0] == param)
			{
				std::cout << *m_itemsList[i];
				std::cout << std::endl;
			}
		}
		break;

	case name_end_with:

		std::cout << "name end with " << (char)param << std::endl;
		for (int i = 0; i < m_itemsList.size(); i++)
		{
			if (m_itemsList[i]->GetName()[strlen(m_itemsList[i]->GetName())-1] == param)
			{
				std::cout << *m_itemsList[i];
				std::cout << std::endl;
			}
		}

		break;

	default:
		PrintInventory();
		std::cout << "Filter Unknow";
		break;
	}

	std::cout << std::endl;
}


