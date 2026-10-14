# [Table Strength (STRONGTABLE)](https://www.codechef.com/problems/STRONGTABLE)

- **Difficulty Rating**: 1211
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ table legs, each with a specific strength $S_i$. If you choose a subset of $k$ legs to support a table, the weight $W$ that the table can support is limited by the weakest leg in that subset. Specifically, if the minimum strength among the chosen $k$ legs is $S_{min}$, the table can support a weight $W$ such that $W/k \le S_{min}$. Your goal is to maximize $W$, which simplifies to $W = k \times S_{min}$.

## Intuition & Mathematical Observation
To maximize the total weight $W = k \times S_{min}$, we need to strategically choose a subset of legs. 

1. **Sorting**: If we sort the strengths in non-decreasing order ($S_0 \le S_1 \le \dots \le S_{N-1}$), it becomes easier to evaluate potential subsets.
2. **Subset Selection**: If we decide that a specific leg with strength $S_i$ will be the *minimum* strength leg in our subset, we should include all legs that have a strength greater than or equal to $S_i$ to maximize $k$.
3. **Calculation**: In the sorted array, if we pick $S_i$ as the minimum, all legs from index $i$ to $N-1$ are $\ge S_i$. The number of such legs is $(N - i)$. Thus, the maximum weight we can support using $S_i$ as the minimum is $S_i \times (N - i)$.
4. **Optimization**: By iterating through all possible indices $i$ from $0$ to $N-1$ and calculating $S_i \times (N - i)$, we can find the global maximum weight.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, dominated by the sorting step. The subsequent linear scan takes $O(N)$.
- **Space Complexity**: $O(N)$ to store the strengths of the $N$ legs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let a subset of legs have strengths {S_1, S_2, ..., S_k}.
 * Let the minimum strength in this subset be S_min.
 * If we use these k legs, the weight W must satisfy:
 * W / k <= S_min  => W <= k * S_min.
 * To maximize W for a fixed subset, we should choose W = k * S_min.
 * 
 * To maximize this over all possible subsets:
 * 1. Sort the strengths in non-decreasing order: W_1 <= W_2 <= ... <= W_N.
 * 2. If we decide that the minimum strength in our subset is W_i, 
 *    then to maximize the weight, we should include all legs with strength >= W_i.
 * 3. The number of such legs is (N - i).
 * 4. The maximum weight for this choice is (N - i) * W_i.
 * 5. We iterate through all i from 0 to N-1 and find the maximum of these values.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    
    // Sort the weights to easily count how many legs have strength >= W_i
    sort(w.begin(), w.end());
    
    long long max_weight = 0;
    
    // For each leg i, if it is the minimum strength leg in our subset,
    // we can include all legs from i to n-1.
    // The number of such legs is (n - i).
    for (int i = 0; i < n; ++i) {
        long long current_weight = w[i] * (n - i);
        if (current_weight > max_weight) {
            max_weight = current_weight;
        }
    }
    
    cout << max_weight << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```