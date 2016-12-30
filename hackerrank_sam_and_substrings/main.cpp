#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    const long MOD = 1000000007;
    long result = 0;
    long f = 1;
    for (long i = s.size()-1; i >= 0; --i) {
        result = (result + (s[i]-'0')*(i+1)*f) % MOD;
        f = (f*10 + 1) % MOD;
    }
    std::cout << result << std::endl;
    return 0;
}