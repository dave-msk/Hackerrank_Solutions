#include <iostream>

long getRoot(long* arr, long node) {
    while (arr[node] != node) node = arr[node];
    return node;
}

void merge(long* arr, long* size, long node1, long node2, long &max) {
    node1 = getRoot(arr, node1);
    node2 = getRoot(arr, node2);
    if (node1 == node2) return;
    else if (node2 < node1) {
        long tmp = node2;
        node2 = node1;
        node1 = tmp;
    }
    arr[node2] = node1;
    size[node1] += size[node2];
    if (max < size[node1]) max = size[node1];
}

int main() {
    long N, node1, node2;
    std::cin >> N;
    long* arr = new long[2*N];
    long* size = new long[2*N];
    long max = 0;
    for (long i = 0; i < 2*N; ++i) {
        arr[i] = i;
        size[i] = 1;
    }

    for (long i = 0; i < N; ++i) {
        std::cin >> node1 >> node2;
        merge(arr, size, node1-1, node2-1, max);
    }
    long min = 2*N;
    for (long i = 0; i < 2*N; ++i) {
        if (arr[i] != i) continue;
        if (size[i] == 1) continue;
        if (size[i] < min) min = size[i];
    }

    std::cout << min << " " << max << std::endl;

    return 0;
}