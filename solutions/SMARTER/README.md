# [Work Smarter, Not Harder (SMARTER)](https://www.codechef.com/problems/SMARTER)

- **Difficulty Rating**: 924
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the maximum integer wait time $w$ the hare can afford such that it still finishes the race strictly before the tortoise. We are given the total distance $L$, the tortoise's speed $V_1$, and the hare's speed $V_2$. The tortoise takes $\lceil L / V_1 \rceil$ time to finish, while the hare takes $w + \lceil L / V_2 \rceil$ time.

## Intuition & Mathematical Observation
To ensure the hare wins, the total time taken by the hare must be strictly less than the time taken by the tortoise:
$$w + \lceil L / V_2 \rceil < \lceil L / V_1 \rceil$$

Rearranging for $w$:
$$w < \lceil L / V_1 \rceil - \lceil L / V_2 \rceil$$

Since $w$ must be an integer, the maximum value $w$ can take is:
$$w_{max} = \lceil L / V_1 \rceil - \lceil L / V_2 \rceil - 1$$

**Implementation Details:**
- In integer arithmetic, $\lceil A / B \rceil$ can be calculated as `(A + B - 1) / B`.
- If the calculated $w_{max}$ is less than 0, it means the hare cannot win even with a wait time of 0, so we output `-1`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tortoise time: T_tortoise = ceil(L / V1)
 * Hare time: T_hare = w + ceil(L / V2)
 * 
 * Condition to win: T_hare < T_tortoise
 * w + ceil(L / V2) < ceil(L / V1)
 * w < ceil(L / V1) - ceil(L / V2)
 * 
 * Max integer w = ceil(L / V1) - ceil(L / V2) - 1
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long L, V1, V2;
        cin >> L >> V1 >> V2;

        // Calculate ceil(L / V1) using integer arithmetic: (L + V1 - 1) / V1
        long long t_tortoise = (L + V1 - 1) / V1;

        // Calculate ceil(L / V2)
        long long t_hare_travel = (L + V2 - 1) / V2;

        // We need w < t_tortoise - t_hare_travel
        long long max_w = t_tortoise - t_hare_travel - 1;

        if (max_w < 0) {
            cout << -1 << "\n";
        } else {
            cout << max_w << "\n";
        }
    }

    return 0;
}
```