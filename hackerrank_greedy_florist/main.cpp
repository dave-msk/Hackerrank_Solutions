#include <cstdio>
#include <algorithm>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    long *C = new long[N];
    int *T = new int[K]{0};
    for (int i = 0; i < N; ++i) scanf("%ld", C+i);
    std::sort(C, C+N);
    long sum = 0;
    for (int i = 0; i < N; ++i) sum += C[N-1-i] * ++T[i%K];
    printf("%ld\n", sum);
    delete[] C, T;
    return 0;
}