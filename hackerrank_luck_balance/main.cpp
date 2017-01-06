#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int K, N, L, T;
    long sum = 0;
    scanf("%d %d", &N, &K);
    std::vector<int> vector;
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &L, &T);
        if (T) vector.push_back(L);
        else sum += L;
    }
    std::sort(vector.begin(), vector.end());
    while (!vector.empty()){
        L = vector.back();
        vector.pop_back();
        sum += (K-- > 0) ? L : -L;
    }
    printf("%ld\n",sum);
    return 0;
}