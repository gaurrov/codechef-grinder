# [Largest K (LARGESTK343)](https://www.codechef.com/problems/LARGESTK343)

- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $X$ zeros and $Y$ ones, we need to arrange them in a sequence such that there are at least $K$ ones between any two occurrences of $0$. We want to find the maximum possible value of $K$.

## Intuition & Mathematical Observation
To maximize $K$, we must distribute the $Y$ ones as efficiently as possible into the gaps created by the $X$ zeros.

1.  **Identifying Gaps**: If we have $X$ zeros, there are exactly $X - 1$ gaps between them.
2.  **Constraint**: The problem requires that every gap between two zeros must contain at least $K$ ones.
3.  **Distribution**: Any ones placed before the first zero or after the last zero do not help satisfy the "between" constraint. Therefore, to maximize $K$, we should place all $Y$ ones into the $X - 1$ gaps.
4.  **Equation**: Let $g_i$ be the number of ones in the $i$-th gap. We have:
    $$\sum_{i=1}^{X-1} g_i = Y$$
    To satisfy the condition $g_i \ge K$ for all $i$, the total number of ones required is at least $(X - 1) \times K$.
    $$(X - 1) \times K \le Y$$
    $$K \le \frac{Y}{X - 1}$$
5.  **Conclusion**: Since we want the largest integer $K$, we take the floor of the division: $K = \lfloor \frac{Y}{X - 1} \rfloor$.

*Note: If $X=1$, there are no gaps between zeros, meaning the condition is vacuously true for any $K$. However, based on the problem constraints, we assume $X > 1$.*

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a single division operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X zeros and Y ones.
 * We want to arrange them such that there are at least K ones between any two zeros.
 * 
 * If we have X zeros, there are (X - 1) gaps between them.
 * To maximize K, we distribute all Y ones into these (X - 1) gaps.
 * The condition (X - 1) * K <= Y leads to K = Y / (X - 1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // X zeros create (X - 1) gaps between them.
        // We need at least K ones in each of these (X - 1) gaps.
        // Total ones required = (X - 1) * K <= Y.
        // K <= Y / (X - 1).
        
        long long K = Y / (X - 1);
        cout << K << "\n";
    }

    return 0;
}
```