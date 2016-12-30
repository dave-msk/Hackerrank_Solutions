#include <iostream>
#include <string>

bool transformable(const std::string &s1, const std::string &s2) {

    int idx1 = 0, idx2 = 0;
    char c1;
    for (int i = 0; i < s1.size(); ++i) {
        c1 = s1[i];
        if (islower(c1)){
            if (toupper(c1) == s2[idx1]) ++idx1;
        }
        else {
            if (idx2 >= s2.size()) return false;
            if (c1 == s2[idx1]) {
                ++idx1;
                idx2 = idx1;
            } else if (c1 == s2[idx2]) {
                ++idx2;
                idx1 = idx2;
            } else {
                return false;
            }
        }
    }
    return idx1 >= s2.size();
}

int main() {
    int q;
    std::cin >> q;
    std::string s1, s2;
    while (q--) {
        std::cin >> s1 >> s2;
        std::cout << ((transformable(s1,s2)) ? "YES" : "NO") << std::endl;
    }
    return 0;
}