#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;  // 5, 17
    mstack.pop(); // 5
    std::cout << mstack.size() << std::endl; // 1
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0); // 5, 3, 5, 737, 0
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << "--- MutantStack ---" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    std::cout << "--- MutantStack reverse ---" << std::endl;
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }
    std::stack<int> s(mstack);
    std::cout << "--- std::stack ---" << std::endl;
    while (!s.empty()) {
        std::cout << s.top() << std::endl;
        s.pop();
    }
    std::cout << "--- pop MutantStack ---" << std::endl;
    while (!mstack.empty()) {
        std::cout << mstack.top() << std::endl;
        mstack.pop();
    }
    return 0;
}