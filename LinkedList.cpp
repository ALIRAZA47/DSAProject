#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;
Node::Node()
	{
		data = 0;
		next = NULL;
	}
Node::Node(int d)
	{
		data = d;
		next = NULL;
	}
	void Node::setData(int d) { data = d; }
	int Node::getData() { return data; }
	void Node::setNext(Node* ptr) { next = ptr; }
	Node* Node::getNext() { return next; }

	// Linked list class constructor--------------------
	LinkedList::LinkedList()
	{
		first = NULL;
	}
	//end constructor-----------------

	//start of addAtStart function-------------------------------
	void LinkedList::addAtStart(int x)
	{
		Node* temp = new Node();
		temp->setData(x);
		Node* aariz = first;
		first = temp;
		temp->setNext(aariz);
	}
	//end of addAtStart function------------------------------------

	//function of displaying data of the list----------------------------------
	void LinkedList::displayALL()
	{
		Node* temp = first;
		if (first != NULL)
		{


			while (temp != NULL)
			{
				std::cout << temp->getData() << '\n';
				temp = temp->getNext();
			}
		}
		else {
			cout << " No Member In the List" << endl;
		}
	}
	//end of displayALL() function-------------------------------------

	//start of addAtEnd() function---------------------------------
	void LinkedList::addAtEnd(int x)
	{
		if (first == NULL)
		{
			addAtStart(x);
		}
		else
		{

			Node* temp = new Node();
			temp->setData(x);
			Node* aariz = first;
			while (aariz->getNext() != NULL)
			{
				aariz = aariz->getNext();
			}
			aariz->setNext(temp);
		}

	}
	//end of addAtEnd() function-------------------------------

	//start of deleteAtStart() function-------------------------
	void LinkedList::deleteAtStart()
	{
		if (first != NULL) {
			first = first->getNext();
		}
		else {
			cout << "No Member in the List" << endl;
		}
	}
	//end  of deleteAtStart function--------------------------

	//start of  deleteAtEnd function--------------------------
	void LinkedList::deleteAtEnd()
	{
		if (first == NULL)
		{
			cout << "NO Memeber in the List" << endl;
		}
		else {
			Node* aariz = first;
			while (aariz->getNext()->getNext() != NULL)
			{
				aariz = aariz->getNext();
			}
			aariz->setNext(NULL);
		}
	}
	//end of deleteAtEnd function----------------------------

	//start of size of list function----------------------------
	int LinkedList::sizeOfList()
	{
		Node* temp = first;
		int counter = 0;
		if (first != NULL)
		{
			while (temp->getNext() != NULL)
			{
				temp = temp->getNext();
				counter++;
			}
			return ++counter;
		}
		else
			return 0;
	}
	//end of  sizeOfList() function----------------------

	//start of removeAtIndex() function-------------------------
	void LinkedList::removeAtIndex(int ind, int sizeofLIst)
	{
		Node* temp = first;
		int i = 0;
		Node* temp2;
		if (first != NULL)
		{
			if (ind == 0)
			{
				deleteAtStart();
			}
			else if (ind <= sizeofLIst && ind >= 0)
			{
				while (i < ind)
				{
					temp2 = temp;
					temp = temp->getNext();
					i++;
				}
				temp2->setNext(temp->getNext());
			}
			else
			{
				std::cout << "----Index does not exist----" << '\n';
			}
		}
		else {
			std::cout << "List is empty" << '\n';
		}
	}
	//END OF removeAtIndex( ) function-------------------------

	//start of remove function--------------------------
	void LinkedList::remove(int  x)
	{
		Node* temp = first;
		Node* temp2 = NULL;
		int checker = 0;
		if (first->getData() == x)
		{
			first = first->getNext();
			return;
		}
		while (temp != NULL)
		{
			if (temp->getData() == x)
			{
				checker++;
				break;
			}
			temp2 = temp;
			temp = temp->getNext();
		}
		if (checker == 0)
		{
			std::cout << "Value Not Found in the list" << '\n';
		}
		else
			temp2->setNext(temp->getNext());

	}
	//end of remove function--------------------------

	//start of getAtIndex()  function------------------------
	int LinkedList::getAtIndex(int ind, int sizeofLIst)
	{
		Node* temp = first;
		int i = 0;
		if (first != NULL)
		{
			if (ind <= sizeofLIst && ind >= 0)
			{
				while (i < ind)
				{
					temp = temp->getNext();
					i++;
				}
				int val = temp->getData();
				return val;
			}
		}
		if (first == NULL)
		{
			std::cout << "List is Empty" << '\n';
		}
		return -1;
	}
	//end of getAtIndex function------------------------------

	//start of  find a value function-------------------------
	int LinkedList::findValue(int val)
	{
		Node* temp = first;
		int i = 0;
		int  checker = 0;
		int ali;
		std::cout << temp->getData() << '\n';
		while (temp->getNext() != NULL)
		{
			ali = temp->getData();
			if (ali == val)
			{
				checker = i;
				return checker;
				break;
			}
			temp = temp->getNext();
			i++;
		}
		checker = -1;
		return checker;
	}
	//end  of find a value function---------------------------
