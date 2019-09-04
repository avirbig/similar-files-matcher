 /**
 *
 * blibrary.cpp
 *
 * 02-09-2019
 * avishai cohen
 *
 * @brief: scan folder for files
 * @description:
 *
 **/

#include "csvReader.hpp"
#include "folderScan.hpp"
#include "blibrary.hpp"
#include "overload.hpp"
#include <iostream>


namespace FileMatcherProject
{

using namespace std;

void Blib::generateLib(string _pathToBFolder)
{
	FolderScan filseFromBFolder(_pathToBFolder);
	vector<string> ListOfFilesToRead(filseFromBFolder.scan());
	
	for (auto filePath: ListOfFilesToRead)
	{
		m_bfiles.push_back(CSVReader().read(_pathToBFolder + '/' + filePath));
	}
}

bool Blib::areFilesSimilar(unordered_set<int>& _nums, unordered_set<int>& _bset, int _minSimilarNumbers)
{
	int count = 0;
	
	for (auto numFromA: _nums)
	{
		if(_bset.find(numFromA) != _bset.end())
		{
			++count;
			if(count == _minSimilarNumbers) return true;
		}
	}
	
	return false;
}

int Blib::findSimilaritiesAndReturnScore(unordered_set<int>& _nums, int _minSimilarNumbers)
{
	int score = 0;
	
	for (auto bset: m_bfiles)
	{
		if(areFilesSimilar(_nums, bset, _minSimilarNumbers))
		{
			++score;
		}
	}
	
	return score;
}
	
#ifdef DEBUG

void Blib::printLibrary() const
{
	cout << m_bfiles;
	cout << '\n';

}
#endif //NDEBUG	
	
}
