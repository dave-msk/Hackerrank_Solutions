#include <cstdio>
#include <algorithm>

int main() {
    long N, K, count = 0;
    scanf("%ld %ld", &N, &K);
    long *price = new long[N];
    for (long i = 0; i < N; ++i) scanf("%ld", price+i);
    std::sort(price, price+N);
    for (long i = 0; i < N; ++i) {
        if (K < price[i]) break;
        K -= price[i];
        ++count;
    }
    printf("%ld\n",count);
    return 0;
}