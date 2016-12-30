#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>

int main() {

    long N, node1, node2;
    std::cin >> N;
    std::vector<long>* map = new std::vector<long>[N+1];
    long* tree = new long[N+1]{0};

    for (long i = 0; i < N-1; ++i) {
        std::cin >> node1 >> node2;
        map[node1].push_back(node2);
        map[node2].push_back(node1);
    }

    std::queue<long> q;
    q.push(1);
    tree[1] = 1;

    while (!q.empty()) {
        node1 = q.front();
        q.pop();
        for (node2 : map[node1]) {
            if (tree[node2] == 0) {
                tree[node2] = node1;
                q.push(node2);
            }
        }
    }

    // for (long i = 1; i <= N; ++i) std::cout << tree[i] << " ";

    long count = N + 1;
    for (long len = 2; len < N; ++len) {
        std::deque<long> dq;
        for (long i = 1; i <= len-1; ++i) {
            if (tree[i] > len) continue;
            auto it = std::lower_bound(dq.begin(), dq.end(), tree[i]);
            dq.insert(it,tree[i]);
        }

        for (long i = len; i <= N; ++i) {
            auto it = std::lower_bound(dq.begin(), dq.end(), tree[i-len]);
            if (*it == tree[i-len]) dq.erase(it);
            it = std::lower_bound(dq.begin(), dq.end(), tree[i]);
            dq.insert(it, tree[i]);
            while (!dq.empty() && dq.front() < i-len+1) dq.pop_front();
            while (!dq.empty() && dq.back() > i) dq.pop_back();
            if (dq.size() == len || dq.size() == len-1) ++count;
        }
        // std::cout << count << std::endl;
    }
    std::cout << count << std::endl;


    return 0;
}