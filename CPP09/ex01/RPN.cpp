#include "RPN.hpp"

RPN::RPN(RPN const& copy) {
    *this = copy;
}

RPN& RPN::operator=(RPN const& copy) {
    if (this == &copy)
        return *this;
    computer = copy.computer;
    return *this;
}

static double Calculate(const double num1, const double num2, const char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            if (num2 == 0) {
                std::cout << "Error" << std::endl;
                exit(1);
            }
            return num1 - num2;
        case '/':
            return num1 / num2;
        case '*':
            return num1 * num2;
        default:
            std::cout << "Error" << std::endl;
            exit(1);
    }
}

RPN::RPN(const std::string& line) {
    if (!NumToStack(line)) {
        return;
    }
    double result = 0.0;

    std::stack<double> tmp;

    while (!computer.empty()) {
        while (!computer.empty() && computer.top().is_num) {
            result = computer.top().num;
            tmp.push(result);
            computer.pop();
        }
        if (computer.empty()) {
            break;
        }
        char op = computer.top().op;
        computer.pop();
        if (tmp.size() < 2) {
            std::cout << "Error" << std::endl;
            return;
        }
        double num2 = tmp.top();
        tmp.pop();
        double num1 = tmp.top();
        tmp.pop();
        result = Calculate(num1, num2, op);
        tmp.push(result);
    }
    if (tmp.size() == 1) {
        result = tmp.top();
        std::cout << result << std::endl;
    } else {
        std::cout << "Error" << std::endl;
    }
}

static bool IsOperator(const char c) {
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

static bool IsSpace(const char c) {
    return (c == ' ');
}

static bool IsNumber(const char c) {
    return (c >= '0' && c <= '9');
}

static bool IsMinus(const char c) {
    return (c == '-');
}

bool RPN::NumToStack(const std::string& line) {
    for (int i = line.size() - 1; i >= 0; --i) {
        char c = line[i];
        if (IsSpace(c)) {
            continue;
        } else if (IsNumber(c) && i > 0 && IsMinus(line[i - 1])) {
            std::string num = line.substr(i - 1, 2);
            PushData(std::atoi(num.c_str()), 0, true);
            --i;
        } else if (IsNumber(c)) {
            PushData(std::atoi(&c), 0, true);
        } else if (IsOperator(c)) {
            PushData(0, c, false);
        } else {
            std::cout << "Error" << std::endl;
            return false;
        }
    }
    return true;
}

void RPN::PushData(int i, char c, bool num) {
    Data data;
    data.num = i;
    data.op = c;
    data.is_num = num;
    computer.push(data);
}