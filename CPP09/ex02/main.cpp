#include "PmergeMe.hpp"

static void PrintString(const std::string& str, int width) {
    int len = width - str.length();
    std::cout << str;
    for (int i = 0; i < len; ++i) {
        std::cout << " ";
    }
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

    // PrintString("Jacob Numbers:");
    // pm.printVec(pm.getJacobNumbers());

    // PrintString("Jacob Index:");
    // pm.printVec(pm.getJacobIndex());

    pm.sortVec();

    // PrintString("Pair Vec:");
    // pm.printPairVec();
    
    PrintString("After:", 10);
    pm.printVec(pm.getSortedVec());

    PrintString("Time to process a range of ", 25);
    std::cout << pm.getVec().size();
    PrintString(" elements with std::vector:", 28);
    std::cout << pm.getSortVecTime() << " us" << std::endl;
    pm.sortList();
    return 0;
}