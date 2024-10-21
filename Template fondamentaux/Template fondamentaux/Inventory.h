#pragma once
#include <vector>
#include "Items.h"

class Inventory
{
public:

	enum Filter
	{
		heavier_than,
		lighter_than,
		weighs,
		name_start_with,
		name_end_with,
	};

	Inventory(); 
	~Inventory();

	void AddItem(Items* pItem);
	//void DeleteItem(Items* pItem);
	void DeleteItemByName(const char* name, bool destroyDuplication = false);

	Items* FindItem(Items* pItem);
	//Items* FindItemByName(const char* name);
	//Items* FindItemByWeight(int& weight );
	//Items* FindItemByID(int& ID );

	void SortByName();
	void SortByWeightAscending();
	void SortByWeightDescending();

	void PrintInventory();

	
	void FilterBy(Filter filter, int param);

private: 
	std::vector<Items*> m_itemsList;
};

bool CompareName(Items* name1, Items* name2);