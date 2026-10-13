# [Peaceful Party (MAYOR_PARTY)](https://www.codechef.com/problems/MAYOR_PARTY)

- **Difficulty Rating**: 898
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the populations of three regions: $P_A$, $P_B$, and $P_C$. We need to invite people from these regions to a party such that no two invited regions are adjacent. Specifically, if we invite region $B$, we cannot invite $A$ or $C$. Conversely, if we invite $A$ or $C$, we cannot invite $B$. We want to maximize the total number of people invited.

## Intuition & Mathematical Observation
The constraint "no two adjacent regions can be invited" limits our choices to two mutually exclusive scenarios:

1.  **Scenario 1**: Invite only region $B$. The total population is $P_B$.
2.  **Scenario 2**: Invite regions $A$ and $C$. Since $A$ and $C$ are not adjacent to each other, they can both be invited simultaneously. The total population is $P_A + P_C$.

Since these are the only two valid configurations that maximize the number of regions invited without violating the adjacency rule, the answer is simply the maximum of these two sums:
$$\text{Result} = \max(P_B, P_A + P_C)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic and a comparison.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three regions A, B, and C with populations P_A, P_B, and P_C.
 * Constraints:
 * 1. If B is invited, A and C cannot be invited (due to conflict).
 * 2. If A or C are invited, B cannot be invited.
 * 
 * Possible scenarios:
 * Scenario 1: Invite people from region B. Total = P_B.
 * Scenario 2: Invite people from regions A and C. Total = P_A + P_C.
 * 
 * We need to find the maximum of these two scenarios.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long pa, pb, pc;
        cin >> pa >> pb >> pc;

        // Option 1: Invite only region B
        long long option1 = pb;
        
        // Option 2: Invite regions A and C
        long long option2 = pa + pc;

        // Output the maximum of the two options
        cout << max(option1, option2) << "\n";
    }

    return 0;
}
```