//Shubhayu Shrestha 1001724804

/* add the necessary includes */
#include <thread>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <mutex>
#include <chrono>
#include <iostream>


/* add an include guard named _HOUSE_  */
#ifndef _HOUSE_
#define _HOUSE_

class House
{
	public :
		/* create the prototype for the constructor based on House.cpp */
		House(std::string Name, std::map<int, std::string> CandyRanking);

		/* create the prototype for ringDoorbell() based on House.cpp */
		virtual std::string ringDoorbell(std::ostringstream &path) = 0; 

		//creating the destructor
		virtual ~House()
		{
			std::cout << "\nHOUSE" << std::endl; 
		}
		
	protected :
		std::string houseName;
		/* declare a mutex named door */
		std::mutex door;
		/* declare a map named CandyRankingMap of type int,string */
		std::map<int, std::string> CandyRankingMap;
};

#endif