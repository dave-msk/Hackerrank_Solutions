#include <iostream>
#include <algorithm>

int main() {
    int s, n, count;
    long b1, b2;
    std::cin >> s;
    while (s--) {
        std::cin >> n;
        std::pair<long,long>* arr = new std::pair<long,long>[n];
        for (int i = 0; i < n; ++i) std::cin >> arr[i].second >> arr[i].first;
        b1 = 0, b2 = 0;
        count = 0;
        std::sort(arr, arr+n);
        for (int i = 0; i < n; ++i) {
            if (arr[i].second > b1 && arr[i].second > b2) {
                ++count;
                if (b1 > b2) b1 = arr[i].first;
                else b2 = arr[i].first;
            } else if (arr[i].second > b1) {
                ++count;
                b1 = arr[i].first;
            } else if (arr[i].second > b2) {
                ++count;
                b2 = arr[i].first;
            }
        }

        std::cout << count << std::endl;

        delete[] arr;
    }
    return 0;
}