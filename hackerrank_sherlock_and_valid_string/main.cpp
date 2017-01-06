#include <iostream>
#include <string>
#include <map>
#include <set>

int main() {
    std::string s;
    std::cin >> s;
    long arr[26]{0};
    for (std::string::size_type i = 0; i < s.size(); ++i) ++arr[s[i]-'a'];
    std::map<long,std::set<int>> map;
    for (int i = 0; i < 26; ++i) if (arr[i] > 0) map[arr[i]].insert(i);
    if (map.size() == 1) std::cout << "YES" << std::endl;
    else if (map.size() > 2) std::cout << "NO" << std::endl;
    else {
        if (map.rbegin()->first - map.begin()->first == 1 && map.rbegin()->second.size() == 1)
            std::cout << "YES" << std::endl;
        else if (map.begin()->first == 1 && map.begin()->second.size() == 1)
            std::cout << "YES" << std::endl;
        else
            std::cout << "NO" << std::endl;
    }

    return 0;
}