#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

//node class implementation
Node::Node()
{
	next =NULL;
	movieID = " ";
	avgRating =0.0;
	totalVotes = 0;
}
Node::Node(string id, float rate, int votes)
{
	movieID = id;
	avgRating = rate;
	totalVotes = votes;
	next = NULL;
}
void Node::setNext(Node* nxt)
{
	next = nxt;
}
Node* Node::getNext()
{
	return next;
}
void Node::setMovieID(string id)
{
	movieID = id;
}
string Node::getMovieID(){return movieID;}
void Node::setAvgrating(float rate){avgRating = rate;}
float Node::getAvgRating(){ return avgRating;}
void Node::setTotalVotes(int votes){totalVotes = votes;}
int Node::getTotalVotes(){return totalVotes;}

//LinkedList class implementation
LinkedList::LinkedList()
{
	first = NULL;
	last = NULL;
}
void LinkedList::addAtEnd(string id, float rate, int votes)
{
	if(first == NULL)
	{
		Node *newNode = new Node(id, rate, votes);
		first = newNode;
		last = newNode;
		//std::cout << first->getTotalVotes() << '\n';
		//std::cout << first->getMovieID() << '\n';
		//std::cout << first->getAvgRating() << '\n';
	}
	else
	{
		Node *newNode = new Node(id, rate, votes);
		last->setNext(newNode);
		last = newNode;
	}
}

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

void LinkedList::displayALL()
	{
		Node* temp = first;
		if (first != NULL)
		{
			while (temp != NULL)
			{
				std::cout << temp->getMovieID() << '\t';
				std::cout << temp->getAvgRating() << '\t';
				std::cout << temp->getTotalVotes() << '\n';
				temp = temp->getNext();
			}
		}
		else {
			cout << " No Member In the List" << endl;
		}
	}
