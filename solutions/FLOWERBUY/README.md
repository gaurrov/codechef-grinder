# [Buying Flowers (FLOWERBUY)](https://www.codechef.com/problems/FLOWERBUY)

- **Difficulty Rating**: 931
- **Solved in**: 1 attempt(s)

## Problem Summary
We are tasked with finding the minimum cost to purchase exactly $N$ flowers. We can buy flowers in two types of bundles:
1. A bundle of 2 flowers for a cost of 4.
2. A bundle of 3 flowers for a cost of 5.

We need to determine the minimum total cost to reach exactly $N$ flowers, or identify if it is impossible.

## Intuition & Mathematical Observation
This is a classic variation of the **Change-Making Problem** or the **Unbounded Knapsack Problem**. 

Since we want to reach exactly $N$ flowers using combinations of 2 and 3, we can define a DP state `dp[i]` as the minimum cost to obtain exactly `i` flowers.
- To reach `i` flowers, we could have come from `i-2` (by adding a bundle of 2) or `i-3` (by adding a bundle of 3).
- The recurrence relation is: 
  `dp[i] = min(dp[i-2] + 4, dp[i-3] + 5)`
- **Base Case**: `dp[0] = 0` (cost to get 0 flowers is 0). All other values are initialized to infinity to represent unreachable states.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate from 1 to $N$ once to fill the DP table. Given $N \le 100$, this is extremely efficient.
- **Space Complexity**: $O(N)$ to store the DP array of size $N+1$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to represent N as 2*x + 3*y = N, where x, y >= 0 are integers.
 * We want to minimize the cost C = 4*x + 5*y.
 * 
 * Since N is small (up to 100), we can use dynamic programming.
 * Let dp[i] be the minimum cost to get exactly i flowers.
 * dp[i] = min(dp[i-2] + 4, dp[i-3] + 5)
 */

void solve() {
    int N;
    cin >> N;

    // Initialize DP array with a large value representing infinity
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
    
    // If dp[N] is still INF, it means N cannot be formed by 2s and 3s
    if (dp[N] == INF) {
        cout << -1 << "\n";
    } else {
        cout << dp[N] << "\n";
    }
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
```