#include <iostream>
#include <map>

class BitTree {
    long* tree;
    long size;
public:
    BitTree(long size) {
        tree = new long[size+1]{0};
        this->size = size+1;
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


    int t, n;
    long y;
    std::cin >> t;
    double sum = 0;
    double num;
    while (t--) {
        std::cin >> n;
        sum = 0;
        num = n+1.0;
        int *arr = new int[n];
        BitTree tree(1000);
        for (int i = 0; i < n; ++i) {
            std::cin >> arr[i];
            tree.add(arr[i], 1);
        }
        for (int i = 0; i < n; ++i) {
            y = n - tree.sum(arr[i]-1);
            sum += num / (y+1);
        }
        std::printf("%.2lf\n", sum);
    }
    return 0;
}