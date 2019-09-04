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
	
	vector<string> filesInA = FolderScan("../../A").scan();
	
	for (auto file: filesInA)
	{
		unordered_set<int> nums = CSVReader().read("../../A/"+ file);
		int score = blib.findSimilaritiesAndReturnScore(nums, 2);
		cout << "fileName: " << file << " = score: " << score << '\n';
	}
	
	return 0;
}
