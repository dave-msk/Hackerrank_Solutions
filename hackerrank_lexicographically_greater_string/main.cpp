#include <iostream>
#include <string>
#include <vector>

int main() {
    long t;
    std::cin >> t;
    std::string s;
    char c;
    int index;
    while (t--) {

        std::cin >> s;
        c = s[s.size()-1];
        index = s.size()-1;
        std::vector<char> v;
        v.push_back(c);
        for (int i = s.size()-2; i >= 0; --i) {
            c = s[i];
            if (c >= v.back()) {
                --index;
                v.push_back(c);
            }
            else break;
        }

        if (index == 0) {
            std::cout << "no answer" << std::endl;
            continue;
        }

        std::cout << s.substr(0,index-1);

        c = s[index-1];

        for (int i = 0; i < v.size(); ++i) {
            if (v[i] > c) {
                std::cout << v[i];
                v[i] = c;
                break;
            }
        }

        for (int i = 0; i < v.size(); ++i) std::cout << v[i];
        std::cout << std::endl;

    }
    return 0;
}