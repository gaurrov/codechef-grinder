# [Gem Bundles (GEMBUND)](https://www.codechef.com/problems/GEMBUND)

- **Difficulty Rating**: 603
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $R$ red gems, $B$ blue gems, and $G$ green gems. Each individual gem can be sold for 3 coins. Alternatively, you can combine one of each color (1 Red, 1 Blue, 1 Green) into a "bundle" which sells for 10 coins. The goal is to maximize the total number of coins earned by choosing the optimal number of bundles to create.

## Intuition & Mathematical Observation
Let $k$ be the number of bundles created. Since a bundle requires one of each color, $k$ can range from $0$ to $\min(R, B, G)$.

If we create $k$ bundles, we use $k$ gems of each color. The remaining gems are $(R-k)$, $(B-k)$, and $(G-k)$.
The total coins earned can be expressed as:
$$\text{Total} = (k \times 10) + ((R-k) + (B-k) + (G-k)) \times 3$$

Expanding this:
$$\text{Total} = 10k + 3(R + B + G - 3k)$$
$$\text{Total} = 10k + 3(R + B + G) - 9k$$
$$\text{Total} = k + 3(R + B + G)$$

Since $3(R + B + G)$ is a constant value regardless of how many bundles we make, to maximize the total coins, we must maximize $k$. Therefore, the optimal strategy is to create as many bundles as possible:
$$k = \min(R, B, G)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and a minimum comparison.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have R red, B blue, and G green gems.
 * Each gem sells for 3 coins individually.
 * A bundle of (1R, 1B, 1G) sells for 10 coins.
 * 
 * Let k be the number of bundles we make.
 * k can range from 0 to min(R, B, G).
 * If we make k bundles, we use k of each gem.
 * Remaining gems: (R-k) red, (B-k) blue, (G-k) green.
 * Total coins = (k * 10) + ((R-k) + (B-k) + (G-k)) * 3
 *             = 10k + 3(R + B + G - 3k)
 *             = 10k + 3(R + B + G) - 9k
 *             = k + 3(R + B + G)
 * 
 * To maximize this, we need to maximize k.
 * Therefore, k = min(R, min(B, G)).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long r, b, g;
        cin >> r >> b >> g;

        // Calculate maximum number of bundles possible
        long long k = min({r, b, g});

        // Calculate total coins
        // Formula: k * 10 + (remaining gems) * 3
        long long remaining_gems = (r - k) + (b - k) + (g - k);
        long long total_coins = (k * 10) + (remaining_gems * 3);

        cout << total_coins << "\n";
    }

    return 0;
}
```