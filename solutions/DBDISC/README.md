# [Double Discount (DBDISC)](https://www.codechef.com/problems/DBDISC)

- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ items, each with a cost $A_i$ and a tastiness value $B_i$. We must select exactly two distinct items $i$ and $j$ to purchase. The pricing rule is as follows:
1. Identify the more expensive item ($M = \max(A_i, A_j)$) and the cheaper item ($m = \min(A_i, A_j)$).
2. The more expensive item receives a discount of $\min(M/2, 100)$.
3. The total cost is calculated as $m + (M - \text{discount})$.
4. We need to find the maximum possible sum of tastiness ($B_i + B_j$) such that the total cost is less than or equal to a given budget $K$. If no such pair exists, output 0.

## Intuition & Mathematical Observation
Given the constraints $N \le 100$, an $O(N^2)$ approach is highly efficient. Since we only need to choose two items, we can iterate through all possible pairs $(i, j)$ where $i < j$.

For every pair:
- Calculate the effective cost using the provided formula: `final_cost = m + (M - min(M / 2, 100))`.
- Check if `final_cost <= K`.
- If valid, track the maximum `B[i] + B[j]` encountered.
- If no pair satisfies the condition, the result remains 0.

## Complexity Analysis
- **Time Complexity**: $O(T \times N^2)$, where $T$ is the number of test cases and $N$ is the number of items. With $N=100$ and $T=100$, the total operations are roughly $10^6$, which easily fits within the 1-second time limit.
- **Space Complexity**: $O(N)$ to store the arrays $A$ and $B$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to select exactly two items (i, j) where i != j.
 * Let the costs be A[i] and A[j].
 * Let the more expensive item be M = max(A[i], A[j]) and the cheaper be m = min(A[i], A[j]).
 * The discount on M is min(M / 2, 100).
 * The final cost is m + (M - min(M / 2, 100)).
 * We need to maximize B[i] + B[j] such that final cost <= K.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    long long max_tastiness = 0;
    bool possible = false;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int cost1 = A[i];
            int cost2 = A[j];
            
            int M = max(cost1, cost2);
            int m = min(cost1, cost2);
            
            int discount = min(M / 2, 100);
            int final_cost = m + (M - discount);
            
            if (final_cost <= K) {
                possible = true;
                long long current_tastiness = (long long)B[i] + B[j];
                if (current_tastiness > max_tastiness) {
                    max_tastiness = current_tastiness;
                }
            }
        }
    }

    if (!possible) {
        cout << 0 << "\n";
    } else {
        cout << max_tastiness << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```