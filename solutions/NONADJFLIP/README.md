# [Non Adjacent Flips (NONADJFLIP)](https://www.codechef.com/problems/NONADJFLIP)

- **Difficulty Rating**: 1128
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a binary string $S$ of length $N$. In one operation, we can choose any subset of indices such that no two indices in the subset are adjacent, and flip the bits at these indices (0 becomes 1, 1 becomes 0). The goal is to find the minimum number of operations required to transform the entire string into all zeros.

## Intuition & Mathematical Observation
To solve this problem, we analyze the state of the string based on the distribution of '1's:

1.  **Case 0: No '1's present.**
    If the string is already all zeros, the number of operations required is **0**.

2.  **Case 1: No adjacent '1's.**
    If there are '1's present but no two '1's are adjacent, we can simply select all indices containing '1' in a single operation. Since no two '1's are adjacent, this set of indices is valid. The answer is **1**.

3.  **Case 2: Adjacent '1's exist.**
    If there is at least one pair of adjacent '1's, we cannot clear the string in a single operation because we cannot select both adjacent '1's simultaneously. However, we can always clear the string in **2** operations:
    *   **Operation 1:** Select all '1's at odd-indexed positions.
    *   **Operation 2:** Select all '1's at even-indexed positions.
    Since no two adjacent indices share the same parity, both sets are guaranteed to be non-adjacent. Thus, 2 operations are always sufficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform a single pass through the string to check for the existence of '1's and adjacent '1's.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. If there are no 1s, the answer is 0.
 * 2. If there are no adjacent 1s, we can flip all 1s in a single operation.
 *    The answer is 1.
 * 3. If there are adjacent 1s, we can split the 1s into two sets (odd indices 
 *    and even indices). Since no two adjacent indices have the same parity, 
 *    both sets are valid. The answer is 2.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool has_one = false;
    bool has_adjacent_ones = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            has_one = true;
            if (i + 1 < N && S[i + 1] == '1') {
                has_adjacent_ones = true;
            }
        }
    }

    if (!has_one) {
        cout << 0 << "\n";
    } else if (has_adjacent_ones) {
        cout << 2 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
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