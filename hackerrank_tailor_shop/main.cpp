#include <iostream>
#include <map>

int main() {
    long n, p, a, value;
    long button = 1;
    long totalButton = 0;
    std::map<long,long> hist;
    std::cin >> n >> p;
    for (long i = 0; i < n; ++i) {
        std::cin >> a;
        if (hist.find(a) == hist.end()) hist[a] = 1;
        else ++hist[a];
    }

    for (auto pair : hist) {
        while (button * p < pair.first) ++button;
        value = pair.second;
        while (value-- > 0) {
            totalButton += button++;
        }
    }

    std::cout << totalButton << std::endl;
    return 0;
}