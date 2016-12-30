#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>

int main() {
    int T, N, M, u, v;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        std::cin >> N;
        std::vector<int>* adList = new std::vector<int>[100];
        std::map<int,int> portals;
        for (int i = 0; i < N; ++i) {
            std::cin >> u >> v;
            portals[u] = v;
        }
        std::cin >> M;
        for (int i = 0; i < M; ++i) {
            std::cin >> u >> v;
            portals[u] = v;
        }

        for (int i = 1; i < 100; ++i) {
            for (int j = 1; j <= 6; ++j) {
                if (i+j <= 100) {
                    if (portals.find(i+j) != portals.end()) adList[i].push_back(portals[i+j]);
                    else adList[i].push_back(i+j);
                }
            }
        }

        std::queue<int> q;
        std::set<int> checked;
        int node, count, round = 0, nextCount = 1;
        bool found = false;
        q.push(1);
        checked.insert(1);
        while (!q.empty() && !found) {
            count = nextCount;
            ++round;
            nextCount = 0;
            for (int i = 0; i < count; ++i) {
                node = q.front();
                q.pop();
                for (int j : adList[node]) {
                    if (j == 100) {
                        found = true;
                        break;
                    }
                    if (checked.find(j) == checked.end()) {
                        checked.insert(j);
                        q.push(j);
                        ++nextCount;
                    }
                }
                if (found) break;
            }
        }
        std::cout << ((found) ? round : -1) << std::endl;
    }
    return 0;
}