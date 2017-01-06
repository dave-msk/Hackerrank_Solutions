#include <cstdio>

int main() {
    long N, K, num, tmp;
    scanf("%ld %ld", &N, &K);
    if (K >= N) {
        while (N) printf("%ld ", N--);
        return 0;
    }
    long *arr = new long[N];
    long *rev = new long[N];
    for (long i = 0; i < N; ++i) {
        scanf("%ld", &num);
        arr[i] = num-1;
        rev[num-1] = i;
    }
    for (long i = 0; i < N; ++i) {
        if (arr[i] != N-1-i && K > 0) {
            tmp = arr[i];
            arr[i] = N-1-i;
            arr[rev[N-1-i]] = tmp;
            rev[tmp] = rev[N-1-i];
            rev[N-1-i] = i;
            --K;
        }
        printf("%ld ", arr[i]+1);
    }

    return 0;
}