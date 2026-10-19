# [Reselling Items (RESELL)](https://www.codechef.com/problems/RESELL)

- **Difficulty Rating**: 903
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ items, each with a specific resale value $A_i$. He can purchase these items to resell them. The cost structure is as follows:
- The first $K$ items purchased cost 5 coins each.
- Any additional items purchased beyond the first $K$ cost 10 coins each.

The goal is to maximize the total profit, where profit for a single item is defined as `(Resale Value - Cost)`. We only purchase an item if it yields a positive profit.

## Intuition & Mathematical Observation
To maximize the total profit, we must be strategic about which items we buy and how we assign the costs:

1.  **Greedy Strategy**: Since we want to maximize profit, we should prioritize items with the highest resale values. By sorting the items in descending order, we ensure that the most valuable items are considered first.
2.  **Cost Assignment**: We have $K$ "cheap" slots (cost 5) and unlimited "expensive" slots (cost 10). To maximize the sum, we should assign the cheaper cost (5) to the items with the highest resale values.
3.  **Profitability Constraint**: We only purchase an item if the resale value is strictly greater than the cost associated with that slot. If $A_i \le \text{cost}$, buying the item would result in zero or negative profit, so we skip it.

**Algorithm**:
1. Sort the array $A$ in descending order.
2. Iterate through the sorted array. For the first $K$ indices, use a cost of 5. For indices $\ge K$, use a cost of 10.
3. If $A_i > \text{cost}$, add $(A_i - \text{cost})$ to the total profit.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the resale values of the items.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N items with resale values A_i.
 * The first K items bought cost 5 coins each.
 * Any subsequent items bought cost 10 coins each.
 * Profit for an item = (Resale Value) - (Cost).
 * 
 * To maximize profit:
 * 1. We should only buy items where the profit is positive.
 * 2. We want to assign the cheapest costs (5 coins) to the items with the highest resale values.
 * 3. Sort the resale values in descending order.
 * 4. For the first K items in the sorted list, profit is (A_i - 5).
 * 5. For the remaining items, profit is (A_i - 10).
 * 6. We only include an item if its individual profit is > 0.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort in descending order to prioritize highest resale values
    sort(A.begin(), A.end(), greater<int>());

    long long total_profit = 0;
    for (int i = 0; i < N; ++i) {
        int cost;
        if (i < K) {
            cost = 5;
        } else {
            cost = 10;
        }

        // Only buy if it results in a profit
        if (A[i] > cost) {
            total_profit += (A[i] - cost);
        }
    }

    cout << total_profit << "\n";
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