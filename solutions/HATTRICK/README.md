# [Hattrick (HATTRICK)](https://www.codechef.com/problems/HATTRICK)

- **Difficulty Rating**: 853
- **Solved in**: 1 attempt(s)

## Problem Summary
In a cricket match, a "hattrick" is defined as taking three wickets in three consecutive balls. Given a sequence of 6 balls (where each ball is represented as either a run value or 'W' for a wicket), determine if a hattrick occurred at any point during the over.

## Intuition & Mathematical Observation
Since the input size is fixed at 6 balls, we can represent the sequence as an array or vector of strings. A hattrick occurs if there exists an index $i$ such that the elements at $i, i+1,$ and $i+2$ are all equal to "W".

Given the constraints:
- The total number of balls is 6.
- We need to check for a sequence of 3.
- The possible starting indices for a 3-ball window are $0, 1, 2,$ and $3$.

By iterating through these four possible windows, we can easily detect if three consecutive 'W's exist. If we find such a window, we output "YES"; otherwise, we output "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since the number of balls is fixed at 6, the loop runs a constant number of times (4 iterations), making the operation independent of input size.
- **Space Complexity**: $O(1)$. We only store 6 strings in a vector, which occupies a constant amount of memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: HATTRICK
 * A hattrick occurs if there are three consecutive 'W's in the sequence of 6 balls.
 * We read the 6 inputs as strings to handle both digits and 'W'.
 * We check all possible windows of size 3:
 * (0,1,2), (1,2,3), (2,3,4), (3,4,5)
 */

void solve() {
    vector<string> balls(6);
    for (int i = 0; i < 6; ++i) {
        cin >> balls[i];
    }

    bool hattrick = false;
    // Check for 3 consecutive wickets
    // We iterate up to index 3 so that i+2 does not exceed the array bounds (5)
    for (int i = 0; i <= 3; ++i) {
        if (balls[i] == "W" && balls[i + 1] == "W" && balls[i + 2] == "W") {
            hattrick = true;
            break;
        }
    }

    if (hattrick) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```