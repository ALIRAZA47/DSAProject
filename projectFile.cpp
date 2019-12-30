/*
*The aim of this project is to make a small search engine
*This project is IMDb based search Engine a small IMDb ;)
/ ****************AIMS and objectives*************** /
*to search for most popular movie
*to search for least popular movie
*to search for those movies having same rating
/ *****************Group Members************* /
*** Mahnoor Awan ***
*** Hamdan Ali Baloch ***
*** Ali Raza Khan ***
*/

//  Main File of Project  \\ //
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdio.h>
#include "LinkedList.h"
using namespace std;
const int number_of_chains = 100;  //total number of Chians in seperate chaining

// Search Engine class Definition
class SearchEngine{
private:

public:
  LinkedList chain[number_of_chains];
  SearchEngine ();    //constructor
  void read_Data_From_File();   //function to read data from file
  int hashFunction(float);    //function to hash data
  void displayAll_movies();   //funcion to display data of movies
	void mostPopularMovie();   //function to find Most Popular Movie
	void leastPopularMovie();    //function to find the least popular movie
	int sameRating(float );    //function to find number of sane rated movies
};

//defiunition of Search Engine class
SearchEngine::SearchEngine()
{
	read_Data_From_File();     //function call to read data from file containing data of movies
}

int SearchEngine::hashFunction(float rate)
{
  return (rate*10) -1;    //returns index AvgRating * 10 subtracting 1
}

//reading data from file
void SearchEngine::read_Data_From_File()
{
  string movie;   //local variable containing movie name
  float rate;   //local variable containing movie rating
  long int votes;   //local variable containing number of votes
  int skipFirstLine = 0;    //counter t oskip first line while data file
  ifstream readingDataFile;   //object to stream a file ALSO counter for total number of movies
  readingDataFile.open("data.txt");
  if(readingDataFile.is_open())
  {
    while(!readingDataFile.eof())   //read file till the end of file
    {
      if(skipFirstLine > 0)
      {
        readingDataFile >> movie;
        readingDataFile >> rate;
        readingDataFile >> votes;
        chain[hashFunction(rate)].addAtEnd(movie, rate, votes);   //adding movie in specific chain
      }
			else
			{
        //catch first line as a junk line
				readingDataFile >> movie;
				readingDataFile >> movie;
				readingDataFile >> movie;
			}
      skipFirstLine ++;   //increamenting the counter for countng
    }
  }
}

//***********************************************//
//implementaion of display function
void SearchEngine::displayAll_movies()
{
	for(int i=9; i<100;i++)    //loop to print all movies data
		chain[i].displayALL();  //call to function of linkedList or list
}

//implementaion of most popular movie function
void SearchEngine::mostPopularMovie()
{
	int maxVotes;  //dummy variable which cointains maximum votes
	Node* popularMovie;  //pointer pointing most popular movie
	Node* tempMovie;   //temporary pointer
	int chain_Counter=99;    //selecting highest rated movie
	tempMovie = chain[chain_Counter].first;    //temporary pointer now pointing to chain of highest rate
  popularMovie = tempMovie;
	while(tempMovie != NULL)   //loop to find movie containing max number of votes
	{
		if(tempMovie->getTotalVotes() > popularMovie->getTotalVotes())
			{
				popularMovie = tempMovie;
			}
		tempMovie = tempMovie->getNext();   //traversing the list ot find max votes
	}


	std::cout << "=======Most Popular Movie is=======" << '\n';
	std::cout << "Movie ID ---> "<<popularMovie->getMovieID() << '\n';
	std::cout << "Average Rating ---> "<<popularMovie->getAvgRating() << '\n';
	std::cout << "Total Votes ---> "<<popularMovie->getTotalVotes() << '\n';

}

//implementaion of least popular movie function
void SearchEngine::leastPopularMovie()
{
	int maxVotes;  //dummy variable containing max votes
	Node* leastpopular;  //pointer poining towards leat popular movie
	Node* tempMovie;   //temporary pointer
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

//implementaion of same rating function
int SearchEngine::sameRating(float rate)
{
  if(rate >= 1.0 && rate <=10.0)   //checks whether rating match the  criteria of rating
		return chain[hashFunction(rate)].sizeOfList();    //return number of same  rated movies
	else
		return -1;    //return -1 if rating does not match criteria of rating
}

//***********************************************//
//end search engine

int main()
{
	SearchEngine sEngine;
	int countOfSameRatedMovies;
	float rate;
	char choiceForFunctions;
	char choiceToExit, choiceToExit1;
	std::cout << "===========================================||\n" << '\n';
	std::cout << "=========Welcome to Search Engine==========||\n" << '\n';
	std::cout << "===========================================" << '\n';

	do
	{
		std::cout << "\n===========================================" << '\n';
		std::cout << "Enter ~1~ to Find Which Movie is Most Popular---" << '\n';
		std::cout << "Enter ~2~ to Find Which Movie is Least Popular---" << '\n';
		std::cout << "Enter ~3~ to Find How Many Movies of a certain Rating are---" << '\n';
		std::cout << "Enter Your Choice (1-3)  ===> " ;
		std::cin >> choiceForFunctions;
		if(choiceForFunctions == '1')
		{
      std::cout << "\n===========================================" << '\n';
      std::cout << "*******************************************\n" << '\n';
      sEngine.mostPopularMovie();
      std::cout << "\n*******************************************" << '\n';
      std::cout << "===========================================" << '\n';
		}
		else if(choiceForFunctions == '2')
		{
      std::cout << "\n===========================================" << '\n';
      std::cout << "*******************************************\n" << '\n';
			sEngine.leastPopularMovie();
      std::cout << "\n*******************************************" << '\n';
      std::cout << "===========================================" << '\n';
		}
		else if(choiceForFunctions == '3')
		{
      std::cout << "\n===========================================" << '\n';
      std::cout << "*******************************************\n" << '\n';
			std::cout << "Enter Rating (Average Rating) for which You Want to Know Number of Movives---->>  ";
			std::cin >> rate;
      std::cout << "\n" << '\n';
			countOfSameRatedMovies=sEngine.sameRating(rate);
			if(countOfSameRatedMovies == -1)
			{
				std::cout << "Rating You Entered Does Not Meet Rating Criteria\n" << '\n';
			}
			else
			{
				std::cout << "Movies of "<<rate<<" Average rate are ==> "<<countOfSameRatedMovies << '\n';

			}
      std::cout << "\n*******************************************" << '\n';
      std::cout << "===========================================" << '\n';
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
