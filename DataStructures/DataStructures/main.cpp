// DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>
#include <string>


void swap(int & a, int & b)
{
	std::cout << "Pre Swap: List Element i: " << a << "List Element j: " << b << std::endl;

	int temp = a;
	a = b;
	b = temp;

	std::cout << "Post Swap: List Element i: " << a << "List Element j: " << b << std::endl;
}

void partition_rand(int list[], int lo, int hi)
{

	int pivot = list[(rand() % (hi-lo))+lo];
	
	std::string input = "0";

	std::cout << "Pivot: " << pivot << std::endl;
	std::cin >> input;

	//print the list out for debugging

	for (int k = 0; k < sizeof(list); k++)
	{
		std::cout << list[k] << std::endl;
	}

	//start the partitioning

	while (lo < hi)
	{
		while ((list[lo] < pivot) && lo < hi)
		{
			lo++;
			std::cout << "Incrementing start" << std::endl;
		}
		while ((list[hi] > pivot) && lo < hi)
		{
			hi--;
			std::cout << "Decrementing end" << std::endl;
		}
		if ((list[lo] > pivot) && (list[hi] <= pivot) && lo < hi)
		{
			swap(list[lo], list[hi]);
		}
	}


	partition_rand(list, 0, lo);
	partition_rand(list, lo + 1, sizeof(list) - hi - 1);

	return;
}

void quicksort(int list[], int lo, int hi)
{
	for (int i = lo; i <= hi; i++)
	{
		std::cout << list[i] << std::endl;
	}

	std::cout << "Entering Paritioning... " << std::endl;
	std::cout << lo << "\n" << hi << std::endl;

	partition_rand(list, lo, hi);

}

int main()
{ 
	int choice = 0;
	int lo = 0;
	int size = 20;
	int hi = size - 1;
	int array[20];
	
	std::string exit = "no";
	
	for (int j = 0; j < size; j++)
	{
		array[j] = rand() % 100;
	}

	for (int i = 0; i <= hi; i++)
	{
		std::cout << i << ":     " << array[i] << std::endl;
	}

	std::cout << lo << std::endl;
	std::cout << hi << std::endl;


	quicksort(array, lo, hi);

	/*
	while (exit == "no")
	{
		std::cout << "Pick which Data Structure you would like to use: \n 1. Linked List \n 2. Quicksort " << std::endl;
		std::cin >> choice;
		if (choice == 1)
		{
			LinkedList NewList;

			while (exit == "no")
			{

				std::cout << "Pick an Option: \n 1. Add \n 2. Pop \n 3. Exit " << std::endl;
				std::cin >> choice;

				if (choice == 3)
				{
					choice = 1;
					exit = "yes";
				}

				if (choice == 2)
				{
					int data = NewList.pop();
					std::cout << "Yout just popped: " << data << std::endl;
				}
				
				while (choice == 1)
				{
					std::cout << "What number would you like to add?" << std::endl;
					std::cin >> choice;

					NewList.push(choice);
					NewList.printList();

					std::cout << "Press 2 to exit, 1 to add more." << std::endl;
					std::cin >> choice;
				}
			}

		}
	}
	
*/
	getchar();

    return 0;
}
