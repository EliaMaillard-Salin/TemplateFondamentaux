// Template fondamentaux.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

#include "Inventory.h"
#include "Items.h"


int main()
{

#pragma region EXO1
    //std::vector<int> vect;
    //std::list<int> list;
    //std::set<int> set;

    //// Init
    //vect = {5,2,9,1,5,6};
    //list = {5,2,9,1,5,6};
    //set = {5,2,9,1,5,6};

    //// Add
    //int element;
    //std::cout << "Choose int to add : ";
    //std::cin >> element; std::cout  << std::endl;
    //vect.push_back(element);
    //list.push_back(element);
    //set.insert(element);

    //// Remove
    //std::vector<int>::iterator it = std::find(vect.begin(), vect.end(), 6);
    //if (it != vect.end())
    //    vect.erase(it); 
    //list.remove(6);
    //set.erase(6);

    //// Sort

    //list.sort();
    ////for (int i = 0; i < vect.size();i++)
    ////    for (int j = i+1; j < vect.size(); j++)
    ////    {
    ////        if (vect[i] > vect[j])
    ////        {
    ////            int save = vect[i];
    ////            vect[i] = vect[j];
    ////            vect[j] = save;
    ////        }
    ////    }
    //
    //std::sort(vect.begin(), vect.end());



    ////Print
    //for (int i = 0; i < vect.size(); i++)
    //    std::cout << vect[i] << " ";
    //std::cout << std::endl;
    //
    //for (int i : list)
    //    std::cout << i << " ";
    //std::cout << std::endl;

    //for (int i : set)
    //    std::cout << i  << " ";
    //std::cout << std::endl;

#pragma endregion


#pragma region EXO1BIS
    Inventory* pInventory = new Inventory();
    Items* Sword = new Items("Sword", 5);
    Items* Shield = new Items("Shield", 12);
    Items* Potion = new Items("Potion", 2);
    Items* Helmet = new Items("Helmet", 6);
    Items* ChestPlate = new Items("ChestPlate", 15);

    pInventory->AddItem(Shield);
    pInventory->AddItem(Potion);
    pInventory->AddItem(Sword);
    pInventory->AddItem(Sword);
    pInventory->AddItem(Helmet);
    pInventory->AddItem(ChestPlate);

    pInventory->SortByWeightAscending();
    std::cout << std::endl;

    pInventory->DeleteItemByName("Potion");

    std::cout << std::endl;
    pInventory->SortByName();

    pInventory->FilterBy(Inventory::heavier_than, 5);
    pInventory->FilterBy(Inventory::lighter_than, 7);
    pInventory->FilterBy(Inventory::weighs, 15);
    pInventory->FilterBy(Inventory::name_start_with, 'S');
    pInventory->FilterBy(Inventory::name_end_with, 'e');

#pragma endregion

}


