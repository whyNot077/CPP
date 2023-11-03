#include "PmergeMe.hpp"
#define MAX_NUM 100000

PmergeMe::PmergeMe(const std::string& line) {
    NONE = -2147483650;
	StrToList(line);
	LstToVec();
    resizeVec();
    makePairVec();
    makePairLst();
    generateJacobNumbers();
}

void PmergeMe::sortVec(void) {
    std::clock_t start = std::clock();
    swapPairVec();
    mergeSort(0, pairVec.size() - 1);
    sortSecond();
    std::clock_t end = std::clock();
    sortVecTime = (end - start) / static_cast<double>(CLOCKS_PER_SEC) * 1e6;

}

void PmergeMe::sortList(void) {
    std::clock_t start = std::clock();
    swapPairLst();
    mergeSort(pairLst.begin(), pairLst.end());
    sortSecondLst();
    std::clock_t end = std::clock();
    sortListTime = (end - start) / static_cast<double>(CLOCKS_PER_SEC) * 1e6;
}

void PmergeMe::resizeVec(void) {
    pairVec.reserve(vec.size() / 2);
    sortedVec.reserve(vec.size());
    jacobIndex.reserve((vec.size() + 1) / 2);
}

void PmergeMe::generateJacobNumbers(void) {
    int prev = 0;
    int curr = 1;
    int n = vec.size();
    
    jacobIndex.push_back(prev);
    jacobIndex.push_back(curr);
    int max_size = (n + 1) / 2;
    for (int i = 2; i < n; ++i) {
        int next = curr + 2 * prev;
        int size = next;
        if (size >= max_size) {
            size = max_size - 1;
        }
        for (int j = 0; j < size - curr; ++j) {
            jacobIndex.push_back(size - j);
        }
        if (jacobIndex.size() >= static_cast<size_t>(max_size)) {
            break;
        }
        prev = curr;
        curr = next;
    }
}

int findIndex(int value, std::vector<int>::iterator start, std::vector<int>::iterator end) {
    std::vector<int>::iterator it = std::lower_bound(start, end, value);
    return std::distance(start, it);
}

void PmergeMe::sortSecond() {
    if (pairVec.size() == 1) {
        if (pairVec[0].second == NONE) {
            sortedVec.push_back(pairVec[0].first);
        } else {
            sortedVec.push_back(pairVec[0].second);
            sortedVec.push_back(pairVec[0].first);
        }
        return;
    }
    for (size_t i = 0; i < pairVec.size(); ++i) {
        sortedVec.push_back(pairVec[i].first);
    }
    // std::cout << "SortedVec: ";
    // printVec(sortedVec);
    // std::cout << "______________________" << std::endl;
    for (size_t i = 0; i < jacobIndex.size(); ++i) {
        int target = jacobIndex[i];
        if (pairVec[target].second == NONE) {
            continue;
        }
        int move = std::min((target + 2) * 2, static_cast<int>(sortedVec.size()));
        int index = findIndex(pairVec[target].second, sortedVec.begin(),  sortedVec.begin() + move);
        sortedVec.insert(sortedVec.begin() + index, pairVec[target].second);
        // std::cout << "begin index: " << 0 << " end index: " << move << " value: " << pairVec[target].second << " index: " << index << std::endl;
        // std::cout << "SortedVec: ";
        // printVec(sortedVec);
        // std::cout << "______________________" << std::endl;
        // ./PmergeMe `jot -r 30 1 100000 | tr '\n' ' '`
    }
}

std::list<int>::iterator findIndexList(long long value, std::list<int>::iterator start, std::list<int>::iterator end) {
    for (std::list<int>::iterator it = start; it != end; ++it) {
        if (*it >= value) {
            return it;
        }
    }
    return end;
}

void PmergeMe::sortSecondLst() {
    if (pairLst.size() == 1) {
        std::list<std::pair<long long, long long> >::iterator it = pairLst.begin();
        if (it->second == NONE) {
            sortedLst.push_back(it->first);
        } else {
            sortedLst.push_back(it->second);
            sortedLst.push_back(it->first);
        }
        return;
    }
    for (std::list<std::pair<long long, long long> >::iterator it = pairLst.begin(); it != pairLst.end(); ++it) {
        sortedLst.push_back(it->first);
    }
    for (std::vector<int>::size_type i = 0; i < jacobIndex.size(); ++i) {
        int target = jacobIndex[i];
        std::list<std::pair<long long, long long> >::iterator targetIt = pairLst.begin();
        std::advance(targetIt, target);
        if (targetIt->second == NONE) {
            continue;
        }
        int move = std::min((target + 2) * 2, static_cast<int>(sortedLst.size()));
        std::list<int>::iterator moveIt = sortedLst.begin();
        std::advance(moveIt, move);
        std::list<int>::iterator insertPos = \
            findIndexList(targetIt->second, sortedLst.begin(), moveIt);
        sortedLst.insert(insertPos, targetIt->second);

        // std::cout << "begin index: " << 0 << " end index: " << move << " value: " << targetIt->second << " index: " << std::distance(sortedLst.begin(), insertPos) << std::endl;
        // std::cout << "SortedLst: ";
        // printLst(sortedLst);
        // std::cout << "______________________" << std::endl;
    }
}

