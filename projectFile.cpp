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
	int sameRating(float );
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

int SearchEngine::sameRating(float rate)
{
	if(rate >= 1.0 && rate <=10.0)
		return chain[hashFunction(rate)].sizeOfList();
	else
		return -1;
}





//end search engine

int main()
{
	SearchEngine sEngine;
	int countOfSameRatedMovies;
	float rate;
	char choiceForFunctions;
	char choiceToExit, choiceToExit1;
	std::cout << "===========================================\n" << '\n';
	std::cout << "=========Welcome to Search Engine==========\n" << '\n';
	std::cout << "===========================================" << '\n';

	do
	{
		std::cout << "\n===========================================" << '\n';
		std::cout << "===========================================" << '\n';
		std::cout << "Enter ~1~ to Find Which Movie is Most Popular---" << '\n';
		std::cout << "Enter ~2~ to Find Which Movie is Least Popular---" << '\n';
		std::cout << "Enter ~3~ to Find How Many Movies of a certain Rating are---" << '\n';
		std::cout << "Enter Your Choice (1-3)  ===> " ;
		std::cin >> choiceForFunctions;
		if(choiceForFunctions == '1')
		{
			sEngine.mostPopularMovie();
		}
		else if(choiceForFunctions == '2')
		{
			sEngine.leastPopularMovie();
		}
		else if(choiceForFunctions == '3')
		{
			std::cout << "Enter Rating (Average Rating) for which You Want to Know Number of Movives---\n" << '\n';
			std::cin >> rate;
			countOfSameRatedMovies=sEngine.sameRating(rate);
			if(countOfSameRatedMovies == -1)
			{
				std::cout << "Rating You Entered Does Not Meet Rating Criteria\n" << '\n';
			}
			else
			{
				std::cout << "Movies of "<<rate<<" Average rate are ==> "<<countOfSameRatedMovies << '\n';

			}
		}
		else
		{
			std::cout << "Invalid Choice Entered" << '\n';
		}
		std::cout << "Do You Want To Exit--(y/n) ===> " ;
		std::cin >> choiceToExit;
		if(choiceToExit == 'y' || choiceToExit == 'Y')
		{
			break;
		}
	} while(1);
  return 0;
}

//end search engine

int main()
{
	SearchEngine obj;
	obj.leastPopularMovie();
	//obj.displayAll_movies();


  return 0;
}
