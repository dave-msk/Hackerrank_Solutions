#include <cstdio>
#include <deque>
#include <queue>
#include <set>


void readState(long state, long n, std::deque<int> *& deque) {
    int pile;
    for (int i = 0; i < 4; ++i) deque[i].clear();
    for (int i = 0; i < n; ++i) {
        pile = ((state >> 2*i+1) & 1)*2 + ((state >> 2*i) & 1);
        deque[pile].push_back(i);
    }
}

long writeState(int fromPile, int toPile, std::deque<int> const * deque) {
    long state = 0;
    int j;
    int num;
    for (int i = 0; i < 4; ++i) {
        j = 0;
        if (i == fromPile) {
            j = 1;
        } else if (i == toPile) {
            state |= (i << 2*deque[fromPile].front());
        }
        while (j < deque[i].size()) {
            num = deque[i][j++];
            state |= (i << 2*num);
        }
    }
    return state;
}

long writeState(std::deque<int> const * deque) {
    long state = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < deque[i].size(); ++j)
            state |= (i << 2*deque[i][j]);
    return state;
}

int main() {
    int n, pile;
    scanf("%d", &n);
    std::deque<int> *deque = new std::deque<int>[4];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &pile);
        deque[pile-1].push_back(i);
    }
    std::set<long> checked;
    std::queue<long> queue;
    long const targetState = writeState(deque);
    long state = 0;
    long count, nextCount = 1, round = 0;
    checked.insert(state);
    queue.push(state);
    while (!queue.empty()) {
        count = nextCount;
        nextCount = 0;
        ++round;
        for (long i = 0; i < count; ++i) {
            state = queue.front();
            queue.pop();
            readState(state,n,deque);
            for (int j = 0; j < 3; ++j) {
                for (int k = j+1; k < 4; ++k) {
                    if (deque[j].empty() && deque[k].empty()) continue;
                    if (deque[j].empty()) state = writeState(k,j,deque);
                    else if (deque[k].empty()) state = writeState(j,k,deque);
                    else {
                        if (deque[k].front() < deque[j].front()) state = writeState(k,j,deque);
                        else state = writeState(j,k,deque);
                    }
                    if (state == targetState) {
                        printf("%ld\n", round);
                        delete[] deque;
                        return 0;
                    }
                    if (checked.find(state) == checked.end()) {
                        ++nextCount;
                        checked.insert(state);
                        queue.push(state);
                    }
                }
            }
        }
    }

    delete[] deque;
    return 0;
}