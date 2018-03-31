#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>


LinkedList::LinkedList()
{
	this->head = nullptr;
	this->tail = nullptr;

}

int LinkedList::pop()
{
	LinkedList::Node * tempNode = new LinkedList::Node;
	int tmp = this->head->data;
	
	if ((this->head == nullptr) && (this->tail == nullptr))
	{
		std::cout << "You have no items in your list" << std::endl;
		return 0;

	}

	if (this->head->prevNode == nullptr)
	{
		std::cout << tmp << " is the last entry in your list." << std::endl;

		this->head = nullptr;
		this->tail = nullptr;

		return tmp;
		
	}

	tempNode->nextNode = this->head->nextNode;
	tempNode->prevNode = this->head->prevNode;
	
	this->head = this->head->prevNode;
	this->head->nextNode = nullptr;

	delete tempNode;
	
	this->length--;

	return tmp;
}

void LinkedList::push(int data)
{
	LinkedList::Node * _newNode = new LinkedList::Node;

	if (this->head == nullptr)
	{
		this->head = _newNode;
		this->tail = _newNode;
		this->head->prevNode = nullptr;

	}
	else
	{
		_newNode->prevNode = this->head;

	}

	_newNode->nextNode = nullptr;
	this->head = _newNode;
	_newNode->data = data;

	this->length++;
}

void LinkedList::printList()
{
	LinkedList::Node * tempNode = this->head;
	for (int i = this->length; i > 0; i--)
	{
		std::cout << i << ": " << tempNode->data << std::endl;
		tempNode = tempNode->prevNode;
	}
}

LinkedList::~LinkedList()
{
}
