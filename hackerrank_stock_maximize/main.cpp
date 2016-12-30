#include <iostream>
#include <stack>

int main() {
    int t;
    std::cin >> t;
    long n, a;
    while (t--) {
        std::cin >> n;
        long *arr = new long[n];
        long long *prefixSum = new long long[n];
        std::stack<long> stk;
        for (long i = 0; i < n; ++i) {
            std::cin >> a;
            arr[i] = a;
            if (i == 0) prefixSum[0] = a;
            else prefixSum[i] = prefixSum[i-1] + a;
            while (!stk.empty() && arr[stk.top()] <= a) stk.pop();
            stk.push(i);
        }
        long long sum = 0;
        while (!stk.empty()) {
            a = stk.top();
            stk.pop();
            if (!stk.empty()) {
                sum += arr[a]*(a-stk.top()) - (prefixSum[a] - prefixSum[stk.top()]);
            } else {
                sum += arr[a]*(a+1) - prefixSum[a];
            }
        }

        std::cout << sum << std::endl;

        delete[] prefixSum;
        delete[] arr;
    }
    return 0;
}