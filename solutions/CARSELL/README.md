# [Sell All the Cars (CARSELL)](https://www.codechef.com/problems/CARSELL)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef owns $N$ cars, each with an initial price $P_i$. Every year, the price of every unsold car decreases by 1 unit (the price cannot drop below 0). Chef can sell at most one car per year. The goal is to determine the maximum total profit Chef can achieve by choosing the optimal order to sell the cars.

## Intuition & Mathematical Observation
To maximize the total profit, we must minimize the total depreciation of the cars. Since every car's price decreases by 1 each year, the total loss is determined by how long a car remains unsold. 

1. **Greedy Strategy**: We should sell the most expensive cars as early as possible. By selling the car with the highest current price first, we prevent its value from decreasing further in subsequent years.
2. **Sorting**: If we sort the initial prices in descending order ($P_0 \ge P_1 \ge \dots \ge P_{N-1}$), the $i$-th car (0-indexed) will be sold in the $(i+1)$-th year.
3. **Price Calculation**: By the time we reach the $i$-th car in our sorted list, it has been subjected to $i$ years of depreciation. Therefore, its selling price will be $\max(0, P_i - i)$.
4. **Modulo Arithmetic**: Since the total profit can be very large, we perform all additions modulo $10^9 + 7$.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the number of cars. The bottleneck is sorting the array of prices for each test case. Given $N \le 10^5$, this fits comfortably within the 1-second time limit.
- **Space Complexity**: $O(N)$ to store the prices of the cars.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize profit, we sell the most expensive cars first.
 * Sorting prices in descending order ensures that the i-th car sold
 * has been depreciated by exactly i years.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // Sort in descending order to sell the most expensive cars first
    sort(P.begin(), P.end(), greater<long long>());

    long long total_profit = 0;
    const long long MOD = 1000000007;

    for (int i = 0; i < N; ++i) {
        // Price at year i is max(0, P[i] - i)
        long long current_price = max(0LL, P[i] - i);
        total_profit = (total_profit + current_price) % MOD;
    }

    cout << total_profit << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```