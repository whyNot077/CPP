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
#include <ctime>
class PmergeMe {
public:
    PmergeMe(const std::string& line);
    ~PmergeMe(void) {};
    void sortVec(void);
    void sortList(void);
    void printVec(const std::vector<int>& vec);
    void printPairVec(void);
    void printLst(const std::list<int>& lst);
    void printPairLst(void);
    const std::vector<int>& getVec(void);
    const std::vector<int>& getSortedVec(void);
    const std::list<int>& getSortedLst(void);
    const std::vector<int>& getJacobIndex(void);
    const std::list<int>& getLst(void);
    const double& getSortVecTime(void);
    const double& getSortListTime(void);
private:
    long long NONE;
	std::vector<int> vec;
    std::vector<std::pair<long long, long long> > pairVec;
    std::vector<int> sortedVec;
	std::list<int> lst;
    std::list<std::pair<long long, long long> > pairLst;
    std::list<int> sortedLst;
    std::vector<int> jacobIndex;
    double sortVecTime;
    double sortListTime;
private:
    PmergeMe(void) {};
    PmergeMe(PmergeMe const& copy);
    PmergeMe& operator=(PmergeMe const& copy);
    void StrToList(const std::string& line);
	void LstToVec(void);
    void makePairVec();
    void makePairLst();
    void swapPairVec();
    void swapPairLst();
    void mergeSort(int left, int right);
    void mergeSort(std::list<std::pair<long long, long long> >::iterator left, 
               std::list<std::pair<long long, long long> >::iterator right);
    void merge(int left, int mid, int right);
    void merge(std::list<std::pair<long long, long long> >::iterator left, 
           std::list<std::pair<long long, long long> >::iterator mid, std::list<std::pair<long long, long long> >::iterator right);
    void generateJacobNumbers(void);
    int findIndex(int value, std::vector<int>::iterator start, std::vector<int>::iterator end);
    int findIndex(int value, std::list<int>::iterator start, std::list<int>::iterator end);
    void sortSecond();
    void resizeVec(void);
    void sortSecondLst(void);
};

#endif