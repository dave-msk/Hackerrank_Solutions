#include <iostream>
#include <map>

class BITtree {
    long* tree;
    long size;
public:
    BITtree(long size) {
        tree = new long[size+1]{0};
        this->size = size+1;
    }

    ~BITtree() {
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
    std::map<long,long> map;
    long* lvs, *rvs, *lps, *rps;
    long N,M,L,R;
    std::cin >> N >> M;
    lvs = new long[N]{0};
    rvs = new long[N]{0};
    lps = new long[M]{0};
    rps = new long[M]{0};

    for (long i = 0; i < N; ++i) {
        std::cin >> L >> R;
        map[L] = 0;
        map[R] = 0;
        lvs[i] = L;
        rvs[i] = R;
    }

    for (long i = 0; i < M; ++i) {
        std::cin >> L >> R;
        map[L] = 0;
        map[R] = 0;
        lps[i] = L;
        rps[i] = R;
    }


    long index = 0;
    for (auto it : map) {
        map[it.first] = ++index;
    }
    BITtree tree1(index), tree2(index);
    tree1.add(1,N);

    for (long i = 0; i < N; ++i) {
        tree1.add(map[lvs[i]], -1);
        tree2.add(map[rvs[i]], 1);
    }
    long count = 0;
    for (long i = 0; i < M; ++i) {
        count += N - tree1.sum(map[rps[i]]) - tree2.sum(map[lps[i]]-1);
    }

    std::cout << count << std::endl;

    return 0;
}