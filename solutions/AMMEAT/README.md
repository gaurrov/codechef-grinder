# [Andrew and the Meatballs (AMMEAT)](https://www.codechef.com/problems/AMMEAT)

- **Difficulty Rating**: 1275
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ plates, each containing a specific number of meatballs. We need to select the minimum number of plates such that the total number of meatballs collected is at least $M$. If it is impossible to reach the target $M$ even by selecting all available plates, we should output -1.

## Intuition & Mathematical Observation
To minimize the number of plates used, we should prioritize plates that contain the highest number of meatballs. This is a classic **Greedy** problem:

1. **Greedy Strategy**: By sorting the plates in descending order, we ensure that each plate we add contributes the maximum possible amount to our current sum. This allows us to reach the target $M$ using the fewest number of elements.
2. **Feasibility Check**: Before attempting to select plates, we must check if the sum of all meatballs across all plates is less than $M$. If `total_sum < M`, it is mathematically impossible to satisfy the condition, and we return -1.
3. **Data Types**: Since $M$ and the number of meatballs per plate can be as large as $10^{18}$, it is crucial to use `long long` in C++ to prevent integer overflow.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan through the sorted array takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the number of meatballs in each of the $N$ plates.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N plates with P_i meatballs. We need to select the minimum number of plates
 * such that the sum of meatballs is at least M.
 * 
 * Strategy:
 * 1. To minimize the number of plates, we should always pick the plates with the 
 *    largest number of meatballs first (Greedy approach).
 * 2. Sort the array of meatballs in descending order.
 * 3. Calculate the prefix sum or keep adding elements until the sum is >= M.
 * 4. If the total sum of all plates is less than M, it's impossible, so output -1.
 */

void solve() {
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> p(n);
    long long total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        total_sum += p[i];
    }

    // If total meatballs available are less than required, impossible.
    if (total_sum < m) {
        cout << -1 << "\n";
        return;
    }

    // Sort in descending order to pick the largest plates first.
    sort(p.rbegin(), p.rend());

    long long current_sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        current_sum += p[i];
        count++;
        if (current_sum >= m) {
            cout << count << "\n";
            return;
        }
    }
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