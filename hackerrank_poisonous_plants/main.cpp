#include <iostream>
#include <stack>

int main() {
    long N;
    std::cin >> N;
    std::stack<std::pair<long,long>> stk;
    long value, daysToDie, maxDaysToDie = -1;
    std::cin >> value;
    stk.push(std::make_pair(value, -1));
    for (long i = 1; i < N; ++i) {
        daysToDie = 1;
        std::cin >> value;
        while (!stk.empty() && value <= stk.top().first) {
            daysToDie = std::max(daysToDie, stk.top().second + 1);
            stk.pop();
        }
        if (stk.empty()) daysToDie = -1;
        maxDaysToDie = std::max(maxDaysToDie, daysToDie);
        stk.push(std::make_pair(value, daysToDie));
    }

    std::cout << ((maxDaysToDie < 0) ? 0 : maxDaysToDie) << std::endl;
    return 0;
}