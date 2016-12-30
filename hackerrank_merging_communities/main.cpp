#include <iostream>
#include <set>
#include <map>

long getRoot(long* arr, long node) {
    while (arr[node] != node) node = arr[node];
    return node;
}

void merge(long* arr, long* size, long node1, long node2) {
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
}

int main() {
    long N, Q, node1, node2;
    char q;
    std::cin >> N >> Q;
    long* arr = new long[N];
    long* size = new long[N];
    for (long i = 0; i < N; ++i) {
        arr[i] = i;
        size[i] = 1;
    }
    for (long i = 0; i < Q; ++i) {
        std::cin >> q;
        if (q == 'Q') {
            std::cin >> node1;
            std::cout << size[getRoot(arr, node1-1)] << std::endl;
        } else if (q == 'M') {
            std::cin >> node1 >> node2;
            merge(arr, size, node1-1, node2-1);
        }
    }
    return 0;
}