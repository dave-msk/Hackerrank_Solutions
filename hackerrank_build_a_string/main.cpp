#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>

std::pair<long*,long*> suffixArrayAndRank(std::string const &s) {
    std::string::size_type n = s.size();
    long *sa = new long[n+1]{0};
    long *rank = new long[n+1]{0};
    for (std::string::size_type i = 0; i <= n; ++i) {
        sa[i] = i;
        rank[i] = (i < n) ? s[i] : -1;
    }

    for (std::string::size_type k = 1; k <= n; k *= 2) {
        auto compare = [&](long i, long j) {
            long ri = (i + k <= n) ? rank[i+k] : -1;
            long rj = (j + k <= n) ? rank[j+k] : -1;
            return std::make_pair(rank[i], ri) < std::make_pair(rank[j], rj);
        };
        std::sort(sa, sa+n+1, compare);
        long *dp = new long[n+1]{0};
        dp[sa[0]] = 0;
        for (long i = 1; i < n+1; ++i) dp[sa[i]] = dp[sa[i-1]] + compare(sa[i-1],sa[i]);
        delete[] rank;
        rank = dp;
    }
    return {sa, rank};
};

long longestPrefixLength(std::string const &s, long const * const sa, long const * const rank, long offset) {
    long ans = 0;
    for (long i = rank[offset]; i >= 1; --i) {
        if (s[sa[i]] != s[offset]) break;
        if (sa[i] <= offset) continue;
        long l = std::mismatch(s.begin()+sa[i], s.end(), s.begin()+offset).second - (s.begin()+offset);
        if (l <= ans) break;
        ans = std::max(ans, std::min(sa[i]-offset, l));
    }
    for (long i = rank[offset]; i < s.size()+1; ++i) {
        if (s[sa[i]] != s[offset]) break;
        if (sa[i] <= offset) continue;
        long l = std::mismatch(s.begin()+sa[i], s.end(), s.begin()+offset).second - (s.begin()+offset);
        if (l <= ans) break;
        ans = std::max(ans, std::min(sa[i]-offset, l));
    }
    return ans;
}


int main() {

    int t;
    std::cin >> t;
    std::string s, str;
    long N, A, B;
    while (t--) {
        std::cin >> N >> A >> B >> s;
        std::string r(s.rbegin(), s.rend());
        long *sa, *rank;
        std::tie(sa, rank) = suffixArrayAndRank(r);
        long *dp = new long[N+1];
        dp[0] = 0;
        for (long i = 0; i < N; ++i) {
            dp[i+1] = dp[i] + A;
            long l = longestPrefixLength(r, sa, rank, N-i-1);
            if (l) for (long j = 0; j < l; ++j) dp[i+1] = std::min(dp[i+1],dp[i-j]+B);
        }
        std::cout << dp[N] << std::endl;
        delete[] sa, rank;
        delete[] dp;
    }
    return 0;
}