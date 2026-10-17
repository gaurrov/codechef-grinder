# [Snape and Ladder (SNAPE)](https://www.codechef.com/problems/SNAPE)

- **Difficulty Rating**: 828
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the base $B$ (the distance between the two points where the sticks touch the ground) and the length of one stick $LS$, we need to find the minimum and maximum possible values for the length of the second stick $RS$ such that the two sticks meet at a point to form a triangle with the base $B$.

## Intuition & Mathematical Observation
The problem describes a triangle with sides $LS$, $RS$, and base $B$. Let $H$ be the vertical height from the ground to the point where the two sticks meet. The base $B$ is divided into two segments, $x$ and $y$, such that $x + y = B$.

Based on the Pythagorean theorem:
1. $LS^2 = H^2 + x^2$
2. $RS^2 = H^2 + y^2$

**1. Minimum $RS$:**
The minimum height $H$ occurs when the stick $LS$ is tilted as much as possible, effectively making it the hypotenuse of a right triangle with base $B$ and height $H$. In the extreme case where the second stick $RS$ is vertical ($y=0$), we have $H = RS$. Substituting this into the first equation:
$LS^2 = RS^2 + B^2 \implies RS^2 = LS^2 - B^2$
Thus, **min $RS = \sqrt{LS^2 - B^2}$**.

**2. Maximum $RS$:**
The maximum height $H$ occurs when the stick $LS$ is placed vertically ($x=0$), making $H = LS$. In this configuration, the second stick $RS$ forms a right triangle with the height $H$ and the base $B$:
$RS^2 = H^2 + B^2 = LS^2 + B^2$
Thus, **max $RS = \sqrt{LS^2 + B^2}$**.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and square root calculations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given base B and length LS. We need to find the range of RS.
 * Min RS occurs when the triangle is as "flat" as possible (RS is vertical).
 * Max RS occurs when the triangle is as "tall" as possible (LS is vertical).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        double b, ls;
        cin >> b >> ls;

        // Minimum RS: sqrt(LS^2 - B^2)
        // Maximum RS: sqrt(LS^2 + B^2)
        double min_rs = sqrt(max(0.0, ls * ls - b * b));
        double max_rs = sqrt(ls * ls + b * b);

        cout << fixed << setprecision(6) << min_rs << " " << max_rs << "\n";
    }

    return 0;
}
```