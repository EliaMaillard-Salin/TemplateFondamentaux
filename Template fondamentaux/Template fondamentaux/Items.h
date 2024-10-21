#pragma once
#include <iostream>

class Items
{
friend class Inventory;

public:
	Items();
	Items(const char* name, int weight);
	~Items();

	const char* GetName();
	int GetWeight();
	
	void SetName(const char* name);
	void SetWeight(int weight);
	
	int GetID();
	friend std::ostream& operator<<(std::ostream& os, Items& pItem);

private:
	int m_weight;
	const char* m_name;
	int m_IDInList;
};

std::ostream& operator<<(std::ostream& os, Items& pItem);