# [Football Ties (FOOTBALLTIES)](https://www.codechef.com/problems/FOOTBALLTIES)

- **Difficulty Rating**: 788
- **Solved in**: 1 attempt(s)

## Problem Summary
In a football league, a win awards 3 points, a loss awards 0 points, and a draw awards 1 point. Given the final scores $X$ and $Y$ of two teams, determine the minimum number of draws that could have occurred between them.

## Intuition & Mathematical Observation
Let $w_A, l_A, d_A$ be the wins, losses, and draws for team A, and $w_B, l_B, d_B$ be the same for team B. Since the teams play against each other:
1. $w_A = l_B$
2. $l_A = w_B$
3. $d_A = d_B = D$ (The number of draws must be equal for both teams)

The scores are calculated as:
- $X = 3 \cdot w_A + D$
- $Y = 3 \cdot w_B + D$

Taking these equations modulo 3:
- $X \equiv D \pmod 3$
- $Y \equiv D \pmod 3$

This confirms that the number of draws $D$ must have the same remainder as the scores when divided by 3. Since we want to minimize $D$ and the smallest non-negative remainder of any number divided by 3 is $X \pmod 3$, the minimum number of draws is simply $X \pmod 3$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing a single modulo operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Score for A: X = 3 * wA + D
 * Score for B: Y = 3 * wB + D
 * 
 * Taking modulo 3:
 * X % 3 = (3 * wA + D) % 3 = D % 3
 * 
 * Since we want to minimize D, the smallest non-negative value 
 * satisfying this is D = X % 3.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // The minimum number of draws is simply X % 3
        cout << (x % 3) << "\n";
    }

    return 0;
}
```