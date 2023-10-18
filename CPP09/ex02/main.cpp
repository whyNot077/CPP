#include "PmergeMe.hpp"

static void PrintString(const std::string& str) {
    const int width = 15;
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
    PrintString("Before:");
    pm.printVec(pm.getVec());

    PrintString("Jacob Numbers:");
    pm.printVec(pm.getJacobNumbers());

    pm.sortVec();
    PrintString("Pair Vec:");
    pm.printPairVec();
    
    PrintString("After:");
    pm.printVec(pm.getSortedVec());
    pm.sortList();
    return 0;
}