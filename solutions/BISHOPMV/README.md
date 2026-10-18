# [Bishop Moves (BISHOPMV)](https://www.codechef.com/problems/BISHOPMV)

- **Difficulty Rating**: 914
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the coordinates of two cells $(x_1, y_1)$ and $(x_2, y_2)$ on an $8 \times 8$ chessboard, determine the minimum number of moves a bishop requires to travel from the first cell to the second. If the destination is unreachable, output $-1$.

## Intuition & Mathematical Observation
A bishop moves diagonally. We can categorize the possible outcomes based on the properties of the chessboard:

1.  **Color Constraint**: A bishop always stays on squares of the same color. On a chessboard, the color of a cell $(x, y)$ is determined by the parity of the sum of its coordinates $(x + y) \pmod 2$. If $(x_1 + y_1) \pmod 2 \neq (x_2 + y_2) \pmod 2$, the cells are of different colors, making it impossible for the bishop to reach the destination. Output: **-1**.
2.  **One-Move Reachability**: Two cells are on the same diagonal if:
    *   $x_1 + y_1 = x_2 + y_2$ (Anti-diagonal)
    *   $x_1 - y_1 = x_2 - y_2$ (Main diagonal)
    *   This is equivalent to checking if $|x_1 - x_2| = |y_1 - y_2|$. If this holds, the bishop reaches the target in **1** move.
3.  **Two-Move Reachability**: If the cells are the same color but not on the same diagonal, the bishop can always reach the target in exactly **2** moves by moving to the intersection point of the two diagonals passing through the start and end cells.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic comparisons.
- **Space Complexity**: $O(1)$, as we only use a few integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A bishop moves along diagonals.
 * Two cells (x1, y1) and (x2, y2) are on the same diagonal if:
 * 1. x1 + y1 == x2 + y2 (Anti-diagonal)
 * 2. x1 - y1 == x2 - y2 (Main diagonal)
 * 
 * If they are on the same diagonal, the distance is 1.
 * If they are not on the same diagonal, we check if they are reachable.
 * A bishop can only reach cells of the same color as the starting cell.
 * The color of a cell (x, y) is determined by (x + y) % 2.
 * If (x1 + y1) % 2 != (x2 + y2) % 2, it is impossible (-1).
 * If they are the same color and not on the same diagonal, it always takes 2 moves.
 */

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Check if same color
    if ((x1 + y1) % 2 != (x2 + y2) % 2) {
        cout << -1 << "\n";
        return;
    }

    // Check if same diagonal
    // Condition: |x1 - x2| == |y1 - y2|
    if (abs(x1 - x2) == abs(y1 - y2)) {
        cout << 1 << "\n";
    } else {
        // Same color but not same diagonal, always 2 moves
        cout << 2 << "\n";
    }
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