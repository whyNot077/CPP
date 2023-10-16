#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility> 

class PmergeMe {
public:
    PmergeMe(const std::string& line);
    ~PmergeMe(void) {};
    void sortVec(void);
private:
	std::vector<int> vec;
    std::vector<std::pair<int, int> > pairVec;
	std::list<int> lst;
    std::list<std::pair<int, int> > pairLst;
private:
    PmergeMe(void) {};
    PmergeMe(PmergeMe const& copy);
    PmergeMe& operator=(PmergeMe const& copy);
	void LstToVec(void);
    void makePairVec(void);
    void makePairLst(void);
    void mergeSort(std::vector<std::pair<int, int> >& arr, int left, int right);
    void mergeSort(std::list<std::pair<int, int> >& arr, int left, int right);
    void merge(std::vector<std::pair<int, int> >& arr, int left, int mid, int right);
    void merge(std::list<std::pair<int, int> >& arr, int left, int mid, int right);
};

#endif