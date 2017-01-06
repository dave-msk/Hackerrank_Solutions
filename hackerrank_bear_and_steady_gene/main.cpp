#include <iostream>
#include <string>
#include <map>
#include <queue>

int main() {
    std::string s;
    long n;
    std::cin >> n >> s;
    long min = s.size();
    std::map<char,long> hist, thres, state;
    std::queue<char> queue;
    hist['A'] = 0, hist['C'] = 0, hist['G'] = 0, hist['T'] = 0;
    state['A'] = 0, state['C'] = 0, state['G'] = 0, state['T'] = 0;
    for (long i = 0; i < n; ++i) ++hist[s[i]];
    for (auto pair : hist) thres[pair.first] = (pair.second > n/4) ? pair.second - n/4 : 0;
    for (long i = 0; i < n; ++i) {
        queue.push(s[i]);
        ++state[s[i]];
        while (!queue.empty() && state[queue.front()] > thres[queue.front()]) {
            --state[queue.front()];
            queue.pop();
        }
        if (state['A'] >= thres['A'] && state['C'] >= thres['C'] &&
            state['G'] >= thres['G'] && state['T'] >= thres['T'] &&
            min > queue.size()) min = queue.size();
    }
    std::cout << min << std::endl;

    return 0;
}