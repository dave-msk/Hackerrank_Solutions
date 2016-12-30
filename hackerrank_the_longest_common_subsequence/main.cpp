#include <iostream>
#include <stack>

int main() {
    int n, m;
    std::cin >> n >> m;
    int* arr1 = new int[n];
    int* arr2 = new int[m];
    for (int i = 0; i < n; ++i) std::cin >> arr1[i];
    for (int i = 0; i < m; ++i) std::cin >> arr2[i];
    int** matrix = new int*[m+1];
    for (int i = 0; i < m+1; ++i) matrix[i] = new int[n+1]{0};
    for (int i = 1; i < m+1; ++i) {
        for (int j = 1; j < n+1; ++j) {
            if (arr2[i-1] == arr1[j-1]) matrix[i][j] = matrix[i-1][j-1]+1;
            else matrix[i][j] = std::max(matrix[i][j-1], matrix[i-1][j]);
        }
    }
    int i = m, j = n;
    std::stack<int> subseq;
    while (i > 0 && j > 0) {
        if (matrix[i][j-1] == matrix[i][j]) --j;
        else if (matrix[i-1][j] == matrix[i][j]) --i;
        else {
            subseq.push(arr1[--j]);
            --i;
        }
    }

    while (!subseq.empty()) {
        std::cout << subseq.top() << " ";
        subseq.pop();
    }

    return 0;
}