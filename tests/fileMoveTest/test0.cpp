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
#include "overload.hpp"
#include "fileMover.hpp"
 
using namespace FileMatcherProject;
using namespace std;
 
int main(void)
{
	//string oldpath("../../A");
	//string newpath("../../C");
	string oldpath("../../C");
	string newpath("../../A");
	
	vector<string> vs = FolderScan(oldpath).scan();
	
	cout << vs << '\n';
	
	for (auto file: vs)
	{
		FileMover().move(file, oldpath, newpath);
	}
	
	vector<string> newvs = FolderScan(newpath).scan();
	
	cout << newvs << '\n';
	
	return 0;
}
