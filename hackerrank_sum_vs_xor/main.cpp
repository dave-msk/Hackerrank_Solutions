#include <iostream>

int main() {
    unsigned long long n;
    unsigned long long count = 0;
    std::cin >> n;
    while (n) {
        if (!(n & 1)) ++count;
        n >>= 1;
    }
    std::cout << (1l << count) << std::endl;
}