#include <bits/stdc++.h>

bool checkGrid(char *grid, int N) {
    for (int j = 0; j < N; ++j)
        for (int i = 1; i < N; ++i)
            if (grid[i*N+j] < grid[(i-1)*N+j]) return 0;
    return 1;
}

void solve() {
    int N;
    scanf("%d", &N);
    char *grid = new char[N*N];
    for (int i = 0; i < N; ++i) {
        scanf("%s", grid+i*N);
        std::sort(grid+i*N, grid+(i+1)*N);
    }
    printf("%s\n", ((checkGrid(grid,N)) ? "YES" : "NO"));
    delete[] grid;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
    return 0;
}