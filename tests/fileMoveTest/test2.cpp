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
#include <fstream>
#include "folderScan.hpp"
#include "blibrary.hpp"
#include "csvReader.hpp"
#include "overload.hpp"
#include "fileMover.hpp"
 
using namespace FileMatcherProject;
using namespace std;
 
int main(void)
{
	string inpath("../../A");
	string condpath("../../B");
	string outpath("../../C");
	
	vector<string> vs = FolderScan(inpath).scan();
	
	Blib blib;
	blib.generateLib(condpath);
	
	string nameOfReportFile("scores.txt");
	ofstream reportFile(outpath + '/' + nameOfReportFile);
	
	for (auto file: vs)
	{
		unordered_set<int> nums = CSVReader().read(inpath + '/' + file);
		
		int score = blib.findSimilaritiesAndReturnScore(nums, 2);
		cout << "fileName: " << file << " = score: " << score << '\n';
		if(score > 0)
		{
			FileMover().move(file, inpath, outpath);
			reportFile << file << '\t' << score << '\n';
		}
	}
	
	vector<string> newvs = FolderScan(outpath).scan();
	
	cout << newvs << '\n';
	
	return 0;
}
