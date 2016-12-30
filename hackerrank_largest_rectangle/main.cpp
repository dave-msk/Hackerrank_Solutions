#include <iostream>
#include <stack>

int main() {

    long N;
    std::cin >> N;
    long* arr = new long[N];
    long long* mults = new long long[N]{0};
    std::stack<long> stk;
    long long max = 0;
    long long prod;
    for (long i = 0; i < N; ++i) {
        std::cin >> arr[i];
        while (!stk.empty() && arr[i] < arr[stk.top()]) {
            prod = (long long) arr[stk.top()] * (long long) (i-stk.top());
            mults[stk.top()] = prod;
            stk.pop();
        }
        stk.push(i);
    }

    while (!stk.empty()) {
        prod = (long long) arr[stk.top()] * (long long) (N - stk.top());
        mults[stk.top()] = prod;
        stk.pop();
    }

    for (long i = N-1; i >= 0; --i) {
        while (!stk.empty() && arr[i] < arr[stk.top()]) {
            prod = (long long) arr[stk.top()] * (long long) (stk.top()-i-1);
            mults[stk.top()] += prod;
            stk.pop();
        }
        stk.push(i);
    }

    while (!stk.empty()) {
        prod = (long long) arr[stk.top()] * (long long) (stk.top());
        mults[stk.top()] += prod;
        stk.pop();
    }

    for (long i = 0; i < N; ++i) if (max < mults[i]) max = mults[i];

    std::cout << max << std::endl;

    return 0;
}