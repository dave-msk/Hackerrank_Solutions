#include <iostream>
#include <string>
#include <vector>

int main() {

    long N, K;
    std::string s;
    std::vector<bool> t;
    std::cin >> N >> K >> s;

    bool key = s[0] == '1';
    t.push_back(s[0] == '1');

    for (long i = 1; i < N; ++i) {
        t.push_back((s[i] == '1')^key);
        if (i -K +1 >= 0) key ^= t[i-K+1];
        key ^= t.back();
    }

    for (long i = 0; i < t.size(); ++i) std::cout << t[i];
    std::cout << std::endl;

    return 0;
}