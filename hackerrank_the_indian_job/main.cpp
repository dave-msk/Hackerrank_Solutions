#include <iostream>

int main() {
    int t, n;
    long G, sum;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> G;
        sum = 0;
        int* arr = new int[n];
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
            sum += arr[i];
        }

        if (sum > 2*G) {
            std::cout << "NO" << std::endl;
            continue;
        } else if (sum <= G) {
            std::cout << "YES" << std::endl;
            continue;
        }

        bool** dp = new bool*[n+1];
        for (int i = 0; i <= n; ++i) dp[i] = new bool[sum+1]{0};
        dp[1][arr[0]] = 1;
        for (int i = 0; i <= n; ++i) dp[i][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (long s = 1; s <= sum; ++s) {
                if (dp[i-1][s]) dp[i][s] = 1;
                else if (s >= arr[i-1] && dp[i-1][s-arr[i-1]]) dp[i][s] = 1;
            }
        }

        bool found = false;

        for (long s = sum - G; s <= G; ++s) found |= dp[n][s];

        std::cout << ((found) ? "YES" : "NO") << std::endl;

        for (int i = 0; i <= n; ++i) delete[] dp[i];
        delete[] dp, arr;
    }
    return 0;
}