PmergeMe::PmergeMe(PmergeMe const& copy) {
    *this = copy;
}

PmergeMe& PmergeMe::operator=(PmergeMe const& copy) {
    if (this != &copy) {
        vec = copy.vec;
        lst = copy.lst;
    }
    return *this;
}
void PmergeMe::makePairVec(void) {
    int n = vec.size();
    for (int i = 0; i < n; i += 2) {
        std::pair<long long, long long> tmp;
        tmp.first = vec[i];
        if (i + 1 < n) {
            tmp.second = vec[i + 1];
        } else {
            tmp.second = NONE;
        }
        pairVec.push_back(tmp);
    }
}

void PmergeMe::makePairLst(void) {
    std::list<int>::iterator it = lst.begin();
    while (it != lst.end()) {
        std::pair<long long, long long> tmp;
        tmp.first = *it;
        ++it;
        if (it != lst.end()) {
            tmp.second = *it;
            ++it;
        } else {
            tmp.second = NONE;
        }
        pairLst.push_back(tmp);
    }
}

void PmergeMe::swapPairVec() {
    for (size_t i = 0; i < pairVec.size(); ++i) {
        if (pairVec[i].second != NONE) {
            if (pairVec[i].first < pairVec[i].second) {
                std::swap(pairVec[i].first, pairVec[i].second);
            }
        }
    }
}

void PmergeMe::swapPairLst() {
    for (std::list<std::pair<long long, long long> >::iterator it = pairLst.begin(); it != pairLst.end(); ++it) {
        if (it->second != NONE) {
            if (it->first < it->second) {
                std::swap(it->first, it->second);
            }
        }
    }
}

void PmergeMe::mergeSort(int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

void PmergeMe::merge(int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    std::vector<std::pair<int, long long> > temp(right - left + 1);

    while (i <= mid && j <= right) {
        if (pairVec[i].first <= pairVec[j].first) {
            temp[k] = pairVec[i];
            i++;
        } else {
            temp[k] = pairVec[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = pairVec[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = pairVec[j];
        j++;
        k++;
    }

    for (i = left, k = 0; i <= right; ++i, ++k) {
        pairVec[i] = temp[k];
    }
}

void PmergeMe::mergeSort(std::list<std::pair<long long, long long> >::iterator left, 
               std::list<std::pair<long long, long long> >::iterator right) {
    if (left != right && std::next(left) != right) {
        std::list<std::pair<long long, long long> >::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        mergeSort(left, mid);
        mergeSort(mid, right);

        merge(left, mid, right);
    }
}


void PmergeMe::merge(std::list<std::pair<long long, long long> >::iterator left, 
           std::list<std::pair<long long, long long> >::iterator mid, std::list<std::pair<long long, long long> >::iterator right) {
    std::list<std::pair<long long, long long> > temp;
    std::list<std::pair<long long, long long> >::iterator i = left, j = mid, k;

    while (i != mid && j != right) {
        if ((*i).first <= (*j).first) {
            temp.push_back(*i);
            ++i;
        } else {
            temp.push_back(*j);
            ++j;
        }
    }

    while (i != mid) {
        temp.push_back(*i);
        ++i;
    }

    while (j != right) {
        temp.push_back(*j);
        ++j;
    }

    k = left;
    for (std::list<std::pair<long long, long long> >::iterator it = temp.begin(); it != temp.end(); ++it, ++k) {
        *k = *it;
    }
}

void PmergeMe::StrToList(const std::string& line) {
    std::stringstream ss(line);
    std::string tmp;

    while (std::getline(ss, tmp, ' ')) {
        int num = std::atoi(tmp.c_str());
        lst.push_back(num);
    }
}

void PmergeMe::LstToVec(void) {
    if (lst.size() > MAX_NUM){
        std::cout << "Error" << std::endl;
        exit(1);
    }
	vec.reserve(lst.size());
	vec.assign(lst.begin(), lst.end());
}

void PmergeMe::printVec(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

const std::vector<int>& PmergeMe::getVec(void) {
    return vec;
}

const std::vector<int>& PmergeMe::getSortedVec(void) {
    return sortedVec;
}

void PmergeMe::printPairVec(void) {
    for (size_t i = 0; i < pairVec.size(); ++i) {
        std::cout << pairVec[i].first << " " << pairVec[i].second<< " ";
    }
    std::cout << std::endl;
}

const std::vector<int>& PmergeMe::getJacobIndex(void) {
    return jacobIndex;
}

const double& PmergeMe::getSortVecTime(void) {
    return sortVecTime;
}

void PmergeMe::printLst(const std::list<int>& lst) {
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::printPairLst(void) {
    for (std::list<std::pair<long long, long long> >::iterator it = pairLst.begin(); it != pairLst.end(); ++it) {
        std::cout << (*it).first << " " << (*it).second << " ";
    }
    std::cout << std::endl;
}

const std::list<int>& PmergeMe::getLst(void) {
    return lst;
}

const std::list<int>& PmergeMe::getSortedLst(void) {
    return sortedLst;
}

const double& PmergeMe::getSortListTime(void) {
    return sortListTime;
}
