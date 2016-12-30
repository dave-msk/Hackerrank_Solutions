#include <iostream>
#include <vector>

int main() {

    long N, p, d;
    std::cin >> N;
    long* arr = new long[N];
    std::vector<std::pair<long, long>> v;
    for (long i = 0; i < N; ++i) {
        std::cin >> p >> d;
        arr[i] = p - d;
        if (arr[i] >= 0) {
            v.push_back(std::make_pair(i,arr[i]));
        } else {
            while (!v.empty() && v.back().second + arr[i] < 0) {
                if (v.size() > 1) v[v.size()-2].second += v.back().second;
                v.pop_back();
            }
            if (!v.empty()) v.back().second += arr[i];
        }
    }
    for (long i = 0; i < N; ++i) {
        while (!v.empty() && v.back().second + arr[i] < 0) {
            if (v.size() > 1) v[v.size()-2].second += v.back().second;
            v.pop_back();
        }
        if (!v.empty()) v.back().second += arr[i];
    }
    std::cout << v[0].first << std::endl;

    return 0;
}