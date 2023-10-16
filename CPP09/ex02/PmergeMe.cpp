#include "PmergeMe.hpp"
#define MAX_NUM 100000

PmergeMe::PmergeMe(const std::string& line) {
	StrToList(line);
	LstToVec();
    makePairLst();

}

void PmergeMe::sortVec(void) {
    makePairVec();
    mergeSort(pairVec, 0, pairVec.size() - 1);
    
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
    for (int i = 0; i < vec.size() - 1; ++i) {
        std::pair<int, int> tmp;
        if (vec[i] >= vec[i + 1]) {
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
    auto it = lst.begin();
    auto next_it = std::next(it);
    while (next_it != lst.end()) {
        std::pair<int, int> tmp;
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

void PmergeMe::mergeSort(std::vector<std::pair<int, int> >& arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void PmergeMe::merge(std::vector<std::pair<int, int> >& arr, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = 0;
    std::vector<std::pair<int, int> > temp(right - left + 1);

    while (i <= mid && j <= right) {
        if (arr[i].first <= arr[j].first) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = left, k = 0; i <= right; ++i, ++k) {
        arr[i] = temp[k];
    }
}

void merge(std::list<std::pair<int, int> >& arr, std::list<std::pair<int, int> >::iterator left, 
           std::list<std::pair<int, int> >::iterator mid, std::list<std::pair<int, int> >::iterator right) {
    std::list<std::pair<int, int> > temp;
    std::list<std::pair<int, int> >::iterator i = left, j = mid, k;

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
    for (std::list<std::pair<int, int> >::iterator it = temp.begin(); it != temp.end(); ++it, ++k) {
        *k = *it;
    }
}

void mergeSort(std::list<std::pair<int, int> >& arr, std::list<std::pair<int, int> >::iterator left, 
               std::list<std::pair<int, int> >::iterator right) {
    if (left != right && std::next(left) != right) {
        std::list<std::pair<int, int> >::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        mergeSort(arr, left, mid);
        mergeSort(arr, mid, right);

        merge(arr, left, mid, right);
    }
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

PmergeMe::StrToList(const std::string& line) {
	std::stringstream ss(line);
	std::string tmp;

	whlie (std::getline(ss, tmp, ' ')) {
		if (!IsStrToInt(tmp)) {
			std::cout << "Error" << std::endl;
			exit(1);
		}
		int num = std::atoi(tmp.c_str());
		lst.push_back(num);
	}
}

vod PmergeMe::LstToVec(void) {
    if (lst.size() > MAX_NUM){
        std::cout << "Error" << std::endl;
        exit(1);
    }
	vec.reserve(lst.size());
	vec.assign(lst.begin(), lst.end());
}