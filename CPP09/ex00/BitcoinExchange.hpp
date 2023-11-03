#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <sstream>

class BitcoinExchange {
public:
    ~BitcoinExchange(void) {};
    BitcoinExchange(std::string filename);
private:
    std::string csv;
    std::string filename;
    std::map<std::string, float> data;
private:
    BitcoinExchange(void) {};
    BitcoinExchange(BitcoinExchange const& copy);
    BitcoinExchange& operator=(BitcoinExchange const& copy);
    void ParseData(const std::string& csv);
    bool IsValidDate(const std::string& date) const;
    bool IsValidValue(const float value) const;
    void PrintData(const std::string& date, const float value);
};

#endif