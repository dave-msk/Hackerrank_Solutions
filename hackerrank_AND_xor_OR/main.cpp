#include <iostream>
#include <stack>

int main() {

    long N;
    // long* arr = new long[N];
    std::cin >> N;
    long max = 0, value, out;
    std::stack<long> stk;
    for (long i = 0; i < N; ++i) {
        std::cin >> value;
        while (!stk.empty()) {
            out = value^stk.top();
            if (max < out) max = out;
            if (value < stk.top()) stk.pop();
            else break;
        }
        stk.push(value);
    }
    std::cout << max << std::endl;
    return 0;
}