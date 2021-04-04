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
#include "House.h"

#ifndef _CANDYHOUSE_
#define _CANDYHOUSE_

class CandyHouse : public House
{
    public:
        /* create the prototype for the constructor based on House.cpp */
        CandyHouse(std::string Name, std::map<int, std::string> CandyRanking);

        std::string ringDoorbell(std::ostringstream &path); 

        //creating the destructor
        ~CandyHouse()
        {
            std::cout << "\nCANDYHOUSE" << std::endl;
        }
};

#endif