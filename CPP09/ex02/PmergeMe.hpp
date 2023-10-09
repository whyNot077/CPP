#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>

class PmergeMe {
public:
    PmergeMe(const std::string& line);
    ~PmergeMe(void) {};
private:
	std::vector<int> vec;
	std::list<int> lst;
private:
    PmergeMe(void) {};
    PmergeMe(PmergeMe const& copy);
    PmergeMe& operator=(PmergeMe const& copy);
	void LstToVec(void);
};

#endif