#pragma once
#include <vector>
#include <functional>
#include "Items.h"

class Inventory
{
public:

	Inventory();
	Inventory(int maxCapacity);
	~Inventory();

	void AddItem(Items* pItem);
	//void DeleteItem(Items* pItem);
	void DeleteItemByName(const char* name, bool destroyDuplication = false);

	Items* FindItem(Items* pItem);
	//Items* FindItemByName(const char* name);
	//Items* FindItemByWeight(int& weight );
	//Items* FindItemByID(int& ID );

	void SortByName();
	void SortByWeight(bool descending = false);

	void PrintInventory();

	void FilterBy(std::function<bool(Items*)> filter);

	void ShowInventoryStats(int weight = 0);

private:
	float CalculateAverageWeight();
	int CalculateTotalWeight();
	int ItemWeightMore(int weight);
	void EmptyInventory(Items* pItem);

private: 
	std::vector<Items*> m_itemsList;
	int m_maxCapacity;
	int m_totalWeight;
};

bool CompareName(Items* name1, Items* name2);