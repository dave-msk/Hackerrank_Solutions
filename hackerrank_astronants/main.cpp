#include <iostream>
#include <map>


long getRoot(long tree[], long idx) {
    while (tree[idx] != idx) idx = tree[idx];
    return idx;
}

int main() {

    long N, I, a1, a2, tmp;
    std::cin >> N >> I;
    long* tree = new long[N];
    long* counts = new long[N];
    for (long i = 0; i < N; ++i) {
        tree[i] = i;
        counts[i] = 1;
    }
    for (long i = 0; i < I; ++i) {
        std::cin >> a1 >> a2;
        a1 = getRoot(tree, a1);
        a2 = getRoot(tree, a2);
        if (a1 == a2) continue;
        if (a1 > a2) {
            tmp = a1;
            a1 = a2;
            a2 = tmp;
        }
        tree[a2] = a1;
        counts[a1] += counts[a2];
    }

    std::map<long, long> mapCount;
    long rootIndex;
    for (long i = 0; i < N; ++i) {
        rootIndex = getRoot(tree,i);
        mapCount[rootIndex] = counts[rootIndex];
    }

    long sqSum = 0, sum = 0;
    for (auto it : mapCount) {
        sum += it.second;
        sqSum += it.second * it.second;
    }

    std::cout << (sum * sum - sqSum)/2 << std::endl;
    return 0;
}