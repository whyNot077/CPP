#include "BitcoinExchange.hpp"

const std::string csvData = "data.csv";
BitcoinExchange::BitcoinExchange(BitcoinExchange const& copy) {
    *this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& copy) {
    if (this == &copy)
        return *this;
    filename = copy.filename;
    data = copy.data;
    return *this;
}

static float GetValue(const std::string& value_str) {
    float value = 0.0f;
    std::string::size_type pos = value_str.find('.');
    if (value_str.length() > 4) {
        throw std::invalid_argument("too large a number");
    } else if (value_str[0] == '-') {
        throw std::invalid_argument("not a positive number");
    } else if (pos != std::string::npos) {
        std::string integer = value_str.substr(0, pos);
        std::string decimal = value_str.substr(pos + 1);
        float divisor = std::pow(10.0f, decimal.length());
        value = std::atoi(integer.c_str()) + std::atoi(decimal.c_str()) / divisor;
    } else {
        value = std::atoi(value_str.c_str());
    }
    return value;
}

BitcoinExchange::BitcoinExchange(std::string filename) : csv(csvData), filename(filename) {
    ParseData(csv);
    std::string date;
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Error: could not open file" << std::endl;
        exit(1);
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::string::size_type pos = line.find('|');
        if (pos == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            line.clear();
            continue;
        }
        date = line.substr(0, pos - 1);
        std::string value_str = line.substr(pos + 1);

        try {
            float value = GetValue(value_str);
            if (IsValidDate(date) && IsValidValue(value))
                PrintData(date, value);
        } catch (std::invalid_argument& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}

bool BitcoinExchange::IsValidValue(const float value) const {
    if (value < 0) {
        throw std::invalid_argument("not a positive number");
    }
    return true;
}


void BitcoinExchange::ParseData(const std::string& csv) {
    if (csv.substr(csv.find_last_of('.')) != ".csv") {
        std::cout << "Error: file is not .csv" << std::endl;
        exit(1);
    }

    std::ifstream file(csv);
    if (!file.is_open()) {
        std::cout << "Error: could not open .csv file" << std::endl;
        exit(1);
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::string date = line.substr(0, line.find(','));
        std::string price = line.substr(line.find(',') + 1);
        try {
            data[date] = std::stof(price);
        } catch (std::invalid_argument& e) {
            std::cout << "Invalid float value: " << price << std::endl;
            continue;
        }
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

bool BitcoinExchange::IsValidDate(const std::string& date) const {
    if (date.size() != 10) {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }
    if (date[4] != '-' || date[7] != '-') {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    std::string s_year = date.substr(0, 4);
    std::string s_month = date.substr(5, 2);
    std::string s_day = date.substr(8, 2);

    if (!IsStrToInt(s_year) || !IsStrToInt(s_month) || !IsStrToInt(s_day)) {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    int year = std::atoi(s_year.c_str());
    int month = std::atoi(s_month.c_str());
    int day = std::atoi(s_day.c_str());

    if (year < 2009 || year > 2024) {
        std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }
    bool is_leap_year = ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);

    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (day < 1 || day > 31) {
                std::cout << "Error: bad input => " << date << std::endl;
                return false;
            }
            break;
        case 4: case 6: case 9: case 11:
            if (day < 1 || day > 30) {
                std::cout << "Error: bad input => " << date << std::endl;
                return false;
            }
            break;
        case 2:
            if (is_leap_year) {
                if (day < 1 || day > 29) {
                    std::cout << "Error: bad input => " << date << std::endl;
                    return false;
                }
            } else {
                if (day < 1 || day > 28) {
                    std::cout << "Error: bad input => " << date << std::endl;
                    return false;
                }
            }
            break;
        default:
            std::cout << "Error: bad input => " << date << std::endl;
            return false;
    }
    return true;
}
static std::string GetPreviousDate(std::string& date) {
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    if (day == "01") {
        if (month == "01") {
            year = std::to_string(std::stoi(year) - 1);
            month = "12";
        } 
else {
            month = std::to_string(std::stoi(month) - 1);
            if (month.size() == 1)
                month = "0" + month;
        }
        day = "31";
    } else {
        day = std::to_string(std::stoi(day) - 1);
        if (day.size() == 1)
            day = "0" + day;
    }
    return year + "-" + month + "-" + day;
}

void BitcoinExchange::PrintData(const std::string& date, const float value) {
    if (data.find(date) != data.end()) {
        std::cout << date << " => " << value << " = " << value * data[date] << std::endl;
    } else {
        std::string closest = date;
        while (data.find(closest) == data.end() && data.find(closest) != data.begin()) {
            closest = GetPreviousDate(closest);
        }
        std::cout << date << " => " << value << " = " << value * data[closest] << std::endl;
    }
}
