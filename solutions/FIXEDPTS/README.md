# [Fixed Points (FIXEDPTS)](https://www.codechef.com/problems/FIXEDPTS)

- **Difficulty Rating**: 884
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an integer $N$ (the length of a permutation) and an integer $K$, determine if it is possible to construct a permutation of length $N$ that contains exactly $K$ fixed points. A fixed point is an index $i$ such that the element at that position is $i$ (i.e., $P[i] = i$).

## Intuition & Mathematical Observation
To have exactly $K$ fixed points, we must choose $K$ indices to be fixed points. This leaves $M = N - K$ indices that must **not** be fixed points. 

These $M$ remaining elements must form a **derangement** (a permutation where no element appears in its original position). We analyze the existence of a derangement for $M$ elements:
1. **If $M = 0$**: This is valid (the empty set is a trivial derangement).
2. **If $M = 1$**: This is **impossible**. If you have only one element left, it must occupy the only remaining position, which makes it a fixed point. Thus, you would end up with $K+1$ fixed points instead of $K$.
3. **If $M \ge 2$**: A derangement always exists (e.g., a simple cyclic shift of the $M$ elements).

Therefore, the condition for a solution to exist is simply $N - K \neq 1$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case is solved in $O(1)$ time using simple arithmetic.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * We need to determine if a permutation of length N can have exactly K fixed points.
 * 
 * 1. If we choose K indices to be fixed points, we are left with M = N - K elements.
 * 2. These M elements must form a derangement (a permutation with zero fixed points).
 * 3. A derangement of size M exists if and only if M != 1.
 *    - If M = 0, it is a valid derangement (the empty set).
 *    - If M = 1, it is impossible to have 0 fixed points.
 *    - If M >= 2, a derangement always exists.
 * 
 * Therefore, the condition is: N - K != 1.
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    if (!(std::cin >> t)) return 0;
    while (t--) {
        int n, k;
        std::cin >> n >> k;

        // If N - K == 1, we are forced to have at least one fixed point 
        // among the remaining elements, making it impossible to have exactly K.
        if (n - k == 1) {
            std::cout << "No\n";
        } else {
            std::cout << "Yes\n";
        }
    }

    return 0;
}
```