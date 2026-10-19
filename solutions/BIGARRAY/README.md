# [Obtain the Sum (BIGARRAY)](https://www.codechef.com/problems/BIGARRAY)

- **Difficulty Rating**: 1368
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array $A$ containing all integers from $1$ to $N$ (i.e., $A = [1, 2, 3, \dots, N]$). We are asked to find an element $x$ in this array such that if we remove $x$, the sum of the remaining elements equals a given value $S$. If no such element exists, we must output $-1$.

## Intuition & Mathematical Observation
1.  **Total Sum**: The sum of all elements in the array is the sum of the first $N$ natural numbers, given by the formula:
    $$\text{TotalSum} = \frac{N \times (N + 1)}{2}$$
2.  **Deriving $x$**: If we remove an element $x$ from the array, the sum of the remaining elements is $\text{TotalSum} - x$. We are given that this remaining sum must equal $S$:
    $$\text{TotalSum} - x = S$$
    Rearranging for $x$:
    $$x = \text{TotalSum} - S$$
3.  **Constraints Check**: Since the array only contains integers from $1$ to $N$, the calculated value $x$ is a valid solution if and only if $1 \le x \le N$. If the calculated $x$ falls outside this range, it implies no such element exists in the array, and we return $-1$.
4.  **Data Types**: Given $N \le 10^9$, the $\text{TotalSum}$ can reach approximately $5 \times 10^{17}$. This fits within a standard 64-bit signed integer (`long long` in C++), which supports values up to $\approx 9 \times 10^{18}$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A is defined as A[i] = i for 1 <= i <= N.
 * The sum of all elements in the array is TotalSum = N * (N + 1) / 2.
 * We are looking for an index x such that:
 * (Sum of all elements except A[x]) = S
 * (TotalSum - x) = S
 * Therefore, x = TotalSum - S.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, s;
        cin >> n >> s;

        // Calculate the sum of the first N natural numbers
        // N=10^9, so N*(N+1)/2 is ~5e17, which fits in long long.
        long long total_sum = n * (n + 1) / 2;

        // The equation is: TotalSum - x = S
        // So, x = TotalSum - S
        long long x = total_sum - s;

        // Check if x is within the valid range [1, N]
        if (x >= 1 && x <= n) {
            cout << x << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
```