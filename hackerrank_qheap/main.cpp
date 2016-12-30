#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    long Q, v;
    int q;
    std::cin >> Q;
    std::vector<long> vector;
    for (long i = 0; i < Q; ++i) {
        std::cin >> q;
        if (q == 1) {
            std::cin >> v;
            vector.push_back(v);
            std::push_heap(vector.begin(), vector.end(), std::greater<long>());
        } else if (q == 2) {
            std::cin >> v;
            for (long j = 0; j < vector.size(); ++j) {
                if (vector[j] == v) {
                    vector.erase(vector.begin()+j);
                    if (j == 0) std::make_heap(vector.begin(), vector.end(), std::greater<long>());
                    break;
                }
            }

        } else if (q == 3) {
            std::cout << vector.front() << std::endl;
        }
    }
    return 0;
}