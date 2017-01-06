#include <cstdio>
#include <algorithm>

void solve() {
    int n;
    long k, *A, *B;
    scanf("%d %ld", &n, &k);
    A = new long[n];
    B = new long[n];
    for (int i = 0; i < n; ++i) scanf("%ld", A+i);
    for (int i = 0; i < n; ++i) scanf("%ld", B+i);
    std::sort(A,A+n);
    std::sort(B,B+n);
    for (int i = 0; i < n; ++i){
        if (A[i]+B[n-1-i] < k) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main() {
    int q;
    scanf("%d",&q);
    while (q--) solve();
    return 0;
}