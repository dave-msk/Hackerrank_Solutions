#include <iostream>
#include <string>
#include <stack>

int main() {


    long Q;
    std::cin >> Q;
    std::string text;
    int q, n;
    std::string w;
    std::stack<std::pair<int,std::string>> history;

    for (long i = 0; i < Q; ++i) {
        std::cin >> q;
        if (q == 1) {
            std::cin >> w;
            text += w;
            history.push(std::make_pair(q,w));
        } else if (q == 2) {
            std::cin >> n;
            w = text.substr(text.size()-n);
            text.erase(text.size()-n);
            history.push(std::make_pair(q,w));
        } else if (q == 3) {
            std::cin >> n;
            std::cout << text[n-1] << std::endl;
        } else if (q == 4) {
            std::pair<int, std::string>& p = history.top();
            if (p.first == 1) {
                text.erase(text.size()-p.second.size());
            } else if (p.first == 2) {
                text += p.second;
            }
            history.pop();
        }
    }

    return 0;
}