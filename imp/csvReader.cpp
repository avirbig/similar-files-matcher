 /**
 *
 * csvReader.cpp
 *
 * 02-09-2019
 * avishai cohen
 *
 * @brief: scan folder for files
 * @description:
 *
 **/

#include <iostream>
#include <fstream>
#include <sstream>
#include "csvReader.hpp"

namespace FileMatcherProject
{

using namespace std;

unordered_set<int> CSVReader::read(string _path)
{
	unordered_set<int> allNums;
	fstream fio(_path);
	string line;
	int tempNumber;
	
	while(fio)
	{
		getline(fio, line, ',');
		stringstream ss(line);
		ss >> tempNumber;
		allNums.emplace(tempNumber);
	}
	
	return allNums;
}
	
}
