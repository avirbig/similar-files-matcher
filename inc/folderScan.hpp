 /**
 *
 * folderScan.hpp
 *
 * 02-09-2019
 * avishai cohen
 *
 * @brief:
 * @description:
 *
 **/

#ifndef _FOLDERSCAN_H_
#define _FOLDERSCAN_H_
 
#include <vector> 
#include <string>

namespace FileMatcherProject
{
	
class FolderScan{
public:
	FolderScan(std::string _pathToFolder);
	std::vector<std::string> scan();
private:
	const std::string m_path;
};
	
}

#endif //_FOLDERSCAN_H_
