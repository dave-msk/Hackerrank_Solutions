#include <iostream>
#include <string>
#include <queue>

int main() {
    int t, n, row, col;
    std::cin >> t;
    std::string s1, s2;
    bool **arr;
    while (t--) {
        std::cin >> n >> s1 >> s2;
        arr = new bool*[2];
        arr[0] = new bool[n];
        arr[1] = new bool[n];
        std::queue<std::pair<int,int>> q;
        for (int i = 0; i < n; ++i) {
            arr[0][i] = s1[i] == '1';
            arr[1][i] = s2[i] == '1';
            if (q.empty() && !arr[0][i]) q.push(std::make_pair(0,i));
            else if (q.empty() && !arr[1][i]) q.push(std::make_pair(1,i));
        }

        col = 0;
        int componentCount = 0;
        while (col < n) {
            componentCount = 0;
            while (!q.empty()) {
                row = q.front().first;
                col = q.front().second;
                q.pop();

                if (!arr[row][col]) {
                    arr[row][col] = 1;
                    ++componentCount;
                }
                if (row && col+1 < n && !arr[0][col+1]) {
                    arr[0][col+1] = 1;
                    q.push(std::make_pair(0,col+1));
                    ++componentCount;
                } else if (!row && !arr[1][col]) {
                    arr[1][col] = 1;
                    q.push(std::make_pair(1,col));
                    ++componentCount;
                }
                if (col+1 < n && !arr[row][col+1]) {
                    arr[row][col+1] = 1;
                    q.push(std::make_pair(row,col+1));
                    ++componentCount;
                }
            }
            if (componentCount & 1) {
                std::cout << "NO" << std::endl;
                break;
            }
            while (col < n) {
                if (!arr[0][col]) {
                    q.push(std::make_pair(0,col));
                    break;
                } else if (!arr[1][col]) {
                    q.push(std::make_pair(1,col));
                    break;
                }
                ++col;
            }
        }
        if (componentCount % 2 == 0) std::cout << "YES" << std::endl;

        delete[] arr[0], arr[1], arr;
    }
    return 0;
}