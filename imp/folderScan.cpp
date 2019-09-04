 /**
 *
 * folderScan.cpp
 *
 * 02-09-2019
 * avishai cohen
 *
 * @brief: scan folder for files
 * @description:
 *
 **/


#include <folderScan.hpp>
#include <boost/filesystem.hpp>
#include <iostream>

namespace FileMatcherProject
{

using namespace std;
using namespace boost::filesystem;

FolderScan::FolderScan(string _path)
: m_path(_path)
{
}

vector<string> FolderScan::scan()
{
	vector<string> filesInFolder;
	
	for (auto i = directory_iterator(m_path); i != directory_iterator(); ++i)
	{
		if (!is_directory(i->path()))
		{
			filesInFolder.push_back(i->path().filename().string());
			//filesInFolder.push_back(m_path + '/' + i->path().filename().string());
		}
	}
	
	return filesInFolder;
}
	
}
