# [A - Books (BIT2A)](https://www.codechef.com/problems/BIT2A)

- **Difficulty Rating**: 1175
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a sorted array $A$ of $N$ integers, for each element $A[i]$, we need to determine how many elements in the array are strictly greater than $A[i]$.

## Intuition & Mathematical Observation
Since the input array is already sorted in non-decreasing order, all elements strictly greater than $A[i]$ must appear after the last occurrence of the value $A[i]$. 

Instead of manually tracking the last occurrence, we can leverage the standard library function `std::upper_bound`. For a given value $A[i]$, `upper_bound` returns an iterator to the first element in the array that is strictly greater than $A[i]$. The number of elements from this iterator to the end of the array represents exactly the count of elements strictly greater than $A[i]$.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the size of the array. For each of the $N$ elements, we perform a binary search (`upper_bound`) which takes $O(\log N)$ time. Given $N \le 100$, this is highly efficient.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sorted list A of size N.
 * For each A[i], we need to find the count of elements strictly greater than A[i].
 * Since the array is sorted, all elements strictly greater than A[i] will appear 
 * after the last occurrence of A[i].
 * 
 * Algorithm:
 * 1. For each test case, read N and the array A.
 * 2. For each A[i], use upper_bound to find the first element strictly greater than A[i].
 * 3. The number of elements strictly greater is (A.end() - upper_bound(A.begin(), A.end(), A[i])).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        // upper_bound returns an iterator to the first element > A[i]
        auto it = upper_bound(A.begin(), A.end(), A[i]);
        // The number of elements strictly greater is the distance from it to the end
        int count = distance(it, A.end());
        cout << count << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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