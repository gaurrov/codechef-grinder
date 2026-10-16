# [Good Subsequence (GOODSUB7)](https://www.codechef.com/problems/GOODSUB7)

- **Difficulty Rating**: 899
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to find the length of the longest subsequence such that the parity (even or odd) of adjacent elements in the subsequence alternates. That is, if the subsequence is $S = [s_1, s_2, \dots, s_k]$, then $s_i \pmod 2 \neq s_{i+1} \pmod 2$ for all $1 \le i < k$.

## Intuition & Mathematical Observation
To solve this, we can use a Dynamic Programming approach. We maintain two variables:
1. `odd_len`: The length of the longest "good" subsequence found so far that ends with an **odd** number.
2. `even_len`: The length of the longest "good" subsequence found so far that ends with an **even** number.

As we iterate through the array:
- If the current number $x$ is **odd**, it can be appended to any good subsequence that ends in an **even** number. Therefore, the new `odd_len` becomes `even_len + 1`.
- If the current number $x$ is **even**, it can be appended to any good subsequence that ends in an **odd** number. Therefore, the new `even_len` becomes `odd_len + 1`.

By updating these values greedily as we traverse the array, we ensure that we always have the maximum possible length for both ending parities. The final answer is simply the maximum of `odd_len` and `even_len`.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the array. We perform a single pass through the input array.
- **Space Complexity**: $O(N)$ to store the input array (or $O(1)$ if we process elements on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A sequence is "good" if the parity of adjacent elements is different.
 * We want to find the length of the longest subsequence that alternates parity.
 * 
 * Let:
 * - odd_len: length of the longest good subsequence ending in an odd number.
 * - even_len: length of the longest good subsequence ending in an even number.
 * 
 * For each element x in A:
 * - If x is odd, it can extend any good subsequence ending in an even number.
 *   New odd_len = even_len + 1.
 * - If x is even, it can extend any good subsequence ending in an odd number.
 *   New even_len = odd_len + 1.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int odd_len = 0;
    int even_len = 0;

    for (int i = 0; i < N; ++i) {
        if (A[i] % 2 != 0) {
            // Current is odd, can extend a sequence ending in even
            odd_len = even_len + 1;
        } else {
            // Current is even, can extend a sequence ending in odd
            even_len = odd_len + 1;
        }
    }

    cout << max(odd_len, even_len) << "\n";
}

int main() {
    // Fast I/O
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