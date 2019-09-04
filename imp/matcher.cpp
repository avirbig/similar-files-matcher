 /**
 *
 * matcher.cpp
 *
 * 02-09-2019
 * avishai cohen
 *
 * @brief: scan folder for files
 * @description:
 *
 **/
 
 
#include <stdexcept>
#include <iostream>
#include "folderScan.hpp"
#include "fileMover.hpp"
#include "matcher.hpp"
#include "csvReader.hpp"

using namespace std;

namespace FileMatcherProject
{

Matcher::Matcher(string _inpath, string _condpath, string _outpath, int _minSimilarNumbers)
: m_inpath(_inpath)
, m_condpath(_condpath)
, m_outpath(_outpath)
, m_minSimilarNumbers(_minSimilarNumbers)
, m_running(true)
, m_scoresFile(_outpath + "/scores.txt")
, m_filesToMatch(FolderScan(_inpath).scan())
{
	if(_minSimilarNumbers < 0)
	{
		throw invalid_argument("invalid similiarity condition");
	}
	
	m_blib.generateLib(_condpath);
}

void Matcher::startMatching(void)
{
	int numOfthreads = thread::hardware_concurrency();
	for (int i = 0; i < numOfthreads; ++i)
	{
		m_workers.emplace_back(thread(&Matcher::run,this));
	}
	
	for (int i = 0; i < numOfthreads; ++i)
	{
		m_workers[i].join();
	}
}

void Matcher::run(void)
{
	while(m_running)
	{
		m_mutex.lock();
			if(m_filesToMatch.empty())
			{
				m_running = false;
				m_mutex.unlock();
				return;
			}
			string file(m_filesToMatch.back());
			m_filesToMatch.pop_back();
		m_mutex.unlock();
		
		unordered_set<int> nums = CSVReader().read(m_inpath + '/' + file);
		
		int score = m_blib.findSimilaritiesAndReturnScore(nums, m_minSimilarNumbers);
		cout << "fileName: " << file << " = score: " << score << '\n';
		if(score > 0)
		{
			FileMover().move(file, m_inpath, m_outpath);
			m_scoresFile << file << '\t' << score << '\n';
		}
	}
}

}
