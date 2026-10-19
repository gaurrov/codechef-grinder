# [Placing 01 And 10 (PLACE0110)](https://www.codechef.com/problems/PLACE0110)

- **Difficulty Rating**: 1114
- **Solved in**: 2 attempt(s)

## Problem Summary
We are given $X$ strings of `"01"` and $Y$ strings of `"10"`. We need to arrange all these $X+Y$ strings in a sequence such that the total number of transitions (where a character changes from `0` to `1` or `1` to `0`) in the resulting concatenated string is minimized.

## Intuition & Mathematical Observation
Each individual string (`"01"` or `"10"`) contains exactly one transition. When we concatenate two strings, a new transition is created at the boundary if the last character of the first string differs from the first character of the second string.

1.  **Internal Transitions**: Every string contributes 1 to the total count. Total internal transitions = $X + Y$.
2.  **Boundary Transitions**:
    *   `"01"` ends in `1`, starts with `0`.
    *   `"10"` ends in `0`, starts with `1`.
    *   If we alternate them (e.g., `01` + `10` + `01` + `10`...), the boundary characters are the same (e.g., `...1` followed by `1...` or `...0` followed by `0...`), resulting in **0** additional transitions at the boundaries.
3.  **Handling Excess**:
    *   If $X = Y$, we can perfectly alternate them (e.g., `01100110...`), resulting in $X+Y$ total transitions.
    *   If $X \neq Y$, we will have an excess of one type. Once we exhaust the pairs, the remaining strings of the same type must be placed next to each other. Placing two identical strings side-by-side (e.g., `01` + `01`) creates a transition at the boundary because the end (`1`) and start (`0`) differ.
    *   Specifically, if we have $N$ strings, there are $N-1$ boundaries. If we alternate as much as possible, we minimize the boundary transitions to $|X - Y| - 1$ (if $X, Y > 0$).

**Refined Logic**:
- If $X=0$ or $Y=0$, we have only one type of string. Concatenating $N$ identical strings creates $N-1$ boundary transitions plus $N$ internal transitions, totaling $2N-1$.
- If $X > 0$ and $Y > 0$:
    - If $X = Y$, total = $X + Y$.
    - If $X \neq Y$, total = $(X + Y) + (|X - Y| - 1)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses simple arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few integer variables.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Problem: PLACE0110
 * We have X strings of "01" and Y strings of "10".
 * Each string has 1 internal transition.
 * Concatenating two strings creates an extra transition if the boundary characters differ.
 */

void solve() {
    int X, Y;
    cin >> X >> Y;
    
    // Case where only one type of string exists
    if (X == 0 || Y == 0) {
        cout << X + Y - 1 << endl;
    } else {
        int diff = abs(X - Y);
        // If equal, we can alternate perfectly
        if (diff == 0) {
            cout << X + Y << endl;
        } else {
            // If unequal, we add the excess transitions
            cout << X + Y + diff - 1 << endl;
        }
    }
}

int main() {
    // Optimize I/O operations
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