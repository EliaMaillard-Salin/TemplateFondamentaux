#include "Inventory.h"
#include <iostream>
#include <algorithm>
#include <string>

Inventory::Inventory(): m_itemsList(std::vector<Items*>()), m_maxCapacity(100), m_totalWeight(0) {}

Inventory::Inventory(int maxCapacity): m_itemsList(std::vector<Items*>()), m_maxCapacity(maxCapacity), m_totalWeight(0) {}

Inventory::~Inventory() {}

void Inventory::AddItem(Items* pItem)
{
	if (m_totalWeight + pItem->GetWeight() > m_maxCapacity)
	{
		std::cout << *pItem << " too heavy for the inventory, max capacity is " << m_maxCapacity << " and currently total item's weight is " << m_totalWeight << std::endl;
		char force;
		std::cout << "Do you really want to add it to your inventory ? (y/n) ";
		std::cin >> force;
		switch (force)
		{
			case 'y':
				EmptyInventory(pItem);
				break;
			case 'n':
				return;
			default:
				return;
		}
	}

	m_itemsList.push_back(pItem);
	pItem->m_IDInList = m_itemsList.size() - 1;
	std::cout << *pItem << " added to inventory" << std::endl;
	m_totalWeight += pItem->GetWeight();
}

void Inventory::DeleteItemByName(const char* name, bool destroyDuplication)
{
	for (int i = 0; i < m_itemsList.size(); i++)
	{
		if (m_itemsList[i]->GetName() == name)
		{
			std::cout << *(m_itemsList[i]) << " deleted. " << std::endl;
			m_totalWeight -= m_itemsList[i]->GetWeight();
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

	while (  ( index < strlen(name1->GetName()) - 1 || index < strlen(name2->GetName()) - 1 ) && name1->GetName()[index] == name2->GetName()[index])
		index++;

	return name1->GetName()[index] < name2->GetName()[index];
}

void Inventory::SortByName()
{
	std::sort(m_itemsList.begin(), m_itemsList.end(),CompareName);
	PrintInventory();
}

void Inventory::SortByWeight(bool descending)
{
	std::sort(m_itemsList.begin(), m_itemsList.end(),
		[=](Items* pItem1, Items* pItem2)
		{
			return descending ? pItem1->GetWeight() > pItem2->GetWeight() : pItem1->GetWeight() < pItem2->GetWeight();
		}
	);
	
	PrintInventory();
}



void Inventory::PrintInventory()
{
	std::cout << std::endl;
	for (int i = 0; i < m_itemsList.size(); i++)
	{
		std::cout << *(m_itemsList[i]);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Inventory::ShowInventoryStats(int weight)
{
	std::cout << "Stats : " << std::endl;
	std::cout << " Average of items' weight in Inventory : " << CalculateAverageWeight() << std::endl;
	std::cout << " Total Inventory weight : " << CalculateTotalWeight() << std::endl;
	std::cout << " Items that weigh more than " << weight << " : " << ItemWeightMore(weight) << std::endl;
}

float Inventory::CalculateAverageWeight()
{
	float average = 0; 
	int itemCount = 0;
	for (int i = 0; i < m_itemsList.size(); i++)
	{
		average += m_itemsList[i]->GetWeight();
		itemCount += 1;
	}
	average /= itemCount;
	return average;
}

int Inventory::CalculateTotalWeight()
{
	return m_totalWeight;
}

int Inventory::ItemWeightMore(int weight)
{
	int total = 0;
	for (int i = 0; i < m_itemsList.size() ; i++)
		if (m_itemsList[i]->GetWeight() > weight)
			total += 1;
	return total;
}

void Inventory::FilterBy(std::function<bool(Items*)> filter)
{
	std::cout << std::endl;
	std::vector<Items*> filteredItems = std::vector<Items*>(m_itemsList.size());
	std::vector<Items*>::iterator it = std::copy_if(m_itemsList.begin(), m_itemsList.end(), filteredItems.begin(), filter);
	filteredItems.resize(std::distance(filteredItems.begin(), it));
	for (int i = 0; i < filteredItems.size(); i++)
	{
		std::cout << *(filteredItems[i]) << std::endl;;
	}
	std::cout << std::endl;
}

void Inventory::EmptyInventory(Items* pItem)
{
	int weightToEmpty = pItem->GetWeight();
	SortByWeight();
	for (int i = 0; i < m_itemsList.size(); i++)
	{
		weightToEmpty -= m_itemsList[i]->GetWeight();
		DeleteItemByName(m_itemsList[i]->GetName());
		if (weightToEmpty <= 0)
			return;
	}
}