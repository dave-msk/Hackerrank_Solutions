#include <iostream>

int main() {
    int N, H, I, p, P;
    std::cin >> N >> H >> I;
    int** arr = new int*[H];
    for (int h = 0; h < H; ++h) arr[h] = new int[N]{0};
    for (int n = 0; n < N; ++n) {
        std::cin >> P;
        for (int i = 0; i < P; ++i) {
            std::cin >> p;
            ++arr[H-p][n];
        }
    }

    long** matrix = new long*[H];
    for (int h = 0; h < H; ++h) matrix[h] = new long[N];
    long** maxTwo = new long*[H-I];
    for (int h = 0; h < H-I; ++h) maxTwo[h] = new long[3]{0};
    long max = 0;
    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            if (h == 0) matrix[h][n] = arr[h][n];
            else if (h < I) matrix[h][n] = matrix[h-1][n] + arr[h][n];
            else matrix[h][n] = std::max(matrix[h-1][n], (maxTwo[h-I][2] == n) ? maxTwo[h-I][0] : maxTwo[h-I][1]) + arr[h][n];
            if (h == H-1 && max < matrix[h][n]) max = matrix[h][n];
            if (h < H-I && matrix[h][n] > maxTwo[h][1]) {
                maxTwo[h][0] = maxTwo[h][1];
                maxTwo[h][1] = matrix[h][n];
                maxTwo[h][2] = n;
            }
        }
    }

    std::cout << max << std::endl;

    for (int i = 0; i < H; ++i) {
        if (i < I) delete[] maxTwo[i];
        delete[] arr[i], matrix[i];
    }

    delete[] arr, matrix, maxTwo;

    return 0;
}