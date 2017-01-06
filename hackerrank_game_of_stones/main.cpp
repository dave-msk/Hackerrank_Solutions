#include <iostream>

int main() {

    int t, n;
    std::cin >> t;
    bool arr[101]{0};
    for (int i = 2; i <= 6; ++i) arr[i] = 1;
    for (int i = 7; i <= 100; ++i) {
        if (arr[i-2] && arr[i-3] && arr[i-5]) arr[i] = 0;
        else arr[i] = 1;
    }
    while (t--) {
        std::cin >> n;
        std::cout << ((arr[n]) ? "First" : "Second") << std::endl;
    }
    return 0;
}