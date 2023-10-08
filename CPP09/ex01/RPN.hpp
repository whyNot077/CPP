#ifndef RPN_HPP
#define RPN_HPP
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>

class RPN {
public:
    struct Data {
        int num;
        char op;
        bool is_num;
    };
    RPN(const std::string& line);
    ~RPN(void) {};
private:
    std::stack<Data> computer;
private:
    RPN(void) {};
    RPN(RPN const& copy);
    RPN& operator=(RPN const& copy);
    bool NumToStack(const std::string& line);
    void PushData(int i, char c, bool num);
};

#endif