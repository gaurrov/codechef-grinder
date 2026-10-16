# [Chocolate Distribution (CHOCOCHEF)](https://www.codechef.com/problems/CHOCOCHEF)

- **Difficulty Rating**: 1104
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ chocolates to be distributed into three jars ($a, b, c$) such that:
1. $a + b + c = N$
2. $a, b, c \ge 1$
3. Exactly two jars contain the same number of chocolates.
4. At least one jar contains an odd number of chocolates.

We need to output any valid triplet $(a, b, c)$ for a given $N$.

## Intuition & Mathematical Observation
To satisfy the condition that exactly two jars are equal, let the two equal jars contain $x$ chocolates each. The third jar will then contain $N - 2x$ chocolates. We must ensure $N - 2x \ge 1$ (i.e., $x \le \frac{N-1}{2}$).

We can split the logic based on the parity of $N$:

*   **Case 1: $N$ is even**
    If we set $x = 1$, the jars become $(1, 1, N-2)$. 
    - Two jars are equal ($1=1$).
    - Since $N \ge 4$ (the smallest even number allowing three positive integers is 3, but for $N=4$, $1+1+2=4$), this is always valid.
    - $1$ is odd, satisfying the "at least one odd" condition.

*   **Case 2: $N$ is odd**
    If we set $x = \frac{N-1}{2}$, the jars become $(\frac{N-1}{2}, \frac{N-1}{2}, 1)$.
    - Two jars are equal.
    - The third jar is $1$, which is odd, satisfying the condition.
    - Since $N \ge 3$, this is always valid.

By using these two simple constructions, we cover all possible values of $N$ efficiently.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform simple arithmetic operations to determine the distribution. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to distribute N chocolates into three jars (a, b, c) such that:
 * 1. a + b + c = N
 * 2. At least one jar has an odd number of chocolates.
 * 3. Exactly two jars have the same number of chocolates.
 * 4. a, b, c >= 1
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        if (n % 2 == 0) {
            // Even N: (1, 1, N-2)
            // Example N=4: 1, 1, 2. (Two 1s, one is odd)
            cout << 1 << " " << 1 << " " << (n - 2) << "\n";
        } else {
            // Odd N: ((N-1)/2, (N-1)/2, 1)
            // Example N=7: 3, 3, 1. (Two 3s, all are odd)
            long long x = (n - 1) / 2;
            cout << x << " " << x << " " << 1 << "\n";
        }
    }

    return 0;
}
```