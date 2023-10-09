#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::string& line) {
	StrToList(line);
	LstToVec();
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
	vec.reserve(lst.size());
	vec.assign(lst.begin(), lst.end());
}