#include <string>
using namespace std;
class Node
{
private:
	string movieID;
	float avgRating;
	int totalVotes;
	Node *next;
public:
	Node();
	Node(string id, float rate, int votes);
	void setMovieID(string id); 
	string getMovieID();
	void setAvgrating(float rate);
	float getAvgRating();
	void setTotalVotes(int votes);
	int getTotalVotes();
	void setNext(Node *nxt);
	Node *getNext();
};


class LinkedList
{
public:
	Node *first;
	Node *last;
	LinkedList();
	void addAtEnd(string id, float rate, int votes);
	int sizeOfList();
	void displayALL();
};
