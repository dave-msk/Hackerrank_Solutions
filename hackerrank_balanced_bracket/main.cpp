#include <iostream>
#include <stack>

using namespace std;

void checkBalance(std::string s) {
    std::stack<char> stk;
    char c;
    for (std::string::size_type i = 0; i < s.size(); ++i) {
        c = s[i];

        if (c == '(' || c == '[' || c == '{') stk.push(c);
        else if (c == ')') {
            if (stk.empty() || stk.top() != '(') {std::cout << "NO" << std::endl; return;}
            stk.pop();
        } else if (c == ']') {
            if (stk.empty() || stk.top() != '[') {std::cout << "NO" << std::endl; return;}
            stk.pop();
        } else if (c == '}') {
            if (stk.empty() || stk.top() != '{') {std::cout << "NO" << std::endl; return;}
            stk.pop();
        }
    }
    std::cout << ((stk.empty()) ? "YES" : "NO") << std::endl;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        checkBalance(s);
    }
    return 0;
}
