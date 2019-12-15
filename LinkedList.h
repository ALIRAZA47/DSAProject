class Node {
private:
	int data;
	Node* next;
public:
	Node ();
	Node(int);
	 void setData(int);
 	int getData();
 	void setNext(Node*);
 	Node* getNext();
};
class LinkedList
{
public:
	LinkedList ();

	 Node* first;
	 void addAtStart(int);
	 void displayALL();
	 void addAtEnd(int);
	 void deleteAtStart();
	 void deleteAtEnd();
	 int sizeOfList();
	 void removeAtIndex(int, int);
	 void remove(int);
	 int getAtIndex(int, int);
	 int findValue(int);

};
