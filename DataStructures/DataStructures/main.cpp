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

void partition_rand(int list[], int start, int end)
{

	int pivot = list[(rand() % (end-start))+start];
	
	std::string input = "0";

	std::cout << "Pivot: " << pivot << std::endl;
	std::cin >> input;

	//print the list out for debugging

	for (int k = 0; k < sizeof(list); k++)
	{
		std::cout << list[k] << std::endl;
	}

	//start the partitioning

	while (start < end)
	{
		while ((list[start] < pivot) && start < end)
		{
			start++;
			std::cout << "Incrementing start" << std::endl;
		}
		while ((list[end] > pivot) && start < end)
		{
			end--;
			std::cout << "Decrementing end" << std::endl;
		}
		if ((list[start] > pivot) && (list[end] <= pivot) && start < end)
		{
			swap(list[start], list[end]);
		}
	}


	partition_rand(list, 0, start);
	partition_rand(list, start + 1, sizeof(list) - end - 1);
}

void quicksort(int list[], int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		std::cout << list[i] << std::endl;
	}

	std::cout << "Entering Paritioning... " << std::endl;
	std::cout << start << "\n" << end << std::endl;

	partition_rand(list, start, end);

}

int main()
{ 
	int choice;

	std::string exit = "no";
	

	/*
	LinkedList New;

	for (int i = 0; i < 100; i++)
	{
		New.push(rand() % 100);
	}
	New.printList();

	*/
	int array[20];
	int start = 0;
	int end = sizeof(array) - 1;

	for (int i = 0; i <= end; i++)
	{
		array[i] = rand() % 100;
	}
	
	std::cout << start << " \n" << end << std::endl;

	quicksort(array, start, end);

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
