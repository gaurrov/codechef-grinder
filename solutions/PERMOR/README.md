# [OR Permutation (PERMOR)](https://www.codechef.com/problems/PERMOR)

- **Difficulty Rating**: 1196
- **Solved in**: 3 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct a permutation $A$ of the numbers $\{1, 2, \dots, N\}$ such that for all $i$ where $3 \le i \le N$, the condition $A_i \neq (A_{i-1} \mid A_{i-2})$ is satisfied.

## Intuition & Mathematical Observation
The core constraint is $A_i \neq (A_{i-1} \mid A_{i-2})$. 

Consider the properties of the bitwise OR operation:
1. For any two positive integers $x$ and $y$, $(x \mid y) \ge \max(x, y)$.
2. If we arrange the permutation in **descending order** ($N, N-1, \dots, 1$), then for any index $i \ge 3$:
   - $A_{i-1} > A_i$
   - $A_{i-2} > A_i$
   
Since $A_{i-1} > A_i$ and $A_{i-2} > A_i$, it follows that $\max(A_{i-1}, A_{i-2}) > A_i$. Because the bitwise OR of two numbers is always greater than or equal to the maximum of those two numbers, we have:
$$(A_{i-1} \mid A_{i-2}) \ge \max(A_{i-1}, A_{i-2}) > A_i$$

Since $(A_{i-1} \mid A_{i-2})$ is strictly greater than $A_i$, the condition $A_i \neq (A_{i-1} \mid A_{i-2})$ is guaranteed to hold for all $i \ge 3$. Thus, simply printing the numbers from $N$ down to $1$ provides a valid solution.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the numbers from $N$ to $1$ exactly once.
- **Space Complexity**: $O(1)$, as we do not store the permutation in an array and only print the values directly.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We need A[i] != (A[i-1] | A[i-2]).
 * If we output the permutation in descending order: N, N-1, ..., 1.
 * For any i >= 3:
 * A[i-1] > A[i] and A[i-2] > A[i].
 * The bitwise OR of two numbers is always greater than or equal to the maximum of the two numbers.
 * Therefore, (A[i-1] | A[i-2]) >= max(A[i-1], A[i-2]) > A[i].
 * Thus, A[i] can never equal (A[i-1] | A[i-2]).
 */

void solve() {
    int n;
    cin >> n;
    for (int i = n; i >= 1; --i) {
        cout << i << (i == 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Optimize I/O operations
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