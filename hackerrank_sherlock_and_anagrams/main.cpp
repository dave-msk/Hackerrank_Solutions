#include <iostream>
#include <string>
#include <algorithm>
#include <map>

void toCanonical(std::string &s) {
    std::sort(s.begin(), s.end());
}

int main() {

    int t;
    long count;
    std::string s, str;
    std::cin >> t;
    while (t--) {
        std::cin >> s;
        std::map<std::string, int> map;
        for (int i = 0; i < s.size(); ++i) {
            for (int l = 1; l < s.size()-i+1; ++l) {
                str = s.substr(i,l);
                toCanonical(str);
                if (map.find(str) == map.end()) map[str] = 1;
                else ++map[str];
            }
        }
        count = 0;
        for (auto pair : map) count += pair.second * (pair.second-1)/2;

        std::cout << count << std::endl;
    }
    return 0;
}