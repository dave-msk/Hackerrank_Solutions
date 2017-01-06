#include <iostream>
#include <map>

int main() {
    long n, k, a;
    std::cin >> n >> k;
    std::map<long,long> map;
    while (n--) {
        std::cin >> a;
        a %= k;
        if (map.find(a) == map.end()) map[a] = 1;
        else ++map[a];
    }

    long count = 0;
    if (map.find(0) != map.end()) count += map[0] * (map[0]-1)/2;
    if (k % 2 == 0 && map.find(k/2) != map.end()) count += map[k/2]*(map[k/2]-1)/2;
    for (long i = 1; i < (k+1)/2; ++i) {
        if (map.find(i) != map.end() && map.find(k-i) != map.end())
            count += map[i] * map[k-i];
    }
    std::cout << count << std::endl;
    return 0;
}