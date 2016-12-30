#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    long n;
    double v;
    std::cin >> n;
    std::vector<double> upper, lower;
    for (long i = 0; i < n; ++i) {
        std::cin >> v;

        if (!lower.empty() && v <= lower.front()) {
            lower.push_back(v);
            std::push_heap(lower.begin(), lower.end(), std::less<double>());
        } else {
            upper.push_back(v);
            std::push_heap(upper.begin(), upper.end(), std::greater<double>());
        }

        while (upper.size() > lower.size() + 1) {
            v = upper.front();
            lower.push_back(v);
            std::push_heap(lower.begin(), lower.end(), std::less<double>());
            std::pop_heap(upper.begin(), upper.end(), std::greater<double>());
            upper.pop_back();
        }

        while (lower.size() > upper.size() + 1) {
            v = lower.front();
            upper.push_back(v);
            std::push_heap(upper.begin(), upper.end(), std::greater<double>());
            std::pop_heap(lower.begin(), lower.end(), std::less<double>());
            lower.pop_back();
        }
        if (upper.size() > lower.size()) std::printf("%.1lf\n", upper.front());
        else if (lower.size() > upper.size()) std::printf("%.1lf\n", lower.front());
        else std::printf("%.1lf\n", (upper.front() + lower.front())/2.0);
    }
    return 0;
}