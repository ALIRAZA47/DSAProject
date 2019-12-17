using namespace std;
class Node {
private:
	string movieID;
	int numOFVotes;
	float avgRating;
	Node* next;
public:
	Node ();
	Node(string, float, int);
	 void setMovieID(string);
 	 string getMovieID();
	 void setAvgRating(float);
 	 float getAvgRating();
	 void setNumOfVotes(int);
 	 int getNumOfVotes();
 	 void setNext(Node*);
 	 Node* getNext();
};
class LinkedList
{
public:
	LinkedList ();

	 Node* first;
	 void displayALL();
	 void addAtEnd(string, float, int);
	 int sizeOfList();
	 //void remove(int);
	 //int findValue(int);

};
