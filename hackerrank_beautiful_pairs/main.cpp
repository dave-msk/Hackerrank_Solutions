#include <iostream>
#include <algorithm>

int main() {
    int n, *A, *B, count = 0;
    std::cin >> n;
    A = new int[n];
    B = new int[n];
    for (int i = 0; i < n; ++i) std::cin >> A[i];
    for (int i = 0; i < n; ++i) std::cin >> B[i];
    std::sort(A,A+n);
    std::sort(B,B+n);
    for (int i = 0; i < n; ++i) std::cout << A[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < n; ++i) std::cout << B[i] << " ";
    std::cout << std::endl;
    int i = 0, j = 0;
    while (i < n && j < n) {
        if (A[i] == B[j]) {
            ++count;
            ++i;
            ++j;
        } else if (A[i] < B[j]) ++i;
        else ++j;
    }
    std::cout << ((count < n) ? count + 1 : count-1) << std::endl;
    return 0;
}