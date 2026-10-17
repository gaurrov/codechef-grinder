# [Far from origin (FARFROMO)](https://www.codechef.com/problems/FARFROMO)

- **Difficulty Rating**: 750
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the coordinates of two points, Alex at $(X_1, Y_1)$ and Bob at $(X_2, Y_2)$, determine who is further from the origin $(0, 0)$. If Alex is further, output "ALEX". If Bob is further, output "BOB". If they are at the same distance, output "EQUAL".

## Intuition & Mathematical Observation
The distance of a point $(x, y)$ from the origin $(0, 0)$ is defined by the Euclidean distance formula:
$$d = \sqrt{x^2 + y^2}$$

To compare the distances of Alex and Bob, we need to compare $\sqrt{X_1^2 + Y_1^2}$ and $\sqrt{X_2^2 + Y_2^2}$. 

**Key Optimization:**
Calculating the square root is computationally expensive and can introduce floating-point precision errors. Since the square root function is monotonically increasing for non-negative values, we can compare the **squared distances** instead:
- Alex's squared distance: $D_1^2 = X_1^2 + Y_1^2$
- Bob's squared distance: $D_2^2 = X_2^2 + Y_2^2$

If $D_1^2 > D_2^2$, then Alex is further. If $D_2^2 > D_1^2$, then Bob is further. If $D_1^2 = D_2^2$, they are at an equal distance. Given the constraints (coordinates between -1000 and 1000), the maximum squared distance is $2,000,000$, which fits easily within a standard integer type.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the coordinates and squared distances.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The distance of a point (x, y) from the origin (0, 0) is given by the formula:
 * Distance = sqrt(x^2 + y^2)
 * To compare the distances of Alex (X1, Y1) and Bob (X2, Y2), we can compare
 * the squared distances to avoid floating point precision issues and the 
 * expensive sqrt() function.
 * 
 * Squared Distance for Alex: D1^2 = X1^2 + Y1^2
 * Squared Distance for Bob: D2^2 = X2^2 + Y2^2
 * 
 * Since X, Y are between -1000 and 1000, the squared distance will be at most
 * 1000^2 + 1000^2 = 2,000,000, which fits comfortably within a standard 32-bit integer.
 * However, using long long is good practice to prevent any potential overflow.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        long long dist1_sq = x1 * x1 + y1 * y1;
        long long dist2_sq = x2 * x2 + y2 * y2;

        if (dist1_sq > dist2_sq) {
            cout << "ALEX" << "\n";
        } else if (dist2_sq > dist1_sq) {
            cout << "BOB" << "\n";
        } else {
            cout << "EQUAL" << "\n";
        }
    }

    return 0;
}
```