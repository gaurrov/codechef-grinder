# [IPL and RCB (CLIPLX)](https://www.codechef.com/problems/CLIPLX)

- **Difficulty Rating**: 1167
- **Solved in**: 2 attempt(s)

## Problem Summary
In the IPL, a team earns 2 points for a win and 1 point for a tie. Given a target of $X$ points and a total of $Y$ matches played, we need to find the **minimum** number of wins required to achieve at least $X$ points.

## Intuition & Mathematical Observation
Let $W$ be the number of wins and $T$ be the number of ties. We are given:
1. $W + T = Y$ (Total matches played)
2. $2W + T \ge X$ (Total points required)

From the first equation, we can express ties as $T = Y - W$. Substituting this into the second equation:
$2W + (Y - W) \ge X$
$W + Y \ge X$
$W \ge X - Y$

Since the number of wins cannot be negative, the minimum number of wins required is:
$W = \max(0, X - Y)$

If the number of matches $Y$ is already greater than or equal to the points $X$, we can achieve the target using only ties (or a mix), resulting in 0 wins. Otherwise, every win beyond the number of matches provides the necessary "extra" point to reach the target.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic calculation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem: CLIPLX
 * Logic: 
 * Let W be the number of wins.
 * Points = 2 * W + (Ties).
 * To minimize W, we maximize Ties.
 * Max Ties = Y - W.
 * Total Points = 2W + (Y - W) = W + Y.
 * We need W + Y >= X, so W >= X - Y.
 * Since W cannot be negative, W = max(0, X - Y).
 */

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // If X <= Y, we can get all points by tying, so 0 wins needed.
        // If X > Y, we need (X - Y) wins.
        int wins = max(0, x - y);
        cout << wins << "\n";
    }
    
    return 0;
}
```