#include <iostream>
#include <stack>

int main() {
    long N, h, count, h1, route = 0;
    std::cin >> N;
    std::stack<long> stk;
    for (long i = 0; i < N; ++i) {
        std::cin >> h;
        count = 0;
        h1 = 0;
        while (!stk.empty() && stk.top() < h) {
            if (stk.top() == h1) {
                ++count;
            } else {
                route += count * (count-1);
                h1 = stk.top();
                count = 1;
            }
            stk.pop();
        }
        route += count * (count-1);
        stk.push(h);
    }

    count = 0;
    h1 = 0;
    while (!stk.empty()) {
        if (stk.top() == h1) ++count;
        else {
            route += count * (count-1);
            h1 = stk.top();
            count = 1;
        }
        stk.pop();
    }
    route += count * (count-1);

    std::cout << route << std::endl;
    return 0;
}