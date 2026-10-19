# [Cooler (COOLER7)](https://www.codechef.com/problems/COOLER7)

- **Difficulty Rating**: 555
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to calculate the total time required to cool an object from an initial temperature $N$ to a target temperature $M$. The rule provided is that cooling the object from temperature $T$ to $T-1$ takes exactly $T$ minutes.

## Intuition & Mathematical Observation
To cool the object from $N$ down to $M$, we must perform a series of steps:
1. Cooling from $N$ to $N-1$ takes $N$ minutes.
2. Cooling from $N-1$ to $N-2$ takes $N-1$ minutes.
3. ...
4. Cooling from $M+1$ to $M$ takes $M+1$ minutes.

The total time is the sum of the arithmetic progression:
$$\text{Total Time} = N + (N-1) + (N-2) + \dots + (M+1)$$

This is a standard arithmetic series where:
- The number of terms is $N - M$.
- The first term is $M + 1$.
- The last term is $N$.

Using the arithmetic series sum formula $\text{Sum} = \frac{\text{count} \times (\text{first} + \text{last})}{2}$:
$$\text{Total Time} = \frac{(N - M) \times (N + M + 1)}{2}$$

Since $N \le 40$, the result fits well within a standard integer, though `long long` is used for best practices.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation is performed using a direct mathematical formula.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To drop the temperature from T to T-1, it takes T minutes.
 * To go from N to M:
 * Step 1: N -> N-1 takes N minutes.
 * Step 2: N-1 -> N-2 takes N-1 minutes.
 * ...
 * Step k: (M+1) -> M takes M+1 minutes.
 * 
 * Total time = N + (N-1) + (N-2) + ... + (M+1)
 * This is an arithmetic series sum:
 * Sum = (Number of terms) * (First term + Last term) / 2
 * Number of terms = N - M
 * Sum = (N - M) * (N + M + 1) / 2
 * 
 * Constraints: N <= 40, so the result will easily fit in a standard integer.
 * Using long long for safety.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // The sum of the arithmetic progression from (M+1) to N
        // Sum = (N - M) * (N + M + 1) / 2
        long long total_time = (n - m) * (n + m + 1) / 2;
        
        cout << total_time << "\n";
    }

    return 0;
}
```