#include <iostream>

int main() {
    const long MOD = 1000000007;
    long long N, n, p, h, d;
    int a;
    std::cin >> N;
    n = 1;
    p = 0;
    h = 0;
    d = 0;
    for (long i = 0; i < N; ++i) {
        std::cin >> a;
        p = ((4*p % MOD) + ((12*n+8) % MOD)*h % MOD + (16*(n*n % MOD) + 12*n + 1) % MOD * a) % MOD;
        h = (4*h % MOD + 8*a*n % MOD + 3*a % MOD + (3*n+2) % MOD * d) % MOD;
        d = (2*d + 3*a) % MOD;
        n = (4*n + 2) % MOD;
    }
    std::cout << p << std::endl;
    return 0;
}