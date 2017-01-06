#include <cstdio>
#include <algorithm>

int main() {
    long N, K;
    scanf("%ld\n%ld", &N, &K);
    long *arr = new long[N];
    for (long i = 0; i < N; ++i) scanf("%ld", arr+i);
    std::sort(arr, arr+N);
    long min = arr[N-1] - arr[0];
    for (long i = 0; i < N-K+1; ++i) if (min > arr[i+K-1]-arr[i]) min = arr[i+K-1]-arr[i];
    printf("%ld\n",min);
    delete[] arr;
    return 0;
}