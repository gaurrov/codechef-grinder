# [Sale (FINALSALE)](https://www.codechef.com/problems/FINALSALE)
- **Difficulty Rating**: 1180
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has projected sales for $N$ consecutive days, represented by an array $A$. If Chef chooses to close the shop on day $k$ (where $1 \le k \le N$), the total sales are calculated as the sum of all sales from day $1$ to $k-1$, plus double the sales of day $k$. The goal is to determine the maximum possible total sales Chef can achieve by choosing the optimal day $k$ to close the shop.

## Intuition & Mathematical Observation
Let $S_k$ be the prefix sum of the array up to day $k$, i.e., $S_k = \sum_{i=1}^{k} A_i$.
The problem states that if we close on day $k$, the total sales $T_k$ are:
$$T_k = \left(\sum_{i=1}^{k-1} A_i\right) + 2 \cdot A_k$$

We can rewrite this expression using the prefix sum $S_k$:
$$T_k = (S_k - A_k) + 2 \cdot A_k$$
$$T_k = S_k + A_k$$

To find the maximum sales, we simply need to iterate through all possible days $k$ from $1$ to $N$, maintain a running prefix sum, and calculate $S_k + A_k$ at each step. We keep track of the maximum value encountered during this iteration. Since $A_i$ can be up to $10^9$ and $N$ up to $3 \cdot 10^5$, the total sum will exceed the capacity of a 32-bit integer, so we must use `long long` in C++.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to compute the prefix sum and the potential total sales. Given the constraint $\sum N \le 3 \cdot 10^5$, this is well within the time limits.
- **Space Complexity**: $O(N)$ to store the input array. This could be optimized to $O(1)$ by calculating the prefix sum on the fly, but $O(N)$ is perfectly acceptable given the memory constraints.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N days with projected sales A_1, A_2, ..., A_N.
 * If Chef closes the shop on day k (1 <= k <= N), the total sales will be:
 * Total = (A_1 + A_2 + ... + A_{k-1}) + (2 * A_k)
 * Total = (A_1 + A_2 + ... + A_k) + A_k
 * 
 * To maximize this, we need to calculate the prefix sum of the array A,
 * and for each possible closing day k, compute (PrefixSum[k] + A_k).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    long long current_prefix_sum = 0;
    long long max_sales = -1; // Initialize with a value smaller than any possible result
    
    for (int i = 0; i < N; ++i) {
        current_prefix_sum += A[i];
        // If we close on day i (0-indexed), total is prefix_sum + A[i]
        long long current_total = current_prefix_sum + A[i];
        
        if (i == 0) {
            max_sales = current_total;
        } else {
            max_sales = max(max_sales, current_total);
        }
    }
    
    cout << max_sales << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```