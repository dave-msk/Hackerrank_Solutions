#include <iostream>
#include <queue>
#include <set>

int main() {
    int t, n, k, node, max;
    std::cin >> t;
    while (t--) {
        std::cin >> n >> k;
        std::set<int> set;
        std::queue<int> queue;
        queue.push(0);
        int* arr = new int[n];
        for (int i = 0; i < n; ++i) std::cin >> arr[i];
        max = 0;
        while (!queue.empty()) {
            node = queue.front();
            queue.pop();
            for (int i = 0; i < n; ++i) {
                if (node + arr[i] <= k && set.find(node+arr[i]) == set.end()) {
                    set.insert(node + arr[i]);
                    queue.push(node + arr[i]);
                    if (node + arr[i] > max) max = node + arr[i];
                }
            }
        }
        std::cout << max << std::endl;
    }
    return 0;
}