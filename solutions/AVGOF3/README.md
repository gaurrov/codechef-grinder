# [Average of Three (AVGOF3)](https://www.codechef.com/problems/AVGOF3)

- **Difficulty Rating**: 1141
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $X$, we are required to find three **distinct** positive integers $A_1, A_2, A_3$ such that their average is exactly $X$. That is:
$$\frac{A_1 + A_2 + A_3}{3} = X \implies A_1 + A_2 + A_3 = 3X$$
The constraints state that $2 \le X \le 100$ and the resulting integers must be within the range $[1, 1000]$.

## Intuition & Mathematical Observation
To satisfy the equation $A_1 + A_2 + A_3 = 3X$, we can look for a symmetric distribution of numbers around the mean $X$. 

If we choose:
- $A_1 = X - 1$
- $A_2 = X$
- $A_3 = X + 1$

The sum becomes $(X - 1) + X + (X + 1) = 3X$. Dividing by 3 gives us the required average $X$. 

**Validation of Constraints:**
1. **Distinctness**: Since $X-1 < X < X+1$, the three integers are always distinct.
2. **Lower Bound**: Given $X \ge 2$, the smallest value is $A_1 = X - 1 \ge 1$. This satisfies the requirement that the integers must be positive.
3. **Upper Bound**: Given $X \le 100$, the largest value is $A_3 = X + 1 \le 101$, which is well within the limit of $1000$.

This simple construction works for all valid inputs provided in the problem.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and a single print statement.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output, requiring no extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find three distinct integers A1, A2, A3 such that:
 * (A1 + A2 + A3) / 3 = X
 * This implies A1 + A2 + A3 = 3 * X.
 * 
 * A simple construction is to pick numbers around X.
 * Let A1 = X - 1, A2 = X, A3 = X + 1.
 * Sum = (X - 1) + X + (X + 1) = 3X.
 * Mean = 3X / 3 = X.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;
        
        // Using the construction: X-1, X, X+1
        // Since X >= 2, X-1 >= 1, which satisfies the lower bound.
        // Since X <= 100, X+1 <= 101, which satisfies the upper bound.
        // The numbers are distinct because (X-1) < X < (X+1).
        cout << (x - 1) << " " << x << " " << (x + 1) << "\n";
    }

    return 0;
}
```