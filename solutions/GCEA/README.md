# [Gotta Catch Em All (GCEA)](https://www.codechef.com/problems/GCEA)

- **Difficulty Rating**: 898
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ Pekómon, each with a specific difficulty level $A_i$. You have two ways to catch them:
1. **Normal Pekóball**: Costs $A_i \times X$ for a Pekómon with difficulty $A_i$.
2. **Master Pekóball**: Costs a flat rate of $Y$ regardless of the difficulty.

The goal is to calculate the minimum total cost required to catch all $N$ Pekómon by choosing the most cost-effective method for each individual Pekómon.

## Intuition & Mathematical Observation
For every individual Pekómon $i$, we are faced with a simple binary choice:
*   Is it cheaper to use a Normal Pekóball ($A_i \times X$)?
*   Is it cheaper to use a Master Pekóball ($Y$)?

Since the choice for one Pekómon does not affect the cost of another, we can apply a **Greedy Strategy**. For each Pekómon, we simply calculate:
$$\text{Cost}_i = \min(A_i \times X, Y)$$
The total cost is the summation of these individual minimums:
$$\text{Total Cost} = \sum_{i=1}^{N} \min(A_i \times X, Y)$$

Given the constraints ($N, X, Y, A_i \le 100$), the maximum possible cost is $100 \times 100 \times 100 = 1,000,000$. While this fits in a standard `int`, using `long long` is a safe practice to avoid potential overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the list of Pekómon exactly once.
- **Space Complexity**: $O(N)$ to store the difficulty levels (or $O(1)$ if we process the input on the fly without storing it in a vector).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each Pekómon i with difficulty A_i:
 * - Cost using Normal Pekóballs: A_i * X
 * - Cost using a Master Pekóball: Y
 * 
 * To minimize the total cost, for each Pekómon, we should choose the minimum
 * of (A_i * X) and Y.
 * 
 * Total Cost = Sum_{i=1 to N} min(A_i * X, Y)
 */

void solve() {
    int N;
    long long X, Y;
    cin >> N >> X >> Y;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        // For each Pekómon, pick the cheaper option
        total_cost += min((long long)A[i] * X, Y);
    }
    
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O setup
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