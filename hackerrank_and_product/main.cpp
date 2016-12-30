#include <iostream>

int main() {

    int n, count;
    unsigned long a, b, diff;
    const unsigned long one = 1;
    std::cin >> n;
    while (n--) {
        count = 0;
        std::cin >> a >> b;
        diff = a^b;
        while (diff >> count) ++count;
        std::cout << (b & ~((one << count)-1)) << std::endl;

    }
    return 0;
}