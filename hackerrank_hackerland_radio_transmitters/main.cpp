#include <cstdio>
#include <algorithm>

int main() {
    long n, k;
    scanf("%ld %ld", &n, &k);
    long *houses = new long[n];
    for (long i = 0; i < n; ++i) scanf("%ld", houses+i);
    std::sort(houses, houses+n);
    long lastUncv = houses[0];
    long lastCv = houses[0]-1;
    long lastTm = houses[0];
    long count = 0;
    for (long i = 1; i < n; ++i) {
        if (lastCv >= lastUncv) {
            lastUncv = houses[i];
        } else {
            if (houses[i] > lastUncv + k) {
                ++count;
                lastCv = lastTm + k;
                if (lastCv < houses[i]) lastUncv = houses[i];
            } else if (houses[i] == lastUncv + k) {
                ++count;
                lastCv = houses[i] + k;
            }
        }
        lastTm = houses[i];
    }
    if (lastCv < houses[n-1]) ++count;
    printf("%ld", count);
    delete[] houses;
    return 0;
}