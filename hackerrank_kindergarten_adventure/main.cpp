#include <iostream>

long toIndex(long n, long N) {
    return (n < 0) ? (n + N) : (n % N);
}

int main() {

    long N, t;

    std::cin >> N;
    long* netArr = new long[N];

    for (long i = 0; i < N; ++i) {
        std::cin >> t;
        if (t == 0 || t == N) continue;
        ++netArr[(i+1) % N];
        --netArr[toIndex((i-t+1), N)];
    }

    long max = netArr[0];
    long count = 0;
    long index = 0;
    for (long i = 0; i < N; ++i) {
        count += netArr[i];
        if (count > max) {
            index = i;
            max = count;
        }
    }
    std::cout << index+1 << std::endl;
    return 0;
}