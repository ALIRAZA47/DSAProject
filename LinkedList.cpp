#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;
Node::Node()
	{
		movieID = " ";
		avgRating = 0.0;
		numOFVotes = 0;
		next = NULL;
	}
Node::Node(string id, float rate, int votes)
	{
		movieID = id;
		avgRating = rate;
		numOFVotes = votes;
		next = NULL;
	}
	void setMovieID(string str) {movieID = str;}
	string getMovieID() { return movieID; }
	void setAvgRating(float rate) { avgRating = rate; }
	float getAvgRating() { return avgRating; }
	void setNumOfVotes(int votes) { numOFVotes = votes; }
	int getNumOfVotes() { return numOFVotes; }
	void Node::setNext(Node* ptr) { next = ptr; }
	Node* Node::getNext() { return next; }

	// Linked list class constructor--------------------
	LinkedList::LinkedList()
	{
		first = NULL;
	}
	//end constructor-----------------

		//function of displaying data of the list----------------------------------
	void LinkedList::displayALL()
	{
		Node* temp = first;
		if (first != NULL)
		{


			while (temp != NULL)
			{
				std::cout << temp->getMovieID() << '\t';
				std::cout << temp->getAvgRating() << '\t';
				std::cout << temp->getNumOfVotes() << '\n';
				temp = temp->getNext();
			}
		}
		else {
			cout << " No Member In the List" << endl;
		}
	}
	//end of displayALL() function-------------------------------------

	//start of addAtEnd() function---------------------------------
	void LinkedList::addAtEnd(string id, float rate, int votes)
	{
		if (first == NULL)
		{
			Node *firstNODE = new Node(id, rate, votes);
			first = firstNODE;
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

/*-------Remove by VALUE-------*/
/*
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
*/
