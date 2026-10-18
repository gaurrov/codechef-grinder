# [Odd Repeat (REPEAT)](https://www.codechef.com/problems/REPEAT)

- **Difficulty Rating**: 1218
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array of length $N + K - 1$. This array contains all the first $N$ positive odd numbers exactly once, plus one specific odd number $x$ that is repeated an additional $K-1$ times (making it appear $K$ times in total). Given the total sum $S$ of the array, we need to identify the value of $x$.

## Intuition & Mathematical Observation
1. **Sum of Odd Numbers**: The first $N$ positive odd numbers are $1, 3, 5, \dots, (2N-1)$. The sum of the first $N$ odd numbers is a well-known mathematical property:
   $$\sum_{i=1}^{N} (2i - 1) = N^2$$
2. **Formulating the Equation**: The total sum $S$ provided in the problem is the sum of the first $N$ odd numbers plus the extra occurrences of the repeated number $x$. Since $x$ appears $K$ times in total, it contributes $K$ times to the sum. However, we already accounted for one instance of $x$ in the $N^2$ sum. Therefore, the extra contribution is $(K-1) \times x$.
   $$S = N^2 + (K - 1) \times x$$
3. **Solving for $x$**: Rearranging the equation to isolate $x$:
   $$(K - 1) \times x = S - N^2$$
   $$x = \frac{S - N^2}{K - 1}$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array contains the first N positive odd numbers.
 * The first N positive odd numbers are: 1, 3, 5, ..., (2N - 1).
 * The sum of the first N positive odd numbers is N^2.
 * 
 * Let x be the number that appears K times.
 * The array consists of all N odd numbers once, plus (K-1) extra copies of x.
 * The sum S is given by:
 * S = (Sum of first N odd numbers) + (K - 1) * x
 * S = N^2 + (K - 1) * x
 * 
 * Rearranging for x:
 * (K - 1) * x = S - N^2
 * x = (S - N^2) / (K - 1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k, s;
        cin >> n >> k >> s;

        // Calculate the sum of the first N odd numbers
        long long sum_n = n * n;

        // Calculate the difference
        long long diff = s - sum_n;

        // Calculate the repeated number
        long long x = diff / (k - 1);

        cout << x << "\n";
    }

    return 0;
}
```