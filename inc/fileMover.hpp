 /**
 *
 * fileMover.hpp
 *
 * 02-09-2019
 * avishai cohen
 *
 * @brief:
 * @description:
 *
 **/

#ifndef _FILEMOVER_H_
#define _FILEMOVER_H_
 
#include <string>

namespace FileMatcherProject
{
	
class FileMover{
public:
	void move(std::string _fileName, std::string _oldPath, std::string _newPath);
};
	
}

#endif //_FILEMOVER_H_
