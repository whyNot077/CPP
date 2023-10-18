#include "PmergeMe.hpp"

static void PrintString(const std::string& str, int width) {
    int len = width - str.length();
    std::cout << str;
    for (int i = 0; i < len; ++i) {
        std::cout << " ";
    }
}

static void PrintTime(const double& time) {
    std::cout << time << " us" << std::endl;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Usage: ./PmergeMe [numbers]" << std::endl;
        return 1;
    }
    std::stringstream ss;
    for (int i = 1; i < argc; ++i) {
        ss << argv[i] << " ";
    }
    PmergeMe pm(ss.str());
    PrintString("Before:", 10);
    pm.printVec(pm.getVec());

    pm.sortVec();
    pm.sortList();

    // PrintString("Jacob Index:", 15);
    // pm.printVec(pm.getJacobIndex());

    // PrintString("Pair Vec:", 10);
    // pm.printPairVec();

    // PrintString("Pair Lst:", 10);
    // pm.printPairLst();

    PrintString("After:", 10);
    pm.printVec(pm.getSortedVec());
    // PrintString("After:", 10);
    // pm.printLst(pm.getSortedLst());

    PrintString("Time to process a range of ", 25);
    std::cout << pm.getVec().size();
    PrintString(" elements with std::vector:", 28);
    PrintTime(pm.getSortVecTime());

    PrintString("Time to process a range of ", 25);
    std::cout << pm.getLst().size();
    PrintString(" elements with std::list:", 28);
    PrintTime(pm.getSortListTime());
    return 0;
}