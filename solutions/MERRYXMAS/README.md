# [Merry Christmas! (MERRYXMAS)](https://www.codechef.com/problems/MERRYXMAS)

- **Difficulty Rating**: 454
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $X$ hours to complete three specific activities that take 1, 2, and 4 hours respectively. The goal is to determine the maximum number of activities you can complete within the given time $X$.

## Intuition & Mathematical Observation
To maximize the number of activities completed, we should always prioritize the activities with the shortest durations. This is a classic **Greedy Algorithm** approach.

1.  **Sort the durations**: The durations are already given as 1, 2, and 4.
2.  **Greedy Strategy**: 
    *   First, attempt to complete the 1-hour activity.
    *   If time remains, attempt the 2-hour activity.
    *   If time still remains, attempt the 4-hour activity.
3.  **Logic**: By subtracting the smallest durations first, we ensure that we fit as many items as possible into the total time $X$.

**Thresholds:**
- If $X < 1$: 0 activities.
- If $1 \le X < 3$: 1 activity (1 hour).
- If $3 \le X < 7$: 2 activities (1 + 2 = 3 hours).
- If $X \ge 7$: 3 activities (1 + 2 + 4 = 7 hours).

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three activities with durations: 1, 2, and 4 hours.
 * To maximize the number of activities completed within X hours, we should
 * always pick the activities with the smallest durations first (Greedy approach).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    int count = 0;
    
    // Attempt to complete the 1-hour activity
    if (X >= 1) {
        count++;
        X -= 1;
    }
    // Attempt to complete the 2-hour activity
    if (X >= 2) {
        count++;
        X -= 2;
    }
    // Attempt to complete the 4-hour activity
    if (X >= 4) {
        count++;
        X -= 4;
    }

    cout << count << "\n";

    return 0;
}
```