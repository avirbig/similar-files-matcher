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
#include "csvReader.hpp"
#include "overload.hpp"
 
using namespace FileMatcherProject;
using namespace std;
 
int main(void)
{
	CSVReader csvr;
	
	unordered_set<int> vals = csvr.read("sample.csv");
	
	cout << vals << endl;
	
	return 0;
}
