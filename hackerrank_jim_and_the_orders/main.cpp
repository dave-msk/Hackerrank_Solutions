#include <cstdio>
#include <algorithm>

int main() {
    int N;
    scanf("%d", &N);
    long t, d;
    long *T = new long[N];
    long *arr = new long[N];
    for (int i = 0; i < N; ++i) {
        scanf("%ld %ld", &t, &d);
        T[i] = t+d;
        arr[i] = i;
    }
    auto compare = [&](int i, int j) {
        return std::make_pair(T[i], i) < std::make_pair(T[j], j);
    };
    std::sort(arr, arr+N, compare);
    for (int i = 0; i < N; ++i) printf("%ld ", arr[i]+1);
    printf("\n");
    delete[] T, arr;

    return 0;
}