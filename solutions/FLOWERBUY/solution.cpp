#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to represent N as 2*x + 3*y = N, where x, y >= 0 are integers.
 * We want to minimize the cost C = 4*x + 5*y.
 * 
 * Since N is small (up to 100), we can use dynamic programming or a simple 
 * brute force search for each test case.
 * Let dp[i] be the minimum cost to get exactly i flowers.
 * dp[i] = min(dp[i-2] + 4, dp[i-3] + 5)
 * Base cases:
 * dp[0] = 0
 * dp[1] = infinity (impossible to get 1 flower)
 * dp[2] = 4
 * dp[3] = 5
 */

void solve() {
    int N;
    cin >> N;

    // Initialize DP array with a large value
    const long long INF = 1e18;
    vector<long long> dp(N + 1, INF);
    
    dp[0] = 0;
    
    for (int i = 1; i <= N; ++i) {
        if (i >= 2 && dp[i - 2] != INF) {
            dp[i] = min(dp[i], dp[i - 2] + 4);
        }
        if (i >= 3 && dp[i - 3] != INF) {
            dp[i] = min(dp[i], dp[i - 3] + 5);
        }
    }
    
    cout << dp[N] << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}