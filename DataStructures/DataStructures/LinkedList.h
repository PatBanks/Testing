#pragma once
class LinkedList
{
public:
	LinkedList();

	struct Node
	{
		int data = 0;

		LinkedList::Node *prevNode = nullptr;
		LinkedList::Node *nextNode = nullptr;

	};

	LinkedList::Node * head;
	LinkedList::Node * tail;
	
	int pop();
	void push(int data);
	void printList();

	int length = 0;


	~LinkedList();
};

