//Shubhayu Shrestha 1001724804
/* Add the needed includes */
#include "TrickOrTreater.h"
#include "House.h"
#include "CandyHouse.h"
#include "ToothbrushHouse.h"
#include <cstring>
#include <fstream>
#include <sstream>

using namespace std;

void get_command_line_params(int argc, char *argv[], string &TOTfile, string &Housefile, string &Candyfile) 
{
	int i;
	std::string cla;
	int candyfilefound = 0, housefilefound = 0, totfilefound = 0;

	for (i = 1; i < argc; i++)
	{
		cla = argv[i];

		if (cla.substr(0, cla.find("=")) == "TOTINPUT")
		{
			TOTfile = cla.substr(cla.find("=") + 1, cla.length());
			totfilefound = 1;
		}
		else if (cla.substr(0, cla.find("=")) == "HOUSEINPUT")
		{
			Housefile = cla.substr(cla.find("=") + 1, cla.length());
			housefilefound = 1;
		}
		else if (cla.substr(0, cla.find("=")) == "CANDYINPUT")
		{
			Candyfile = cla.substr(cla.find("=") + 1, cla.length());
			candyfilefound = 1;
		}
	}

	if (!(candyfilefound && housefilefound && totfilefound))
	{
		throw invalid_argument("\nMissing command line parameters - Usage : TOTINPUT=  HOUSEINPUT=  CANDYINPUT=  \n");
		exit(0); 
	}

}

int main(int argc, char *argv[])
{
	string TOTFilename, HouseFilename, CandyFilename;

	/* create a map named CandyRankingMap of type int,string */
	string CandyLine;
	char CandyLineA[50] = {};
	string CandyName;
	int CandyRanking;
	char *CandyPtr = NULL;
	map<int, string>CandyRankingMap; 

	/* create a vector named Houses of type pointers to House */
	string HouseLine;
	vector<House*> Houses; 

	/* create a vector named TOTs of type TrickOrTreater */
	string TotLine;
	vector<TrickOrTreater> TOTs;

	/* declare an ostringstream named HouseHeading */
	ostringstream HouseHeading; 
	
	srand(time(NULL));
	
	/* create a try-catch block for function get_command_line_params */
	try
	{
		get_command_line_params(argc, argv, TOTFilename, HouseFilename, CandyFilename);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
		exit(0);
	}
	/* open all three files from command line for reading - use TOTFH, HouseFH and CandyFH */
	ifstream CandyFH{CandyFilename};
	ifstream HouseFH{HouseFilename};
	ifstream TOTFH{TOTFilename};

	/* make getline read from CandyFH into CandyLine */
	while (getline(CandyFH, CandyLine))
	{
		strcpy(CandyLineA, CandyLine.c_str());
		CandyPtr = strtok(CandyLineA, "|");
		CandyName = CandyPtr;
		CandyPtr = strtok(NULL, "|");
		CandyRanking = atoi(CandyPtr);
		/* call insert() and make_pair() with CandyRanking and CandyName */
		CandyRankingMap.insert(make_pair(CandyRanking, CandyName)); 
	}

	/* Close the Candy file - CandyFH */
	CandyFH.close(); 

	HouseHeading << "          ";
	
	int houseType; 

	while (getline(HouseFH, HouseLine))
	{
		houseType = rand() %2; 

		if(houseType == 0)
		{
			//candyHouse
			Houses.push_back(new CandyHouse(HouseLine, CandyRankingMap));
		}
		else
		{
			//toothbrushHouse
			Houses.push_back(new ToothbrushHouse(HouseLine, CandyRankingMap));
		}
		

		/* in one line - use new to allocate a House object that is constructed by    */
		/* passing HouseLine and CandyRankingMap and push_back the object into Houses */
		

		HouseHeading << HouseLine;
		for (int i = 0; i < 11 - HouseLine.length(); i++)
			HouseHeading << " ";
	}

	HouseHeading << endl << endl;
	/* Close the House file - HouseFH */
	HouseFH.close(); 


	/* Create all of the Trick or Treaters */
	while (getline(TOTFH, TotLine))
	{
		TOTs.push_back(TrickOrTreater{TotLine, Houses});
	}
	
	/* Close the TOT file - TOTFH */
	TOTFH.close(); 
	
	/* Start all of the trick or treaters using a range based for loop over vector TOT */	
	/* call function startThread() for each iterator for each pass through the loop */
	for(auto& it : TOTs)
	{
		it.startThread(); 
	}

	while (TrickOrTreater::ImDone != TOTs.size() ) 
	{
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout << HouseHeading.str();


        for (auto& it : TOTs) 
		{
			cout << it.getPath() << it.getName() << endl;
        }
		/* put this_thread to sleep for 5 milliseconds */
		this_thread::sleep_for(chrono::milliseconds(5)); 
    }	
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout << HouseHeading.str();
	
	/* range based for loop over TOTs */ 
	for (auto &it : TOTs)
	{
		cout << it.getPath() << it.getName() << endl;
	}
	
	/* range based for loop over TOTs */
	for (auto &it : TOTs)
	{
		cout << it; 
	}
	
	/* range based for loop over TOTs */
	for (auto &it : TOTs)
	{
		it.joinThread();
	}

	/* range based for loop over Houses */
	for (auto &it : Houses)
	{
		delete it;
	}
	
	return 0;
}
