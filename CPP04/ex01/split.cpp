#include <string>
#include <iostream>

std::string* split(const std::string& str, char delim, int& count) {
    std::string* words;
    count = 0;
    size_t start = 0;
    size_t end = str.find(delim);

    while (end != std::string::npos) {
        count++;
        start = end + 1;
        end = str.find(delim, start);
    }

    words = new std::string[count];
    start = 0;
    end = str.find(delim);
    int i = 0;

    while (end != std::string::npos) {
        words[i] = str.substr(start, end - start);
        i++;
        start = end + 1;
        end = str.find(delim, start);
    }

    return words;
}
