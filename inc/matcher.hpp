 /**
 *
 * matcher.hpp
 *
 * 02-09-2019
 * avishai cohen
 *
 * @brief:
 * @description:
 *
 **/

#ifndef _MATCHER_H_
#define _MATCHER_H_
 
#include <vector> 
#include <string>
#include <thread>
#include <mutex>
#include <unordered_set>
#include <fstream>
#include "blibrary.hpp"


namespace FileMatcherProject
{
	
class Matcher{
public:
	Matcher(std::string inpath, std::string condpath, std::string outpath, int _minSimilarNumbers);
	void startMatching(void);
private:
	void run(void);
private:
	std::string m_inpath;
	std::string m_condpath;
	std::string m_outpath;
	int m_minSimilarNumbers;
	bool m_running;
	std::ofstream m_scoresFile;
	Blib m_blib;
	std::vector<std::string> m_filesToMatch;
	std::vector<std::thread> m_workers;
	std::mutex m_mutex;
};

}

#endif //_MATCHER_H_
