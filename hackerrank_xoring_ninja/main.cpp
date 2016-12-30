#include <iostream>

int main() {
    int t;
    long n, a;
    unsigned long sum = 0;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        sum = 0;
        for (long i = 0; i < n; ++i) {
            std::cin >> a;
            sum |= a;
        }
        while (--n) {
            sum = (sum << 1) % 1000000007;
        }
        std::cout << sum << std::endl;
    }

    return 0;
}