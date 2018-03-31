// DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>
#include <string>

int main()
{ 
	int choice;
	int choice1;
	int choice2;
	int choice3;
	int choice4;

	std::string exit = "no";
	
	/*
	LinkedList New;

	for (int i = 0; i < 100; i++)
	{
		New.push(rand() % 100);
	}
	New.printList();

	*/
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
	
	
	getchar();

    return 0;
}

