# [Chef and Stocks (STOCKMARKET)](https://www.codechef.com/problems/STOCKMARKET)

- **Difficulty Rating**: 948
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array $A$ representing the profit or loss on $N$ different days. We are allowed to skip exactly one day. The goal is to maximize the total profit after skipping one day.

## Intuition & Mathematical Observation
To maximize the total profit, we need to remove the element that contributes the least to the total sum. 

Let $S$ be the sum of all elements in the array: $S = \sum_{i=1}^{N} A_i$.
If we skip the $k$-th day, the new total profit becomes $S - A_k$. 

To maximize this value, we must choose $k$ such that $A_k$ is the minimum value in the array. Thus, the optimal strategy is:
1. Calculate the total sum of all elements.
2. Identify the minimum element in the array.
3. Subtract the minimum element from the total sum.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to calculate the sum and find the minimum value.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the sum and the minimum value, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N days of profit/loss. We need to skip exactly one day to maximize the total profit.
 * Total profit = (Sum of all A_i) - (A_i that we skip).
 * To maximize the total profit, we need to minimize the value of the day we skip.
 */

void solve() {
    int N;
    cin >> N;
    
    long long total_sum = 0;
    int min_val = 101; // Constraints state A_i <= 100, so 101 is a safe initial max
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        total_sum += val;
        if (val < min_val) {
            min_val = val;
        }
    }
    
    // We skip the day with the minimum profit (or maximum loss)
    cout << (total_sum - min_val) << "\n";
}

int main() {
    // Fast I/O setup
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