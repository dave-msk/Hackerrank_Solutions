#include <cstdio>
#include <cstring>

int main() {
    int t;
    long n;
    scanf("%d", &t);
    while (t--) {
        scanf("%ld", &n);
        long n3 = 0, n5 = 0;
        while (n3*5 <= n) {
            if ((n-5*n3) % 3 == 0) {
                n5 = (n-5*n3)/3;
                break;
            }
            ++n3;
        }
        if (3*n5 + 5*n3 == n) {
            char *arr = new char[n+1];
            if (n5) memset(arr, '5', n5*3);
            if (n3) memset(arr+n5*3, '3', n3*5);
            arr[n] = 0;
            printf("%s\n", arr);
            delete[] arr;
        } else printf("-1\n");
    }
    return 0;
}