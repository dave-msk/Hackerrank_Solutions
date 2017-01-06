#include <cstdio>
#include <algorithm>

int main() {
    long N;
    scanf("%ld", &N);
    int *w = new int[N];
    for (long i = 0; i < N; ++i) scanf("%d", w+i);
    std::sort(w, w+N);
    int count = 0;
    int cw = -5;
    for (long i = 0; i < N; ++i) {
        if (w[i] <= cw + 4) continue;
        cw = w[i];
        ++count;
    }
    printf("%d\n", count);
    return 0;
}