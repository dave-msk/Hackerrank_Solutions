#include <iostream>

int main() {
    int t;
    long N, bound, prevBound;
    std::cin >> t;
    while (t--) {
        std::cin >> N;
        std::cin >> prevBound;
        long** cost = new long*[2];
        cost[0] = new long[N]{0};
        cost[1] = new long[N]{0};
        for (long i = 1; i < N; ++i) {
            std::cin >> bound;
            cost[0][i] = std::max(cost[0][i-1] + std::abs(bound - prevBound), cost[1][i-1] + bound-1);
            cost[1][i] = std::max(cost[0][i-1] + prevBound-1, cost[1][i-1]);
            prevBound = bound;
        }
        std::cout << std::max(cost[0][N-1], cost[1][N-1]) << std::endl;
        delete[] cost[0], cost[1];
        delete[] cost;
    }
    return 0;
}