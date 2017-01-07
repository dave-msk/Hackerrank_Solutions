#include <cstdio>
#include <vector>
#include <stack>
#include <set>
#include <stdlib.h>

int main() {
    long n, u, v, sum = 0, idx, min;
    scanf("%ld", &n);
    long *data = new long[n];
    long *subSum = new long[n]{0};
    std::vector<long> *adList = new std::vector<long>[n];
    for (long i = 0; i < n; ++i) {
        scanf("%ld", data+i);
        sum += data[i];
    }
    min = sum;

    for (long i = 0; i < n-1; ++i) {
        scanf("%ld %ld", &u, &v);
        adList[u-1].push_back(v-1);
        adList[v-1].push_back(u-1);
    }
    std::set<long> checked;
    std::stack<std::pair<long,long>> stack;
    // checked.insert(0);
    stack.push(std::make_pair(0,0));
    while (!stack.empty()) {
        u = stack.top().first;
        checked.insert(u);
        idx = stack.top().second;
        if (idx < adList[u].size()) {
            v = adList[u][idx];
            if (checked.find(v) != checked.end()) {
                ++stack.top().second;
                continue;
            }
            stack.push(std::make_pair(v,0));
            continue;
        }
        for (long i = 0; i < adList[u].size(); ++i) subSum[u] += subSum[adList[u][i]];
        subSum[u] += data[u];
        if (min > labs(sum - 2*subSum[u])) min = labs(sum - 2*subSum[u]);
        stack.pop();
    }
    printf("%ld\n", min);
    delete[] data, subSum, adList;

    return 0;
}