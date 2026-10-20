# [Expensive Buying (BUYING7)](https://www.codechef.com/problems/BUYING7)

- **Difficulty Rating**: 635
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ items, each with a specific price $C_i$. Your task is to select exactly $K$ items such that the total cost of these items is maximized. In other words, you need to find the sum of the $K$ most expensive items available.

## Intuition & Mathematical Observation
To maximize the sum of $K$ items, we should always pick the items with the highest prices. 
1. **Sorting**: By sorting the array of prices in descending order, the largest elements will occupy the first $K$ positions (indices $0$ to $K-1$).
2. **Summation**: Once sorted, we simply iterate through the first $K$ elements and accumulate their values.
3. **Data Types**: Given the constraints ($N \le 100$ and $C_i \le 100$), the maximum possible sum is $10,000$. While a standard `int` is sufficient, using `long long` is a safe practice to prevent potential overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, where $N$ is the number of items. This is dominated by the sorting step. Given $T$ test cases, the total complexity is $O(T \times N \log N)$.
- **Space Complexity**: $O(N)$ to store the prices of the items in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N items with prices C_i. We need to find the sum of the K most expensive items.
 * To do this, we can sort the array of prices in descending order and sum the first K elements.
 * 
 * Constraints:
 * T <= 100, N <= 100, C_i <= 100.
 * The maximum possible sum is 100 * 100 = 10,000, which fits comfortably in a standard integer.
 * However, using long long is good practice for competitive programming to avoid overflow.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    
    // Sort the prices in descending order
    sort(C.begin(), C.end(), greater<int>());
    
    // Sum the first K elements
    long long total_cost = 0;
    for (int i = 0; i < K; ++i) {
        total_cost += C[i];
    }
    
    cout << total_cost << "\n";
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