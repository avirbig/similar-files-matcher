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
 
using namespace FileMatcherProject;
using namespace std;
 
int main(void)
{
	FolderScan fs(".");
	
	vector<string> vs = fs.scan();
	
	cout << vs << endl;
	
	return 0;
}
