# [Mirror Swap (MRSWAP)](https://www.codechef.com/problems/MRSWAP)

- **Difficulty Rating**: 667
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an array $A$ of size $2N$. You are allowed to perform a swap operation between $A[i]$ and its "mirror" element $A[2N + 1 - i]$ (using 1-based indexing). The goal is to maximize the sum of the elements in the first half of the array (indices $1$ to $N$) after performing any number of these swaps.

## Intuition & Mathematical Observation
The problem states that for every index $i$ (where $1 \le i \le N$), we have a pair of elements: $A[i]$ and $A[2N + 1 - i]$. 

Since we can swap these two elements freely, we have two choices for the value at position $i$: either keep $A[i]$ or swap it with $A[2N + 1 - i]$. To maximize the total sum of the first $N$ elements, we should independently choose the larger value from each pair $(A[i], A[2N + 1 - i])$ and place it in the first half of the array.

Mathematically, the maximum sum is:
$$\sum_{i=0}^{N-1} \max(A[i], A[2N - 1 - i])$$
(using 0-based indexing).

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the first half of the array exactly once.
- **Space Complexity**: $O(N)$ to store the input array of size $2N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array A of size 2N.
 * We can swap A[i] with A[2N + 1 - i] (1-indexed).
 * This means for each pair (A[i], A[2N + 1 - i]), we can choose which one 
 * goes into the first half and which one goes into the second half.
 * To maximize the sum of the first half (A[1]...A[N]), for each pair 
 * (A[i], A[2N + 1 - i]), we should pick the maximum of the two values 
 * to be in the first half.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the array.
 */

void solve() {
    int N;
    cin >> N;
    int size = 2 * N;
    vector<int> A(size);
    for (int i = 0; i < size; ++i) {
        cin >> A[i];
    }

    long long max_sum = 0;
    // We iterate from 0 to N-1.
    // The mirror element of A[i] is A[2N - 1 - i].
    for (int i = 0; i < N; ++i) {
        int val1 = A[i];
        int val2 = A[2 * N - 1 - i];
        max_sum += max(val1, val2);
    }

    cout << max_sum << "\n";
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