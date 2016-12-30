#include <iostream>
#include <deque>

int main() {
    long n, q, d;
    std::cin >> n >> q;
    long* arr = new long[n];
    for (long i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    for (long i = 0; i < q; ++i) {
        std::cin >> d;
        long min = 1000000;
        std::deque<long> dq;
        for (long j = 0; j < d; ++j) {
            while (!dq.empty() && arr[dq.back()] <= arr[j]) dq.pop_back();
            dq.push_back(j);
        }
        if (arr[dq.front()] < min) min = arr[dq.front()];
        for (long j = d; j < n; ++j) {
            if (dq.front() <= j-d) dq.pop_front();
            while (!dq.empty() && arr[dq.back()] <= arr[j]) dq.pop_back();
            dq.push_back(j);
            if (arr[dq.front()] < min) min = arr[dq.front()];
        }
        std::cout << min << std::endl;
    }
    return 0;
}