 /**
 *
 * csvReader.hpp
 *
 * 02-09-2019
 * avishai cohen
 *
 * @brief:
 * @description:
 *
 **/

#ifndef _CSVREAD_H_
#define _CSVREAD_H_
 
#include <string>
#include <unordered_set> 

namespace FileMatcherProject
{
	
class CSVReader{
public:
	std::unordered_set<int> read(std::string m_path);
};
	
}

#endif //_CSVREAD_H_
