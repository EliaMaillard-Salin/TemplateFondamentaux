// Template fondamentaux.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

#include "Inventory.h"
#include "Items.h"

template <typename T>
double CalculStatistiques(T arr[], int size)
{
    T somme = 0;
    for (int i = 0; i < size; i++)
    {
        somme += arr[i];
    }
    return static_cast<double>(somme) / size;
}

template <>
double CalculStatistiques(float arr[], int size) {
    double somme = 0;
    for (int i = 0; i < size; i++)
    {
        somme += arr[i];
    }
    double moyenne = static_cast<double>(somme) / size;

    double variance = 0;
    for (int i = 0; i < size; i++)
    {
        variance += (arr[i] - moyenne) * (arr[i] - moyenne);
    }
    variance /= size;
    return variance;
}


template <typename T>
T GetMinimum(T arr, int arrSize)
{
    T minimumValue = &arr[0];
    for (int i = 0; i < arrSize; i++)
    {
        if (arr[i] < *minimumValue)
            minimumValue = &arr[i];
    }
    return minimumValue;
}

template <typename T>
int Exo3_2(std::vector<T> vect, T element)
{
    vect.push_back(element);
    return vect.size();
}

template <typename T>
T Exo3_3(std::list<T> list)
{
    T sum = T();
    for (T i : list)
        sum += i;
    return sum;
}

template <typename T>
double Exo3_4(T* arr, int arrSize)
{
    T average = T();
    for (int i = 0; i < arrSize; i++)
        average += arr[i];

    return static_cast<double>(average/arrSize);
}

template < >
double Exo3_4(int* arr, int arrSize)
{
    int average = 0;
    for (int i = 0; i < arrSize; i++)
        average += arr[i];

    return static_cast<double>(average / arrSize);
}


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
    //Inventory* pInventory = new Inventory();
    //Items* Sword = new Items("Sword", 5);
    //Items* Shield = new Items("Shield", 12);
    //Items* Potion = new Items("Potion", 2);
    //Items* Helmet = new Items("Helmet", 6);
    //Items* ChestPlate = new Items("ChestPlate", 15);
    //Items* GOLD = new Items("GOLD", 80);

    //pInventory->AddItem(Shield);
    //pInventory->AddItem(Potion);
    //pInventory->AddItem(Sword);
    //pInventory->AddItem(Sword);
    //pInventory->AddItem(Helmet);
    //pInventory->AddItem(ChestPlate);
    //pInventory->AddItem(GOLD);

    //pInventory->SortByWeight(true);
    //pInventory->SortByWeight();
    //std::cout << std::endl;

    //pInventory->DeleteItemByName("Potion");

    //std::cout << std::endl;
    //pInventory->SortByName();

    //pInventory->ShowInventoryStats(5);
    //
    //pInventory->FilterBy([](Items* item)->bool { return item->GetWeight() > 5; });

    //pInventory->PrintInventory();

#pragma endregion


#pragma region Exo2
    srand(time(NULL));
    Exo2();
#pragma endregion


float aa[] = {5.65,8.25,5.2,10.0,90.65  };
std::list<float> list(10,50.555);
std::cout << Exo3_4(aa,5);




}


