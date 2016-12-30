#include <cmath>
#include <iostream>
#include <queue>
#include <set>

int main() {
    int Q, round, count, num;
    long N;
    std::cin >> Q;
    bool found;
    for (int i = 0; i < Q; ++i) {
        std::cin >> N;
        std::queue<long> q;
        std::set<long> s;
        q.push(N);
        s.insert(N);
        round = 0;
        count = 1;
        found = false;
        long min = N;
        while (!found) {
            ++round;
            num = count;
            count = 0;
            // std::cout << round << ": ";
            for (int j = 0; j < num; j++) {
                N = q.front();
                // std::cout << N << " ";
                q.pop();
                if (found) {
                    if (min > N) min = N;
                    continue;
                }
                if (N <= 3) {
                    min = N;
                    found = true;
                }
                for (int k = 2; k <= std::sqrt(N+1); ++k) {
                    if (N % k == 0) {
                        if (s.find(N/k) == s.end()) {
                            s.insert(N/k);
                            q.push(N/k);
                            ++count;
                        }
                    }
                }
                if (s.find(N-1) == s.end()) {
                    s.insert(N-1);
                    q.push(N-1);
                    ++count;
                }
            }
            // std::cout << std::endl;
        }
        std::cout << round + min -1 << std::endl;
    }
    return 0;
}