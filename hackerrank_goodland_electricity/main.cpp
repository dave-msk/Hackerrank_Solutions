#include <cstdio>

int main() {
    long n, k;
    scanf("%ld %ld", &n, &k);
    unsigned tower;
    long lastCv = -1, lastTw = -1, count = 0;
    for (long i = 0; i < n; ++i) {
        scanf("%u",&tower);
        if (tower) lastTw = i;
        if (i-lastCv == k) {
            ++count;
            lastCv = lastTw+k-1;
        }
        if (i-lastCv >= k) {
            printf("-1\n");
            return 0;
        }
    }
    if (lastCv < n-1) {
        if (lastTw+k-1 >= n-1) printf("%ld\n", count+1);
        else printf("-1\n");
    } else printf("%ld\n",count);
    return 0;
}