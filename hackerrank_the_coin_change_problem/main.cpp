#include <iostream>
#include <algorithm>

int main() {
    int N, M;
    std::cin >> N >> M;
    int* C = new int[M];
    int c;
    for (int i = 0; i < M; ++i) std::cin >> C[i];
    std::sort(C, C+M);
    long* arr = new long[N]{0};
    for (int i = 0; i < M; ++i) {
        c = C[i];
        for (int j = 0; j < N; ++j) {
            if (j+1 < c) continue;
            else if (j+1 == c) arr[j] += 1;
            else arr[j] += arr[j-c];
        }
    }
    std::cout << arr[N-1] << std::endl;
    return 0;
}