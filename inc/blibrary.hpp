 /**
 *
 * blibrary.hpp
 *
 * 02-09-2019
 * avishai cohen
 *
 * @brief:
 * @description:
 *
 **/

#ifndef _BLIB_H_
#define _BLIB_H_
 
#include <string>
#include <unordered_set> 
#include <vector>

namespace FileMatcherProject
{
	
class Blib{
public:
	void generateLib(std::string _pathToBFolder);
	int findSimilaritiesAndReturnScore(std::unordered_set<int>& _nums, int _minSimilarNumbers);
	
	#ifdef DEBUG
	void printLibrary() const;
	#endif //NDEBUG
private:
	bool areFilesSimilar(std::unordered_set<int>& _nums, std::unordered_set<int>& _bset, int _minSimilarNumbers);
private:
	std::vector<std::unordered_set<int> > m_bfiles;
};
	
}

#endif //_BLIB_H_
