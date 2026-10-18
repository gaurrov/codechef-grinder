# [Anti Adjacent Swaps (ANADSW)](https://www.codechef.com/problems/ANADSW)

- **Difficulty Rating**: 1306
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$, we are allowed to swap any two elements $A[i]$ and $A[j]$ if and only if $|i - j| > 1$. We need to determine if it is possible to sort the array in non-decreasing order using any number of these operations.

## Intuition & Mathematical Observation
The core of the problem lies in the constraints imposed by the swap condition $|i - j| > 1$:

1.  **$N = 1$**: The array is trivially sorted. Always **YES**.
2.  **$N = 2$**: We can only swap if $|i - j| > 1$. Since the only indices are $0$ and $1$, $|0 - 1| = 1$. No swaps are possible. The array must be sorted initially. **YES** if $A[0] \le A[1]$, else **NO**.
3.  **$N = 3$**: We can swap $A[0]$ and $A[2]$ because $|0 - 2| = 2 > 1$. We cannot swap $A[0], A[1]$ or $A[1], A[2]$. Thus, we can either keep the original array or swap the first and last elements. We check if either configuration is sorted.
4.  **$N \ge 4$**: With at least 4 elements, we have enough "buffer" space to move any element to any position. For any two adjacent elements $A[i]$ and $A[i+1]$, we can use a third element at index $k$ (where $|k-i| \ge 2$ and $|k-(i+1)| \ge 2$) to perform a series of swaps that effectively swaps $A[i]$ and $A[i+1]$. Since we can swap any adjacent pair, we can perform a bubble sort. Thus, for $N \ge 4$, the answer is always **YES**.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we perform a simple check for $N=3$ and constant time operations for other cases.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We can swap any two elements A[i] and A[j] if |i - j| > 1.
 * 
 * For N >= 4, we can always sort the array because we have enough 
 * buffer elements to swap any adjacent pair.
 * For N = 3, we can only swap the first and last elements.
 * For N = 2, no swaps are possible.
 * For N = 1, it is already sorted.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    if (N == 1) {
        cout << "YES" << "\n";
    } else if (N == 2) {
        if (A[0] <= A[1]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else if (N == 3) {
        // Check if already sorted
        bool sorted = is_sorted(A.begin(), A.end());
        if (sorted) {
            cout << "YES" << "\n";
            return;
        }
        // Try swapping 1st and 3rd elements
        swap(A[0], A[2]);
        if (is_sorted(A.begin(), A.end())) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else {
        // For N >= 4, we can always sort the array
        cout << "YES" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```