#include <iostream>
#include <vector>
#include <set>
#include <queue>

int main() {

    int q, n, u, v, s;
    long m;
    std::cin >> q;
    for (int qi = 0; qi < q; ++qi) {
        std::cin >> n >> m;
        std::vector<int>* map = new std::vector<int>[n+1];
        int* dist = new int[n+1];
        for (int i = 0; i < n+1; ++i) dist[i] = -1;
        for (int i = 0; i < m; ++i) {
            std::cin >> u >> v;
            map[u].push_back(v);
            map[v].push_back(u);
        }
        std::cin >> s;

        std::queue<int> queue;
        std::set<int> checked;
        queue.push(s);
        checked.insert(s);

        int count = 1;
        int nextCount = 0;
        int distMult = 1;

        while (!queue.empty()) {
            for (int j = 0; j < count; ++j) {
                u = queue.front();
                queue.pop();
                for (int w : map[u]) {
                    if (checked.find(w) == checked.end()) {
                        dist[w] = distMult;
                        checked.insert(w);
                        ++nextCount;
                        queue.push(w);
                    }
                }
            }
            count = nextCount;
            nextCount = 0;
            ++distMult;
        }
        for (int i = 1; i <= n; ++i) {
            if (i == s) continue;
            std::cout << ((dist[i] == -1) ? -1 : 6*dist[i]) << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}