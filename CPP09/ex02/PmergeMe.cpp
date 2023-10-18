#include "PmergeMe.hpp"
#define MAX_NUM 100000

static bool IsStrToInt(const std::string& str);

PmergeMe::PmergeMe(const std::string& line) {
    NONE = -2147483650;
	StrToList(line);
	LstToVec();
    resizeVec();
    generateJacobNumbers();
}

void PmergeMe::sortVec(void) {
    makePairVec();
    mergeSort(0, pairVec.size() - 1);
    // sortSecond();
}
void PmergeMe::resizeVec(void) {
    pairVec.reserve(vec.size() / 2);
    sortedVec.resize(vec.size(), 0);
    jacobNumbers.reserve(vec.size());
}

void PmergeMe::sortList(void) {
    makePairLst();
    mergeSort(pairLst.begin(), pairLst.end());
}

void PmergeMe::generateJacobNumbers(void) {
    int prev = 0;
    int curr = 1;
    int n = vec.size();
    
    jacobNumbers.push_back(prev);
    jacobNumbers.push_back(curr);
    for (int i = 2; i < n; ++i) {
        int next = curr + 2 * prev;
        if (next >= n) {
            next = n - 1;
        }
        for (int j = 0; j < next - curr; ++j) {
            jacobNumbers.push_back(next - j);
        }
        prev = curr;
        curr = next;
    }
}

int PmergeMe::findIndex(int value, std::vector<int>::iterator& start, std::vector<int>::iterator& end) {
    std::vector<int>::iterator it = std::lower_bound(start, end, value);
    return it - sortedVec.begin();
}

// void PmergeMe::sortSecond() {
//     for (int i = 0; i < jacobNumbers.size(); ++i) {
//         int index = jacobNumbers[i];
//         if (index >= sortedVec.size()) {
//             index = sortedVec.size() - 1;
//         }
//         if (pairVec[i].second != NONE) {
//             int secondIndex = findIndex(
//             std::swap(sortedVec[index], sortedVec[secondIndex]);
//         }
//     }
// }

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
        std::pair<int, long long> tmp;
        if (i + 1 == n) {
            tmp.first = vec[i];
            tmp.second = NONE;
        }
        else if (vec[i] >= vec[i + 1]) {
            tmp.first = vec[i];
            tmp.second = vec[i + 1];
        } else {
            tmp.first = vec[i + 1];
            tmp.second = vec[i];
        }
        pairVec.push_back(tmp);
    }
}

void PmergeMe::makePairLst(void) {
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator next_it = std::next(it);
    while (next_it != lst.end()) {
        std::pair<int, long long> tmp;
        if (*it >= *next_it) {
            tmp.first = *it;
            tmp.second = *next_it;
        } else {
            tmp.first = *next_it;
            tmp.second = *it;
        }
        pairLst.push_back(tmp);
        ++it;
        ++next_it;
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

    int index = 0;
    for (i = left, k = 0; i <= right; ++i, ++k) {
        pairVec[i] = temp[k];
        sortedVec[index] = temp[k].first;
        index++;
        if (temp[k].second != NONE) {
            sortedVec[index] = temp[k].second;
            index++;
        }
    }
}

void PmergeMe::merge(std::list<std::pair<int, long long> >::iterator left, 
           std::list<std::pair<int, long long> >::iterator mid, std::list<std::pair<int, long long> >::iterator right) {
    std::list<std::pair<int, long long> > temp;
    std::list<std::pair<int, long long> >::iterator i = left, j = mid, k;

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
    for (std::list<std::pair<int, long long> >::iterator it = temp.begin(); it != temp.end(); ++it, ++k) {
        *k = *it;
    }
}

void PmergeMe::mergeSort(std::list<std::pair<int, long long> >::iterator left, 
               std::list<std::pair<int, long long> >::iterator right) {
    if (left != right && std::next(left) != right) {
        std::list<std::pair<int, long long> >::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        mergeSort(left, mid);
        mergeSort(mid, right);

        merge(left, mid, right);
    }
}

void PmergeMe::StrToList(const std::string& line) {
	std::stringstream ss(line);
	std::string tmp;

	while (std::getline(ss, tmp, ' ')) {
		if (!IsStrToInt(tmp)) {
			std::cout << "Error" << std::endl;
			exit(1);
		}
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

static bool IsStrToInt(const std::string& str) {
    char *end;
    errno = 0;
    long val = std::strtol(str.c_str(), &end, 10);

    if (end == str.c_str() || *end != '\0') {
        return false;
    }
    if (errno == ERANGE || val > INT_MAX || val < INT_MIN) {
        return false;
    }
    return true;
}

const std::vector<int>& PmergeMe::getVec(void) {
    return vec;
}

const std::vector<int>& PmergeMe::getSortedVec(void) {
    return sortedVec;
}

const std::vector<int>& PmergeMe::getJacobNumbers(void) {
    return jacobNumbers;
}

void PmergeMe::printPairVec(void) {
    for (size_t i = 0; i < pairVec.size(); ++i) {
        std::cout << pairVec[i].first << " " << pairVec[i].second<< " ";
    }
    std::cout << std::endl;
}