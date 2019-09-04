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
#include "blibrary.hpp"
#include "overload.hpp"
 
using namespace FileMatcherProject;
using namespace std;
 
int main(void)
{
	Blib blib;
	
	blib.generateLib("../../B");
	
	blib.printLibrary();
	
	return 0;
}
