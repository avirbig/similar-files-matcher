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
#include "matcher.hpp"
 
using namespace FileMatcherProject;
using namespace std;
 
int main(void)
{
	string inpath("../../A");
	string condpath("../../B");
	string outpath("../../C");
	int minSimilarNumbers = -13;
	
	try
	{
		Matcher m(inpath,condpath,outpath,minSimilarNumbers);
		m.startMatching();
	}
	catch (invalid_argument& e)
	{
		cerr << e.what() << '\n';
		return -1;
	}
	
	return 0;
}
