# [Long Drive (LONGDRIVE)](https://www.codechef.com/problems/LONGDRIVE)

- **Difficulty Rating**: 939
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has already driven for 10 hours at an average speed of $X$ km/h. He wants his total average speed over the entire duration (10 hours + $n$ additional hours) to be at least $Y$ km/h. During the additional $n$ hours, Chef can drive at a maximum speed of 100 km/h. We need to find the minimum integer $n$ required to achieve this target average speed.

## Intuition & Mathematical Observation
To achieve an average speed of at least $Y$ in the minimum amount of time, we should drive at the maximum possible speed (100 km/h) for all $n$ additional hours.

Let the total distance covered be $D$.
1. Initial distance: $10 \times X$
2. Additional distance: $n \times 100$
3. Total time: $10 + n$

The condition for the new average speed is:
$$\frac{10X + 100n}{10 + n} \geq Y$$

Rearranging the inequality to solve for $n$:
$$10X + 100n \geq Y(10 + n)$$
$$10X + 100n \geq 10Y + nY$$
$$100n - nY \geq 10Y - 10X$$
$$n(100 - Y) \geq 10(Y - X)$$
$$n \geq \frac{10(Y - X)}{100 - Y}$$

Since $n$ must be an integer, we take the ceiling of the resulting value. Using integer arithmetic, the ceiling of $\frac{a}{b}$ can be calculated as `(a + b - 1) / b`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic calculation. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the minimum integer 'n' such that the average speed 
 * over (10 + n) hours is at least Y, given the first 10 hours were at speed X
 * and the subsequent n hours are at a maximum speed of 100 km/h.
 * 
 * Derived formula: n >= (10 * (Y - X)) / (100 - Y)
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Numerator: 10 * (y - x)
        // Denominator: 100 - y
        long long numerator = 10 * (y - x);
        long long denominator = 100 - y;
        
        // Calculate ceiling division: (numerator + denominator - 1) / denominator
        long long n = (numerator + denominator - 1) / denominator;
        
        cout << n << "\n";
    }

    return 0;
}
```