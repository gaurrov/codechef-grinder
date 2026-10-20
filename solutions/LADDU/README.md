# [Laddu (LADDU)](https://www.codechef.com/problems/LADDU)

- **Difficulty Rating**: 1241
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to calculate the maximum number of months a user can redeem their "Laddus" for, based on their activity history and their origin (Indian or Non-Indian). Each activity earns a specific amount of Laddus, and the redemption threshold depends on the user's origin:
- **INDIAN**: 200 Laddus per month.
- **NON_INDIAN**: 400 Laddus per month.

## Intuition & Mathematical Observation
The problem is a straightforward simulation. We need to parse the activity list and accumulate the total Laddus earned:
1. **CONTEST_WON**: Base 300 + bonus `max(0, 20 - rank)`.
2. **TOP_CONTRIBUTOR**: Fixed 300.
3. **BUG_FOUND**: Variable based on `severity`.
4. **CONTEST_HOSTED**: Fixed 50.

Once the total sum is calculated, the number of months is simply the integer division of `total_laddus` by the `threshold` (200 or 400). Since the constraints are small and the operations are linear, a simple loop is sufficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the total number of activities across all test cases. We iterate through each activity exactly once.
- **Space Complexity**: $O(1)$, as we only store a few variables to keep track of the running total and current activity data.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Calculate total laddus based on activity rules:
 *    - CONTEST_WON rank: 300 + max(0, 20 - rank)
 *    - TOP_CONTRIBUTOR: 300
 *    - BUG_FOUND severity: severity
 *    - CONTEST_HOSTED: 50
 * 2. Determine redemption threshold based on origin:
 *    - INDIAN: 200
 *    - NON_INDIAN: 400
 * 3. Calculate max months: total_laddus / threshold
 */

void solve() {
    int activities;
    string origin;
    cin >> activities >> origin;

    long long total_laddus = 0;

    for (int i = 0; i < activities; ++i) {
        string type;
        cin >> type;
        if (type == "CONTEST_WON") {
            int rank;
            cin >> rank;
            total_laddus += 300;
            if (rank < 20) {
                total_laddus += (20 - rank);
            }
        } else if (type == "TOP_CONTRIBUTOR") {
            total_laddus += 300;
        } else if (type == "BUG_FOUND") {
            int severity;
            cin >> severity;
            total_laddus += severity;
        } else if (type == "CONTEST_HOSTED") {
            total_laddus += 50;
        }
    }

    int threshold = (origin == "INDIAN") ? 200 : 400;
    cout << (total_laddus / threshold) << "\n";
}

int main() {
    // Fast I/O
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