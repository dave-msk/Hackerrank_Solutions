#include <iostream>

class BitTree{
    long* tree;
    long size;
public:
    BitTree(long size) {
        tree = new long[size+1]{0};
        this->size = size + 1;
    }

    ~BitTree() {
        delete[] tree;
    }

    void add(long idx, long value) {
        while (idx < size) {
            tree[idx] += value;
            idx += (idx & -idx);
        }
    }

    long sum(long idx) {
        long sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
};

int main() {

    int t;
    long N, a, nMax, max;
    std::cin >> t;
    long* min;
    while (t--) {
        nMax = 0;
        max = 0;
        std::cin >> N;
        if (N == 1) {
            std::cin >> a;
            std::cout << a << " " << a << std::endl;
            continue;
        }
        BitTree* tree = new BitTree(N);
        min = new long[N+1]{0};
        for (int i = 1; i <= N; ++i) {
            std::cin >> a;
            if (i == 1) max = a;
            else max = (a > max) ? a : max;
            if (a > 0) nMax += a;
            tree->add(i, a);
        }
        if (max < 0) {
            std::cout << max << " " << max << std::endl;
            continue;
        }

        for (long i = 1; i <= N; ++i) {
            a = tree->sum(i);
            if (i == 1) max = a;
            min[i] = (min[i-1] < a) ? min[i-1] : a;
            if (a - min[i] > max) max = a - min[i];
        }
        std::cout << max << " " << nMax << std::endl;
        delete[] min;
        delete tree;
    }
    return 0;
}