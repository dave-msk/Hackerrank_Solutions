#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long n, k, v1, v2;
    std::cin >> n >> k;
    std::vector<long> v(n);
    long i = 0;
    while (i < n) std::cin >> v[i++];
    std::make_heap(v.begin(), v.end(), std::greater<long>());
    i = 0;
    while (v.size() > 1 && v.front() < k) {
        ++i;
        v1 = v.front();
        std::pop_heap(v.begin(), v.end(), std::greater<long>());
        v.pop_back();
        v2 = v.front();
        std::pop_heap(v.begin(), v.end(), std::greater<long>());
        v.pop_back();
        v.push_back(v1 + 2*v2);
        std::push_heap(v.begin(), v.end(), std::greater<long>());
    }
    std::cout << ((v.front() < k) ? -1 : i) << std::endl;
    return 0;
}