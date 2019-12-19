#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdio.h>
#include "LinkedList.h"
using namespace std;
const int number_of_chains = 100;
//search Engine
class SearchEngine{
private:

public:
  LinkedList chain[number_of_chains];
  SearchEngine ();
  void read_Data_From_File();
  int hashFunction(float);
  void displayAll_movies();
};
SearchEngine::SearchEngine()
{
}

int SearchEngine::hashFunction(float rate)
{
  return (rate*10) -1;
}

void SearchEngine::read_Data_From_File()
{
  string movie;
  float rate;
  long int votes;
  int skipFirstLine = 0;
  ifstream readingDataFile;
  readingDataFile.open("data.txt");
  if(readingDataFile.is_open())
  {
    while(!readingDataFile.eof())
    {
      if(skipFirstLine > 0)
      {
        readingDataFile >> movie;
        readingDataFile >> rate;
        readingDataFile >> votes;
        chain[hashFunction(rate)].addAtEnd(movie, rate, votes);
      }
			else
			{
				readingDataFile >>movie;
				readingDataFile >>movie;
				readingDataFile >>movie;
			}
      skipFirstLine ++;
    }
  }
}

void SearchEngine::displayAll_movies()
{
	for(int i=0; i<100;i++)
		chain[i].displayALL();
}
/* message */
//end search engine

/*void SearchEngine::read_Data_From_File()
{
  string movie;
  float rate;
  long int votes;
  int skipFirstLine = 0;
  ifstream readingDataFile;
  readingDataFile.open("data.txt");
  if(readingDataFile.is_open())
  {
    while(!readingDataFile.eof())
    {
      std::cout << "ali" << '\n';
      if(skipFirstLine > 0)
      {
        readingDataFile >> movie;
        readingDataFile >> rate;
        readingDataFile >> votes;
        chain[hashFunction(rate)].addAtEnd(movie, rate, votes);
        std::cout << "raza" << '\n';
      }
      skipFirstLine ++;
    }
  }
}*/



//end search engine

int main()
{
	SearchEngine obj;
	obj.read_Data_From_File();
	obj.displayAll_movies();


  return 0;
}
