#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<std::pair<long long, long long>> v;
    std::vector<long long> tmp;
    long long sum = 0, arrival, value;
    long N;
    std::cin >> N;
    for (long i = 0; i < N; ++i) {
        std::cin >> arrival >> value;
        v.push_back(std::make_pair(arrival, value));
        std::push_heap(v.begin(), v.end(), std::greater<std::pair<long long,long long>>());
    }
    long long currTime = v.front().first;
    while (!v.empty()) {

        while (!v.empty() && v.front().first <= currTime) {
            sum += currTime - v.front().first;
            tmp.push_back(v.front().second);
            std::push_heap(tmp.begin(), tmp.end(), std::greater<long long>());
            std::pop_heap(v.begin(), v.end(), std::greater<std::pair<long long,long long>>());
            v.pop_back();
        }

        if (!v.empty() && tmp.empty()) {
            currTime = v.front().first;
            continue;
        }

        currTime += tmp.front();
        sum += tmp.front()*tmp.size();
        std::pop_heap(tmp.begin(), tmp.end(), std::greater<long long>());
        tmp.pop_back();
    }
    while (!tmp.empty()) {
        sum += tmp.front()*tmp.size();
        std::pop_heap(tmp.begin(), tmp.end(), std::greater<long long>());
        tmp.pop_back();
    }
    std::cout << sum/N << std::endl;
    return 0;
}