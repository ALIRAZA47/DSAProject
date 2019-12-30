/*
		Header file which contains declaration of linked list data type
*/
#include <string>
using namespace std;
//declaration of Node class
class Node
{
private:
	string movieID; 		//stores name of movie
	float avgRating;		//stores average rating of movie
	int totalVotes;			//stores total number of votes of movie
	Node *next;					// stores the address of next movie object
public:
	Node();		//node class constructor
	Node(string id, float rate, int votes);		//parameterized constructor to construct a movie object with all attribtes
	void setMovieID(string id);		//function to set movie ID or name
	string getMovieID();		//function t oget movie ID or Name
	void setAvgrating(float rate);	//function to set average rating of a movie
	float getAvgRating();		//function to get average rating of movie
	void setTotalVotes(int votes);		//function to set votes of a movie
	int getTotalVotes();		//function to get votes of a movie
	void setNext(Node *nxt); 		//function to set next movie to another movie
	Node *getNext(); 		//function to get next movie to another movie
};

//declaration of linkedlist class
class LinkedList
{
public:
	Node *first;		//points to first movie
	Node *last;			//points to last movie
	LinkedList();		//linkedlist constructor
	void addAtEnd(string id, float rate, int votes);		//function to add movie at End of a list
	int sizeOfList();		//get size of a list
	void displayALL();		//print movies of a list
};
