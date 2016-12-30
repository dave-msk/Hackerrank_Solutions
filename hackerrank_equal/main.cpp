#include <iostream>
#include <algorithm>

long getOperation(long diff) {
    return (diff/5 + (diff % 5)/2 + (diff % 5 % 2));
}

int main() {

    int t, n;
    std::cin >> t;
    long count, count2;
    while (t--) {
        std::cin >> n;
        count = 0;
        long* arr = new long[n];
        long* inc = new long[n]{0};
        for (int i = 0; i < n; ++i) std::cin >> arr[i];
        std::sort(arr, arr+n);
        count2 = getOperation(arr[0]);
        for (int i = 1; i < n; ++i) {
            count2 += getOperation(arr[i]);
            arr[i] += inc[i-1];
            inc[i] = inc[i-1] + arr[i] - arr[i-1];
            count += getOperation(inc[i] - inc[i-1]);
        }
        std::cout << ((count2 < count) ? count2 : count) << std::endl;
    }
    return 0;
}