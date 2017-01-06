#include <iostream>
#include <string>

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;
    int** matrix = new int*[s1.size()+1];
    for (int i = 0; i < s1.size()+1; ++i) matrix[i] = new int[s2.size()+1]{0};
    for (int i = 1; i <= s1.size(); ++i) {
        for (int j = 1; j <= s2.size(); ++j) {
            if (s1[i-1] == s2[j-1]) matrix[i][j] = matrix[i-1][j-1] + 1;
            else matrix[i][j] = std::max(matrix[i-1][j], matrix[i][j-1]);
        }
    }
    std::cout << matrix[s1.size()][s2.size()] << std::endl;
    for (int i = 0; i < s1.size()+1; ++i) delete[] matrix[i];
    delete[] matrix;
    return 0;
}