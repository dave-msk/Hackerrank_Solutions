#include <iostream>
#include <stack>

int main() {

    int n;
    std::cin >> n;
    long* arr = new long[n];
    std::stack<long> candidates;
    long* l_idx = new long[n]{0};
    long long max = 0;
    long long currMult;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
        while (!candidates.empty() && arr[i] >= arr[candidates.top()-1]) candidates.pop();
        if (candidates.empty()) l_idx[i] = 0;
        else l_idx[i] = candidates.top();
        candidates.push(i+1);
    }

    while (!candidates.empty()) candidates.pop();

    for (int i = n-1; i >= 0; --i) {
        while (!candidates.empty() && arr[i] >= arr[candidates.top()-1]) candidates.pop();
        currMult = (candidates.empty()) ? 0 : ((long long) candidates.top() * (long long)l_idx[i]);
        if (max < currMult) max = currMult;
        candidates.push(i+1);
    }

    std::cout << max << std::endl;

    return 0;
}