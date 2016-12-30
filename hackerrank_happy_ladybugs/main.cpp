#include <iostream>

using namespace std;

bool isHappy(std::string s) {
    char prev = s[0];
    bool currHappy = prev == '_';
    for (std::string::size_type i = 1; i < s.size(); ++i) {
        if (s[i] =='_') continue;
        else if (s[i] == prev) {
            currHappy = true;
        } else {
            if (currHappy) {
                currHappy = false;
                prev = s[i];
            } else return false;
        }
    }
    return currHappy;
}


int main(){
    int Q;
    cin >> Q;
    for(int a0 = 0; a0 < Q; a0++){
        int n;
        cin >> n;
        string b;
        cin >> b;
        bool hasEmpty = false;
        int hist[26]{0};
        for (int i = 0; i < b.size(); ++i) {
            if (b[i] == '_') {
                hasEmpty = true;
                continue;
            }
            ++hist[b[i] - 'A'];

        }
        bool odd = false;
        for (int i = 0; i < 26; ++i) if (hist[i] == 1) {odd = true; break;}
        if (isHappy(b)) std::cout << "YES" << std::endl;
        else if (odd) std::cout << "NO" << std::endl;
        else std::cout << ((hasEmpty) ? "YES" : "NO") << std::endl;
    }
    return 0;
}
