#include <iostream>

int main() {
    int t;
    long n, result, value;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        result = 0;
        for (int k = 1; k <= n; ++k) {
            std::cin >> value;
            if ((k & 1) && ((n-k+1) & 1)) {
                result ^= value;
            }
        }
        std::cout << result << std::endl;
    }
    return 0;
}