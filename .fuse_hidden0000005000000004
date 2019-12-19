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
	void mostPopularMovie();
	void leastPopularMovie();
};
SearchEngine::SearchEngine()
{
	read_Data_From_File();
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
	for(int i=9; i<100;i++)
		chain[i].displayALL();
}
void SearchEngine::mostPopularMovie()
{
	int maxVotes;
	Node* popularMovie;
	Node* tempMovie;
	int chain_Counter=99;
			tempMovie = chain[chain_Counter].first;
			popularMovie = tempMovie;
			while(tempMovie != NULL)
			{
				if(tempMovie->getTotalVotes() > popularMovie->getTotalVotes())
				{
					popularMovie = tempMovie;
				}
				tempMovie = tempMovie->getNext();
			}


	std::cout << "=======Most Popular Movie is=======" << '\n';
	std::cout << "Movie ID ---> "<<popularMovie->getMovieID() << '\n';
	std::cout << "Average Rating ---> "<<popularMovie->getAvgRating() << '\n';
	std::cout << "Total Votes ---> "<<popularMovie->getTotalVotes() << '\n';

}


void SearchEngine::leastPopularMovie()
{
	int maxVotes;
	Node* leastpopular;
	Node* tempMovie;
	int chain_Counter=9;
			tempMovie = chain[chain_Counter].first;
			leastpopular = tempMovie;
			while(tempMovie != NULL)
			{
				if(tempMovie->getTotalVotes() >	 leastpopular->getTotalVotes())
				{
					leastpopular = tempMovie;
				}
				tempMovie = tempMovie->getNext();
			}


	std::cout << "=======Least Popular Movie is=======" << '\n';
	std::cout << "Movie ID ---> "<<leastpopular->getMovieID() << '\n';
	std::cout << "Average Rating ---> "<<leastpopular->getAvgRating() << '\n';
	std::cout << "Total Votes ---> "<<leastpopular->getTotalVotes() << '\n';

}

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
	obj.leastPopularMovie();
	//obj.displayAll_movies();


  return 0;
}
