#include <iostream>
#include <cmath>



bool isPrime(unsigned long long n) {
    if (n == 1 || n == 0) return false;
    if (n == 2 || n == 3 || n == 5) return true;
    for (unsigned long long i = 2; i <= std::sqrt(n)+1; ++i) if (n % i == 0) return false;
    return true;
}

long countPrimes(unsigned long long sum) {
    long count = 0;
    while (sum) if (isPrime(sum--)) ++count;
    return count;
}

int main() {
    int t, N, K;
    std::cin >> t;
    unsigned long long sum, component;
    while (t--) {
        std::cin >> N;
        K = N/4;
        sum = 1;
        for (int k = 1; k <= K; ++k) {
            component = 1;
            for (int j = 1; j <= k; ++j) component = component * (N-4*k+j)/j;
            sum += component;
        }
        std::cout << countPrimes(sum) << std::endl;
    }
    return 0;
}