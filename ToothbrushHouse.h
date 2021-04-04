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

#ifndef _TOOTHBRUSHHOUSE_
#define _TOOTHBRUSHHOUSE_

class ToothbrushHouse : public House
{
    public:
        // create the prototype for the constructor based on House.cpp 
        ToothbrushHouse(std::string Name, std::map<int, std::string> CandyRanking);

        //create the prototype for ringDoorbell() based on House.cpp 
        std::string ringDoorbell(std::ostringstream &path); 

        //creating the destructor
        ~ToothbrushHouse()
        {
            std::cout << "\nTOOTHBRUSHHOUSE" << std::endl;
        }
};

#endif
