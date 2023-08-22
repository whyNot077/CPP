#include "includes.hpp"

int main() {
    srand(time(NULL));
    Base *base = generate();
    identify(base);
    identify(*base);
    identify(nullptr);
    delete base;
    return 0;
}
