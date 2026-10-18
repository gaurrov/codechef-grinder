# [Yoga Class (YOGACLASS)](https://www.codechef.com/problems/YOGACLASS)

- **Difficulty Rating**: 879
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ hours available for yoga classes. There are two types of sessions:
1. **Type 1**: Lasts 1 hour and earns $X$ coins.
2. **Type 2**: Lasts 2 hours and earns $Y$ coins.

The goal is to determine the maximum number of coins Chef can earn by choosing an optimal combination of these sessions within the $N$ hours.

## Intuition & Mathematical Observation
To maximize earnings, we compare two primary strategies:

1. **Prioritizing Type 2 sessions**: Since Type 2 sessions cover 2 hours, we can fit at most $\lfloor N/2 \rfloor$ of these. If $N$ is odd, we are left with 1 hour, which must be filled by a Type 1 session. The total earnings for this strategy are:
   $$\text{Earnings} = (\lfloor N/2 \rfloor \times Y) + ((N \pmod 2) \times X)$$

2. **Using only Type 1 sessions**: In some cases, a Type 2 session might be less profitable than two Type 1 sessions (i.e., if $Y < 2X$). In this scenario, it is better to fill all $N$ hours with Type 1 sessions. The total earnings for this strategy are:
   $$\text{Earnings} = N \times X$$

By calculating both values and taking the maximum, we ensure the optimal result regardless of the relationship between $X$ and $Y$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We compare two strategies:
 * 1. Maximize Type 2 sessions: (N / 2) * Y + (N % 2) * X
 * 2. Use only Type 1 sessions: N * X
 * The answer is the maximum of these two values.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        // Option 1: Maximize Type 2 sessions
        long long num_type2 = n / 2;
        long long remainder = n % 2;
        long long earnings_with_type2 = (num_type2 * y) + (remainder * x);

        // Option 2: Only Type 1 sessions
        long long earnings_only_type1 = n * x;

        // The answer is the maximum of the two strategies
        cout << max(earnings_with_type2, earnings_only_type1) << "\n";
    }

    return 0;
}
```