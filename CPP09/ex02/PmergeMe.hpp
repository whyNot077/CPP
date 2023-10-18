#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <list>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <utility> 
#include <sstream>
class PmergeMe {
    long long NONE;
public:
    PmergeMe(const std::string& line);
    ~PmergeMe(void) {};
    void sortVec(void);
    void sortList(void);
    void printVec(const std::vector<int>& vec);
    void printPairVec(void);
    const std::vector<int>& getVec(void);
    const std::vector<int>& getSortedVec(void);
    const std::vector<int>& getJacobNumbers(void);
private:
	std::vector<int> vec;
    std::vector<std::pair<int, long long> > pairVec;
    std::vector<int> sortedVec;
	std::list<int> lst;
    std::list<std::pair<int, long long> > pairLst;
    std::list<int> sortedLst;
    std::vector<int> jacobNumbers;
private:
    PmergeMe(void) {};
    PmergeMe(PmergeMe const& copy);
    PmergeMe& operator=(PmergeMe const& copy);
    void StrToList(const std::string& line);
	void LstToVec(void);
    void makePairVec(void);
    void makePairLst(void);
    void mergeSort(int left, int right);
    void mergeSort(std::list<std::pair<int, long long> >::iterator left, 
               std::list<std::pair<int, long long> >::iterator right);
    void merge(int left, int mid, int right);
    void merge(std::list<std::pair<int, long long> >::iterator left, 
           std::list<std::pair<int, long long> >::iterator mid, std::list<std::pair<int, long long> >::iterator right);
    void generateJacobNumbers(void);
    int findIndex(int value, std::vector<int>::iterator& start, std::vector<int>::iterator& end);
    void sortSecond();
    void resizeVec(void);
};

#endif