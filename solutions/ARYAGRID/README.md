# [Arya In Grid (ARYAGRID)](https://www.codechef.com/problems/ARYAGRID)

- **Difficulty Rating**: 1341
- **Solved in**: 1 attempt(s)

## Problem Summary
Arya is placed at a starting coordinate $(X_0, Y_0)$ on an $N \times M$ grid. She can move exactly $L$ units in any of the four cardinal directions (up, down, left, right). We need to determine the total number of distinct cells $(x, y)$ within the grid boundaries ($1 \le x \le N$ and $1 \le y \le M$) that Arya can reach.

## Intuition & Mathematical Observation
The movement in the $X$ (row) and $Y$ (column) dimensions are independent. Arya can reach a row $x$ if and only if $x \equiv X_0 \pmod L$ and $1 \le x \le N$. Similarly, she can reach a column $y$ if and only if $y \equiv Y_0 \pmod L$ and $1 \le y \le M$.

Because the movements are independent, the total number of reachable cells is simply the product of the number of reachable rows and the number of reachable columns:
$$\text{Total Cells} = (\text{Count of valid } x) \times (\text{Count of valid } y)$$

To find the count of valid rows:
1. **Minimum reachable row**: The smallest $x \ge 1$ such that $x = X_0 - k \cdot L$. This is calculated as $X_0 - \lfloor \frac{X_0 - 1}{L} \rfloor \cdot L$.
2. **Maximum reachable row**: The largest $x \le N$ such that $x = X_0 + k \cdot L$. This is calculated as $X_0 + \lfloor \frac{N - X_0}{L} \rfloor \cdot L$.
3. **Count**: Since these form an arithmetic progression with common difference $L$, the count is $\frac{\text{max\_r} - \text{min\_r}}{L} + 1$.

The same logic applies to the columns using $M$ and $Y_0$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses simple arithmetic operations.
- **Space Complexity**: $O(1)$, as we only store a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Arya starts at (X0, Y0) and can jump exactly L units in 4 directions.
 * This means Arya can reach any cell (x, y) such that:
 * x = X0 + k1 * L, where 1 <= x <= N
 * y = Y0 + k2 * L, where 1 <= y <= M
 * 
 * Since the movement is independent in the X and Y dimensions, the set of 
 * reachable cells is the Cartesian product of reachable rows and reachable columns.
 */

void solve() {
    long long N, M, X0, Y0, L;
    if (!(cin >> N >> M >> X0 >> Y0 >> L)) return;

    // Calculate number of reachable rows
    // Smallest r >= 1: X0 - ((X0 - 1) / L) * L
    // Largest r <= N: X0 + ((N - X0) / L) * L
    long long min_r = X0 - ((X0 - 1) / L) * L;
    long long max_r = X0 + ((N - X0) / L) * L;
    long long count_r = (max_r - min_r) / L + 1;

    // Calculate number of reachable columns
    long long min_c = Y0 - ((Y0 - 1) / L) * L;
    long long max_c = Y0 + ((M - Y0) / L) * L;
    long long count_c = (max_c - min_c) / L + 1;

    cout << count_r * count_c << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```