 /**
 *
 * test0.cpp
 *
 * 02-09-2019
 * avishai cohen
 *
 * @brief:
 * @description:
 *
 **/

#include <iostream>
#include "folderScan.hpp"
#include "blibrary.hpp"
#include "csvReader.hpp"
#include "overload.hpp"
 
using namespace FileMatcherProject;
using namespace std;
 
int main(void)
{
	Blib blib;
	
	blib.generateLib("../../B");
	
	unordered_set<int> nums = CSVReader().read("../../A/1.csv");
	
	int score = blib.findSimilaritiesAndReturnScore(nums, 10);
	
	cout << score << endl;
	
	return 0;
}
