# [Pseudo Sorted Array (PSEUDOSORT)](https://www.codechef.com/problems/PSEUDOSORT)

- **Difficulty Rating**: 1067
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if an array is "pseudo-sorted." An array is defined as pseudo-sorted if it is either already sorted in non-decreasing order or can be made sorted by performing exactly one swap of adjacent elements $A[i]$ and $A[i+1]$.

## Intuition & Mathematical Observation
The definition of a pseudo-sorted array implies that there can be at most one "inversion" (a pair where $A[i] > A[i+1]$) that prevents the array from being sorted. 

1. **Already Sorted**: If the array has no inversions, it is already sorted, so we output `YES`.
2. **Single Swap Strategy**: If there is at least one inversion, the only way to fix the array (if possible) is to swap the *first* pair that violates the non-decreasing order. If swapping this specific pair results in a fully sorted array, the condition is satisfied.
3. **Verification**: After performing the swap at the first detected inversion point, we perform a linear scan to verify if the entire array is now sorted. If it is, the answer is `YES`; otherwise, it is `NO`.

This greedy approach works because if there were multiple disjoint inversions, a single swap would not be sufficient to fix all of them.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the array. We perform one pass to find the inversion and one pass to verify the sorted order.
- **Space Complexity**: $O(N)$ to store the array elements.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is pseudo-sorted if it is already sorted or can be sorted by 
 * swapping exactly one adjacent pair (A[i], A[i+1]).
 * 
 * Strategy:
 * 1. Find the first index 'i' where A[i] > A[i+1].
 * 2. If no such index exists, the array is already sorted -> YES.
 * 3. If such an index exists, perform the swap A[i] and A[i+1].
 * 4. After the swap, check if the array is sorted.
 * 5. If it is sorted, output YES, otherwise output NO.
 */

bool isSorted(const vector<long long>& a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Find the first inversion
    int first_inversion = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            first_inversion = i;
            break;
        }
    }

    // If no inversion, it's already sorted
    if (first_inversion == -1) {
        cout << "YES" << "\n";
        return;
    }

    // Perform the swap at the first inversion point
    swap(a[first_inversion], a[first_inversion + 1]);

    // Check if the array is now sorted
    if (isSorted(a, n)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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