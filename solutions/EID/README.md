# [Chef and Eid (EID)](https://www.codechef.com/problems/EID)

- **Difficulty Rating**: 1135
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ coins with various values, the goal is to select two distinct coins such that the absolute difference between their values is minimized. We need to output this minimum difference.

## Intuition & Mathematical Observation
To minimize the difference between any two elements in a set, the most efficient approach is to sort the set first. 

1. **Sorting**: Once the array is sorted in non-decreasing order ($a_1 \le a_2 \le \dots \le a_N$), the minimum difference between any two elements must exist between two **adjacent** elements.
2. **Proof**: Consider any two indices $i$ and $j$ where $i < j$. The difference $a_j - a_i$ can be expressed as the sum of differences of adjacent elements: $(a_j - a_{j-1}) + (a_{j-1} - a_{j-2}) + \dots + (a_{i+1} - a_i)$. Since all coin values are non-negative, each individual term $(a_{k+1} - a_k)$ is less than or equal to the total sum $(a_j - a_i)$. Therefore, the minimum difference is guaranteed to be found by checking only adjacent pairs.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, dominated by the sorting step. The subsequent linear scan takes $O(N)$. Given the constraint $\sum N \le 5 \times 10^5$, this approach is well within the time limit.
- **Space Complexity**: $O(N)$ to store the coin values in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N coins with values v_1, v_2, ..., v_N.
 * We need to choose two distinct coins such that the absolute difference 
 * between their values is minimized.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    
    // Sort the coin values to bring the closest values next to each other
    sort(v.begin(), v.end());
    
    // Initialize min_diff with a large value
    // The problem constraints state coin values are up to 10^6
    long long min_diff = 2000000; 
    
    // Check differences between adjacent elements
    for (int i = 0; i < N - 1; ++i) {
        long long diff = v[i + 1] - v[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
        // Optimization: if diff is 0, it's the smallest possible absolute difference
        if (min_diff == 0) break;
    }
    
    cout << min_diff << "\n";
}

int main() {
    // Fast I/O setup
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