# [Buy Ten Packets (TENPACKETS)](https://www.codechef.com/problems/TENPACKETS)

- **Difficulty Rating**: 669
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy exactly 10 packets of noodles. He has two options available:
1. Buy a pack of 2 for $X$ rupees.
2. Buy a pack of 4 for $Y$ rupees.

The goal is to determine the minimum cost to acquire exactly 10 packets.

## Intuition & Mathematical Observation
To get exactly 10 packets using combinations of 2-packs and 4-packs, we can represent 10 as $2a + 4b = 10$, where $a$ is the number of 2-packs and $b$ is the number of 4-packs.

The possible non-negative integer solutions for $(b, a)$ are:
1. **0 packs of 4, 5 packs of 2**: Cost = $5X$
2. **1 pack of 4, 3 packs of 2**: Cost = $Y + 3X$
3. **2 packs of 4, 1 pack of 2**: Cost = $2Y + X$

Since we want the minimum cost, we simply calculate these three values and return the minimum among them using the `min()` function.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated costs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs 10 packets.
 * Options:
 * - 2 packets for X
 * - 4 packets for Y
 * 
 * We need to represent 10 as a sum of 2s and 4s.
 * Possible combinations (number of 4-packs, number of 2-packs):
 * 1. (0, 5): 0 * Y + 5 * X = 5X
 * 2. (1, 3): 1 * Y + 3 * X = Y + 3X
 * 3. (2, 1): 2 * Y + 1 * X = 2Y + X
 * 
 * We need to find the minimum of these three values.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    // Calculate the three possible ways to get 10 packets
    long long option1 = 5 * X;
    long long option2 = Y + 3 * X;
    long long option3 = 2 * Y + X;

    // Find the minimum of the three options
    long long min_cost = min({option1, option2, option3});

    cout << min_cost << "\n";
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