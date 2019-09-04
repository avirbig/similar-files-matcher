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

#include <iostream>
#include <fstream>

#include "fileMover.hpp"

namespace FileMatcherProject
{

using namespace std;

void FileMover::move(string _fileName, string _oldPath, string _newPath)
{
	string oldname = _oldPath + '/' + _fileName;
	string newname = _newPath + '/' + _fileName;
	
	ifstream ifs(oldname, ios::in | ios::binary);
	ofstream ofs(newname, ios::out | ios::binary);
	ofs << ifs.rdbuf();
	remove(oldname.c_str());
}
	
}
