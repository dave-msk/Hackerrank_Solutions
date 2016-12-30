#include <iostream>
#include <vector>

int main() {

    int t, n;
    std::cin >> t;
    unsigned long long a;
    while (t--) {
        std::cin >> n;
        std::vector<unsigned long long> v;
        for (int i = 0; i < n; ++i) {
            std::cin >> a;
            v.push_back(a);
        }
        if (n == 1) {
            if (v[0] == 1) std::cout << 2 << std::endl;
            else std::cout << 3 << std::endl;
            std::cout << "1 1 ";
            if (v[0]-1) std::cout << v[0]-1;
            std::cout << std::endl;
            continue;
        } else if (n == 2) {
            if (v[0] == 1) std::cout << 2 << std::endl;
            else std::cout << 3 << std::endl;
            std::cout << "1 ";
            if (v[0] == 1) std::cout << v[1]+1;
            else std::cout << v[1]+1 << " " << v[0]-1;
            std::cout << std::endl;
            continue;
        }

        if (n & 1) {
            if (v[n-2] == 1) {
                v[n-3] += 1;
                if (v[n-1] == 1) v.pop_back();
                else v[n-1] -= 1;
            } else {
                if (v[n-1] == 1) v.pop_back();
                else v[n-1] -= 1;
                v[n-2] -= 1;
                v.insert(v.begin()+n-1,1);
                v.insert(v.begin()+n-1,1);
            }
        } else {
            if (v[n-3] == 1) {
                v[n-4] += 1;
                v[n-3] += v[n-1];
                v[n-2] -= 1;
                v.pop_back();
                if (!v.back()) v.pop_back();
            } else {
                v[n-3] -= 1;
                v[n-1] += 1;
                if (v[n-2] > 1) {
                    v.push_back(v[n-2]-1);
                    v[n-2] = 1;
                }
            }
        }
        std::cout << v.size() << std::endl;
        for (std::vector<unsigned long long>::size_type i = 0; i < v.size(); ++i) std::cout << v[i] << " ";
        std::cout << std::endl;
    }

    return 0;
}