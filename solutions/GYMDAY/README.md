# [International Gym Day (GYMDAY)](https://www.codechef.com/problems/GYMDAY)

- **Difficulty Rating**: 1201
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy a gym membership that costs $X$ coins. He currently has $Y$ coins. He can participate in trial sessions, where each session costs 1 coin. For every session he participates in, he receives a discount of $D\%$ on the original price $X$. We need to find the minimum number of trial sessions $n$ Chef must attend such that he can afford the membership with his remaining budget. If it is impossible to afford the membership even after spending all his coins on sessions, output -1.

## Intuition & Mathematical Observation
The condition for Chef to afford the membership after $n$ sessions is:
1. **Remaining Budget**: $Y - n$
2. **Discounted Price**: $X \times \left(1 - \frac{n \times D}{100}\right)$

Chef can afford the membership if:
$$(Y - n) \geq X \times \left(1 - \frac{n \times D}{100}\right)$$

To avoid floating-point precision issues, we multiply both sides by 100:
$$100 \times (Y - n) \geq X \times (100 - n \times D)$$

Since the constraints are small ($X \leq 50$ and $Y$ is also small), we can iterate through all possible values of $n$ from $0$ to $Y$. The first $n$ that satisfies the inequality is our answer. If we exhaust all possibilities up to $n = Y$ without satisfying the condition, it is impossible to afford the membership.

## Complexity Analysis
- **Time Complexity**: $O(Y)$ per test case, where $Y$ is the initial budget. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and perform calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has budget Y, membership cost X.
 * Each trial session costs 1 coin.
 * After n trial sessions:
 * - Remaining budget: Y - n
 * - Discount: n * D %
 * - Membership price: X * (1 - (n * D) / 100)
 * 
 * We need to find the smallest n >= 0 such that:
 * (Y - n) >= X * (100 - n * D) / 100
 * 
 * Multiplying by 100 to avoid floating point issues:
 * 100 * (Y - n) >= X * (100 - n * D)
 */

void solve() {
    int D, X, Y;
    cin >> D >> X >> Y;

    // If Chef can already afford it without any sessions
    if (Y >= X) {
        cout << 0 << "\n";
        return;
    }

    // Iterate through possible number of sessions.
    // Chef cannot take more than Y sessions because he would have 0 coins left.
    for (int n = 1; n <= Y; ++n) {
        // Remaining budget after n sessions
        int remaining_budget = Y - n;
        
        // Discounted price check: 
        // remaining_budget * 100 >= X * (100 - n * D)
        if (remaining_budget * 100 >= X * (100 - n * D)) {
            cout << n << "\n";
            return;
        }
    }

    // If no n works
    cout << -1 << "\n";
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