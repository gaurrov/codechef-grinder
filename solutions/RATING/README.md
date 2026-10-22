# [The Rating Dilemma (RATING)](https://www.codechef.com/problems/RATING)

- **Difficulty Rating**: 909
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given an integer $S$, which represents the sum of two integers $X$ and $Y$ (i.e., $X + Y = S$). We are given the constraints that $X$ must be greater than $Y$ (implied by the context of ratings where $X$ is the new rating and $Y$ is the change, though the problem specifically asks to maximize $X \cdot Y$ given $Y < 0$ and $X > 0$). Our goal is to find the values of $X$ and $Y$ that maximize the product $X \cdot Y$.

## Intuition & Mathematical Observation
We are given the equation:
$X + Y = S \implies Y = S - X$

We want to maximize the product $P = X \cdot Y$. Substituting $Y$:
$P = X(S - X) = SX - X^2$

This is a downward-opening parabola. To maximize the product, we want $X$ and $Y$ to be as close to each other as possible. However, we are constrained by the fact that $Y$ must be a negative integer ($Y < 0$). 

To make $X$ and $Y$ as close as possible while keeping $Y$ negative, we should choose the largest possible value for $Y$. The largest negative integer is $-1$.

If we set $Y = -1$:
$X + (-1) = S \implies X = S + 1$

Substituting these into the product:
$P = (S + 1) \cdot (-1) = -(S + 1)$

Since $S$ can be up to $10^9$, the result will fit within a standard 64-bit integer (`long long` in C++).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only a single addition and negation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem: RATING
 * Logic:
 * We are given X + Y = S, with X > 0 and Y < 0.
 * We want to maximize X * Y.
 * Since Y = S - X, the product is X(S - X) = SX - X^2.
 * To maximize this, we want X and Y to be as close to each other as possible.
 * However, Y must be negative. The largest negative integer is -1.
 * If we set Y = -1, then X = S + 1.
 * The product is (S + 1) * (-1) = -(S + 1).
 */

using namespace std;

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        long long S;
        cin >> S;
        // The maximum product is -(S + 1)
        cout << -(S + 1) << "\n";
    }

    return 0;
}
```