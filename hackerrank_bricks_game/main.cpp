#include <iostream>

int main() {
    int t;
    long n, a1, a2, a3;
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        long* arr = new long[n];
        long* first = new long[n+1]{0};
        long* second = new long[n+1]{0};
        for (long i = 0; i < n; ++i) std::cin >> arr[i];
        for (long i = 1; i <= n; ++i) {
            if (i < 4) {
                first[i] = arr[n-i] + first[i-1];
            } else {
                a1 = arr[n-i] + second[i-1];
                a2 = arr[n-i] + arr[n-i+1] + second[i-2];
                a3 = arr[n-i] + arr[n-i+1] + arr[n-i+2] + second[i-3];
                if (a1 >= a2 && a1 >= a3) {
                    first[i] = a1;
                    second[i] = first[i-1];
                } else if (a2 >= a1 && a2 >= a3) {
                    first[i] = a2;
                    second[i] = first[i-2];
                } else {
                    first[i] = a3;
                    second[i] = first[i-3];
                }
            }
        }
        std::cout << first[n] << std::endl;

        delete[] arr, first, second;
    }
    return 0;
}